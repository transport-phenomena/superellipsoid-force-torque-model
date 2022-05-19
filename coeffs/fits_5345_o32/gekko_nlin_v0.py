import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt
import sys
#import pysindy as ps
from gekko import GEKKO


#-------------------------------------------------------------------------------------------#
#                                                                                           #
#      MAIN                                                                                 #
#                                                                                           #
#-------------------------------------------------------------------------------------------#

def main():

#
#    Basic input
#

    #fname = "results_se0-524.csv"
    #fname = "results_se0-5345_cleaned.csv"
    #fname = "corr_results_se0-1214.csv" # -  Extracted particles with lambda1 = 1-6, corrected for minuses
    fname = "corr_results_se1215-5345.csv" # -  Extracted particles with lambda1 = 6-11, corrected for minuses
    #yvar = "PIxx"

#
#   Fitting funcs
#

    f = [ "x1**3", "x1**2", "x1", "1" ]
    g = [ "x2**3", "x2**2", "x2", "1" ]
    #h = [ "x3**3", "x3**2", "x3", "1" ]
    #i = [ "x4**3", "x4**2", "x4", "1" ]

    #f = [ "x1**2", "x1", "1" ]
    #g = [ "x2**2", "x2", "1" ]
    h = [ "x3**2", "x3", "1" ]
    i = [ "x4**2", "x4", "1" ]

    #f = [ "x1", "1" ]
    #g = [ "x2", "1" ]
    #h = [ "1" ]
    #i = [ "1" ]

    runPolyFit( fname, "Kxx", f, g, h, i )
    runPolyFit( fname, "Kyy", f, g, h, i )
    runPolyFit( fname, "Kzz", f, g, h, i )

    runPolyFit( fname, "Omegaxx", f, g, h, i )
    runPolyFit( fname, "Omegayy", f, g, h, i )
    runPolyFit( fname, "Omegazz", f, g, h, i )
    
    runPolyFit( fname, "PIxx", f, g, h, i )
    runPolyFit( fname, "PIyy", f, g, h, i )
    runPolyFit( fname, "PIzz", f, g, h, i )

#-------------------------------------------------------------------------------------------#
#                                                                                           #
#   FUNCS                                                                                   #
#                                                                                           #
#-------------------------------------------------------------------------------------------#


def runPolyFit( fname, yvar, f, g, h, i ):

#
#   Config
#

    plot = True
    printCoeffs = False
    printStats = True
    outputCoeffs = True

    print("Running for: " + yvar )

#
#   Define parameter bounds
#

    lbound = -10
    ubound = 10

#
#   Factorize funcs
#

    eq,nparams = factorizeFuncs( f,g,h,i )
    #print("eq:")
    #print(eq)

#
#   Read CSV
#
    l1_,l2_,e1_,e2_,y_ = readCsv( fname, yvar )

#
#   Correct and normalize
#
    y_,divscale = correctNormalize(y_)

#
#   Extract partial 
#
    l1,l2,e1,e2,y = extractPartial( l1_,l2_,e1_,e2_,y_ )

#
#   Gekko
#
    xin_1 = l1
    xin_2 = l2 
    xin_3 = e1
    xin_4 = e2
    yin = y

    m = GEKKO()

    # Declare input params
    a=[]
    for i in range(nparams):
        a.append( m.FV(lb=lbound, ub=ubound) )

    # Set vars
    xm1 = np.array( xin_1 )
    xm2 = np.array( xin_2 )
    xm3 = np.array( xin_3 )
    xm4 = np.array( xin_4 )
    ym = np.array( yin )

    x1 = m.Param(value=xm1)
    x2 = m.Param(value=xm2)
    x3 = m.Param(value=xm3)
    x4 = m.Param(value=xm4)

    z = m.Param(value=ym)
    y = m.Var()

    m.Equation( y == eval(eq) )

    m.Minimize( ((y-z)/(z+1e-09))**2 )

    for i in range(nparams):
        a[i].STATUS = 1

    m.options.IMODE = 2
    m.options.SOLVER = 2

    # Solve
    #m.solve(  )
    m.solve( disp=False )

    for i in range(nparams):
        a[i] = a[i].value[0]

    if printCoeffs:

        for i in range(nparams):
            if a[i] != 0.0:
                print( "a[" + str(i) +"]=" + str(a[i])  )

#
#   Check results
#
    yraw, ypredarr, erravg, errmax = checkResults( yin, eq, a, xin_1, xin_2, xin_3, xin_4, printStats )

