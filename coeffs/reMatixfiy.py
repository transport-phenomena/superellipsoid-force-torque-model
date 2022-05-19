import sys
import numpy as np
import math

#sys.path.insert(0,"../../superStlJun21/")
#import src.forcesMoments as fm 


# 2nd order
#rfitFolder = "fits_0-5345_o22"
#rfitFolder = "fits_1214_o22"
#rfitFolder = "fits_5345_o22"

# 3rd order
rfitFolder = "fits_1214_o32"
#rfitFolder = "fits_5345_o32"


datfiles = [
        "Kxx_coeffs.dat",
        "Kyy_coeffs.dat",
        "Kzz_coeffs.dat",
        "Omegaxx_coeffs.dat",
        "Omegayy_coeffs.dat",
        "Omegazz_coeffs.dat",
        "PIxx_coeffs.dat",
        "PIyy_coeffs.dat",
        "PIzz_coeffs.dat"    
]

def main():
    
    #
    #   Run rematrixfiy on all dat files
    #
    
    for dfile in datfiles:
        
    
        fname = rfitFolder + "/" + dfile
        eq, coeffs, sc, errs = readFits(fname)
        runReMatrixfix( fname,eq,coeffs,sc,errs )


def runReMatrixfix( fname,eq,coeffs,sc,errs ):

    coeffs = np.array(coeffs)

    cmax = np.max( abs(coeffs) )
    
    #escale = cmax / 100.0  #So that the highest value in coeffs is 100
    rescale = 1.0 / sc

    for i in range(len(coeffs)):
        
        coeffs[i] = coeffs[i] / rescale
        
    sc = sc * rescale
    
    print(cmax)
    
    
    eqTerms = eq.split("+")
    eqTerms = [ eqTerms[i].strip() for i in range(len(eqTerms)) ]
    
    #for i in range(5):
        #print( eqTerms[i] ) 
        
        
    #
    #   read rematirxfiy fits
    #
    fname2=""
    if len(eqTerms) == 81:
        fname2 = "../../polyNotations/fMatrix_order22.txt"
    elif len(eqTerms) == 144:
        fname2 = "../../polyNotations/fMatrix_order32.txt"
    
    eq2 = readFits2(fname2)
    
    eq2Terms = eq2.split("+")
    eq2Terms = [ eq2Terms[i].strip() for i in range(len(eq2Terms)) ]
    
    #for i in range(5):
        #print( eq2Terms[i] ) 
    
    
    #
    #   Init A matrix
    #

    if len(eqTerms) == 81:
        isize,jsize = 9,9
    elif len(eqTerms) == 144:
        isize,jsize = 16,9
    else:
        print("Unknown fit dimension, check, stopping")
        sys.exit(1)
        
    A = np.zeros((isize,jsize))
    #
    #   Check if fit terms match
    #
    
    for i in range(len(eqTerms)):
        
        et1 = eqTerms[i]
        et2 = eq2Terms[i]
        
        if i < len(eqTerms)-1:
       
            Astr = et2.split("*",1)[0].strip()
            
            # split on first '*'
            et1 = et1.split("*",1)[1].strip()
            et2 = et2.split("*",1)[1].strip()
            
            if not et1 == et2:
            
                print(f"At i={i} terms do not match !!!!!!!!!!!!!!! ")
                print("Stopping, check whats going on !!!")
                sys.exit(1)
                
        else:
            Astr = et2.strip()
            
        Astr = Astr.split("[",1)[1]
        Astr = Astr.split("]",1)[0]
        
        ival = int( Astr.split(",")[0].strip() )
        jval = int(  Astr.split(",")[1].strip() )

        A[ival,jval] = coeffs[i]
        
        #print(Astr)
        #print(et1,"--",et2)
 
    print(A) 
    
    
    #
    #   Write out new file
    #
    newfname = fname.rsplit(".",1)[0] + "_A.dat"
    print()
    print(f"Saving new file to: {newfname}")

    f = open( newfname, "w" )
    
    f.write("Equation:\n")
    
    for i in range(len(eq2Terms)):

        if i < len(eq2Terms)-1:
            f.write( eq2Terms[i] + " + " )
        else:
            f.write( eq2Terms[i] )
        
        if math.modf( i/4 )[0] == 0.0:
            f.write("\n")
        
    f.write("\n")
    
    f.write("End\n")
    
    f.write("Coeffs:\n")
    
    for i in range(isize):
        for j in range(jsize):
            f.write( f"A[{i},{j}]={A[i,j]:.12f}\n" )
    
    f.write("End\n")
    
    f.write("\n")
    f.write(f"divscale={sc:.4f}\n")
    f.write("\n")
    
    f.write(f"avg.err={errs[0]:.6e}\n")
    f.write(f"max.err={errs[1]:.6e}\n")
    
    f.write("\n")
    f.write("########################################\n")
    f.write("Writing simplified A matrix in Latex:\n")
    f.write("########################################\n")
    f.write("\n")
    
    

    f.write( "\\begin{equation}\n")
            
    f.write( "\t\hat{A}=\n" )
    f.write( "\t\left(\\begin{array}{ccccccccc}\n" )
    for i in range(isize):
        f.write( f"\t\t{wNum(A[i,0])} & {wNum(A[i,1])} & {wNum(A[i,2])} & {wNum(A[i,3])} & {wNum(A[i,4])} & " )
        f.write( f"{wNum(A[i,5])} & {wNum(A[i,6])} & {wNum(A[i,7])} & {wNum(A[i,8])} \\\ \n" )
    f.write( "\t\end{array}\n" )
    f.write( "\t\\right)\n" )
    f.write( "\end{equation}\n" )
    
    #for i in range(isize):
    #    for j in range(jsize):
    #        f.write( f"A[{i},{j}]={A[i,j])}\n" )
    
    
    f.write("\n")
    f.write("\n")
    f.close()
    
    

        