#
#   Write resutls to file.dat
#
    if outputCoeffs:

        fle = yvar + "_coeffs.dat"
        f = open( fle, "w+" )

        #Write equation
        weq = eq.split("+")
        weq = [x.replace(' ', '') for x in weq]

        #5 terms per row
        f.write("Equation:\n")
        s,k = "",0
        for w in weq:

            s += w + " + "
            if k == 4:
                #f.write( s+"\n" )
                s += "\n"
                k = 0
                #s,k = "",0

            k+=1
        
        s = s[:-3]
        f.write( s + "\n" )
        f.write("End\n")
        f.write("Coeffs:\n")

        #Write coeffs
        for i in range(nparams):

            s = "a[" + str(i) +"]=" + str(a[i]) + "\n"
            f.write( s )

        f.write("\n")
        f.write("End\n")
        f.write("\n")

        f.write( f"divscale={divscale}\n" )
        f.write("\n")

        #Write avg, max err
        f.write( f"avg.err={erravg}\n" )
        f.write( f"max.err={errmax}\n" )
        f.write("\n")

        f.close()

#
#   Plot data
#

    if plot:

        fig, ax = plt.subplots(1, 1, figsize=(6, 6))

        #ax.plot(x_train[:, 0], x_train[:, 1], '-', label='true')
        #ax.plot(sim[:, 0], sim[:, 1], '--', label='SINDy')

        ax.plot(yraw, '-', label='true')
        ax.plot(ypredarr, '--', label='GEKKO')

        ax.set(xlabel='x', ylabel='y', title='Measuremet data')

        ax.grid()
        ax.legend()

        #plt.show()



def correctNormalize(u):

    u = np.array(u)
    maxu = np.max( 1*abs(u) )
    for i in range(len(u)):
        u[i] = u[i] / maxu
        u[i] = u[i] + 0

    #maxu = 1

    return u, maxu


def checkResults( yin, eq, a, xin_1, xin_2, xin_3, xin_4, printStats ):

    yraw = yin

    yerr = []
    avg,rms = 0,0
    k=0

    ypredarr = []

    for i in range(len(xin_1)):

        x1 = xin_1[i]
        x2 = xin_2[i]
        x3 = xin_3[i]
        x4 = xin_4[i]

        ypred = eval(eq)

        ypredarr.append(ypred)

        delta = abs( ypred - yraw[i] ) / abs( yraw[i]+1e-09 )
        yerr.append( delta )

        #Prints for debug
        #print( ypred, yraw[i] )

        avg += delta
        rms += ( ypred-yraw[i] )**2

        #print( "l=",x1,x2," y=",ypred,yraw[i],delta )

        pstr = str(x1)+"," + str(x2)+"," + str(yraw[i])+","
        pstr += str(ypred)+"," + str(delta)
        #print( pstr )

        k += 1

#    x1,x2,x3,x4 = 1,1,1,1
#    print(f"sphere={eval(eq)}, true={yraw[12]}")
#    x1,x2,x3,x4 = 2,1,1,1
#    print(f"ell211={eval(eq)}")
#    x1,x2,x3,x4 = 5,1,1,1
#    print(f"ell511={eval(eq)}, true={yraw[87]}")
#    x1,x2,x3,x4 = 5,3,1,1
#    print(f"ell531={eval(eq)}, true={yraw[112]}")
#    x1,x2,x3,x4 = 5,3,0.2,1.5
#    print(f"supere={eval(eq)}, true={yraw[103]}")

    rms = (rms / k)**0.5
    avg = avg / k

    if printStats:
        print("rms, "+str(rms))
        print("avg, "+str(avg))
        print("max, "+str(max(yerr)))

    return yraw, ypredarr, avg, max(yerr)


def readCsv(fname,yvar):

    import pandas as pd
    df = pd.read_csv(fname)
    df.rename(columns=lambda x: x.strip(), inplace=True)

    l1 = np.array( df["lam1"] )
    l2 = np.array( df["lam2"] )
    e1 = np.array( df["e1"] )
    e2 = np.array( df["e2"] )

    #y = np.array( abs(df[yvar]) )
    y = np.array( df[yvar] )

    return l1,l2,e1,e2,y  

def extractPartial(l1,l2,e1,e2,y):

    l1_, l2_, e1_, e2_, y_ = [],[],[],[],[]

    for i in range(len(l1)):

        #if e1[i] == 1 and e2[i] == 1:
        #if e1[i] == 1:
        #if e2[i] == 1:
        if True:

            l1_.append( l1[i] )
            l2_.append( l2[i] )
            e1_.append( e1[i] )
            e2_.append( e2[i] )
            y_.append( y[i] )
        
    return l1_, l2_, e1_, e2_, y_

def factorizeFuncs(fun_f, fun_g, fun_h, fun_i):

    def check(f):

        if f != "1":
            f = f + "*"
        else:
            f = ""

        return f

    def checkLast(f):

        if f != "1":
            f = f
        else:
            f = ""

        return f

    s=""
    k=0
    for f in fun_f:
        for g in fun_g:
            for h in fun_h:
                for i in fun_i:

                    f_ = check(f)
                    g_ = check(g)
                    h_ = check(h)
                    i_ = checkLast(i)

                    s += "a[" + str(k) + "]*"
                    s += f_ + g_ + h_ + i_

                    if s[-1] == "*":
                        s = s[:-1]

                    s += " + "

                    k += 1
                
                #s += "\n"

    s = s[:-3]

    return s, k


#
#   Call main
#
if __name__ == '__main__':
    main()