# --------------------------------------------------- #
#   FUNCS
# --------------------------------------------------- #






def readFits2(fname):
    
    f = open(fname, "r")
    lines = f.readlines()

    eq = ""
    start = False

    #
    #   Read equation
    #
    for l in lines:

        if "End" in l:
            start = False

        if start:
            eq += l.strip("\n")

        if "Equation:" in l:
            start = True

    return eq


def readFits(fname):

    f = open(fname, "r")
    lines = f.readlines()

    eq = ""
    start = False

    #
    #   Read equation
    #
    for l in lines:

        if "End" in l:
            start = False

        if start:
            eq += l.strip("\n")

        if "Equation:" in l:
            start = True

    #
    #   Read coeffs
    #
    coeffs = []
    a = []  # [ 0 for i in range(500) ]
    for l in lines:

        if "End" in l:
            start = False

        if start and "a" in l:
            l = l.strip("\n")
            l = l.split("=")[1]
            a.append(float(l))

        if "Coeffs:" in l:
            start = True

    # print("Eq:\n")
    # print(eq)

    for l in lines:

        if "divscale" in l:
            l = l.split("=")[1]
            dscl = float(l)
            break
    
    errs = [0,0]
    for l in lines:

        if "avg.err" in l:
            l = l.split("=")[1]
            errs[0] = float(l)
        elif "max.err" in l:
            l = l.split("=")[1]
            errs[1] = float(l)
            break

    return eq, a, dscl, errs


def wNum(x):
    
#    if abs(x) < 0.1:
#        xout = "{:.3e}".format(x)
#    elif abs(x) < 1:
#        xout = "{:.4f}".format(x)
#    elif abs(x) < 10:
#        xout = "{:.3f}".format(x)
#    elif abs(x) < 100:
#        xout = "{:.2f}".format(x)
#    elif abs(x) < 1000:
#        xout = "{:.1f}".format(x)
#    else:
#        xout = "{:.0f}".format(x)

    if abs(x) < 1.0e-04:
        return "{:.1f}".format(0.0)

    if abs(x) < 0.1:
        #xout = "{:.2e}".format(x)
        xout = "{:.4f}".format(x)
    elif abs(x) < 1:
        xout = "{:.4f}".format(x)
    elif abs(x) < 10:
        xout = "{:.3f}".format(x)
    elif abs(x) < 100:
        xout = "{:.2f}".format(x)
    elif abs(x) < 1000:
        xout = "{:.1f}".format(x)
    else:
        xout = "{:.0f}".format(x)
  
    return xout
    
    



#
#   Call main
#
if __name__ == '__main__':
    main()
