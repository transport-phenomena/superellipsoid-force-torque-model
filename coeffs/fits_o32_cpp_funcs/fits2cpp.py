import os
import sys
import numpy as np
import math

sys.path.insert(0,"../../../superStlJun21/")
import src.funcs as fc
import src.forcesMoments as fm 


rfitFolders = [ "../../fits_order32/fits_1214_o32/",
                "../../fits_order32/fits_5345_o32/"  ]



def main():
    
    #convertEq( rfitFolders[0], rfitFolders[1], "Kxx_coeffs_A.dat" ) 
    #convertEq( rfitFolders[0], rfitFolders[1], "Kyy_coeffs_A.dat" ) 
    #convertEq( rfitFolders[0], rfitFolders[1], "Kzz_coeffs_A.dat" )  
    
    #convertEq( rfitFolders[0], rfitFolders[1], "Omegaxx_coeffs_A.dat" )  
    #convertEq( rfitFolders[0], rfitFolders[1], "Omegayy_coeffs_A.dat" ) 
    #convertEq( rfitFolders[0], rfitFolders[1], "Omegazz_coeffs_A.dat" ) 
    
    #convertEq( rfitFolders[0], rfitFolders[1], "PIxx_coeffs_A.dat" )
    #convertEq( rfitFolders[0], rfitFolders[1], "PIyy_coeffs_A.dat" )
    convertEq( rfitFolders[0], rfitFolders[1], "PIzz_coeffs_A.dat" )


def convertEq( fold1, fold2, tensorname ):
    
    print("--------------------------")
    print( tensorname + "::" )
    print("--------------------------")
    
# -------------------------------------------------- #
#   Read 1st segment
# -------------------------------------------------- #

    eq, coeffs, sc = 0,0,0

    fname = fold1 + tensorname
    eq, coeffs, sc = fm.readFits(fname)

# -------------------------------------------------- #
#   Covert coefficients for 1st segment
# -------------------------------------------------- #
    
    m = len(coeffs[0])
    n = len(coeffs)
    
    amat = f"double A1[{n}][{m}] = " + "{\n"

    for j in range(len(coeffs)):
        row = coeffs[j]

        arow = "\t{ "
        for i in range(len(row)):
            r = row[i]
            if i < len(row)-1:
                arow += f"{r:.8f}, "
            else:
                if j < len(coeffs)-1:
                    arow += f"{r:.8f}" + " },"
                else:
                    arow += f"{r:.8f}" + " }"
                     
        amat += arow +"\n"

    amat += "};"
    
    print("// Matrix of coefficients for 1st fit ( 1 >= lambda1 => 5 )")
    print(amat)
    
    
# -------------------------------------------------- #
#   Read 2nd segment
# -------------------------------------------------- #
    
    eq2, coeffs2, sc2 = 0,0,0
    fname = fold2 + tensorname
    eq2, coeffs2, sc2 = fm.readFits(fname)

# -------------------------------------------------- #
#   Covert coefficients for 2nd segment
# -------------------------------------------------- #
    
    m = len(coeffs2[0])
    n = len(coeffs2)
    
    amat = f"double A2[{n}][{m}] = " + "{\n"

    for j in range(len(coeffs2)):
        row = coeffs2[j]

        arow = "\t{ "
        for i in range(len(row)):
            r = row[i]
            if i < len(row)-1:
                arow += f"{r:.8f}, "
            else:
                if j < len(coeffs2)-1:
                    arow += f"{r:.8f}" + " },"
                else:
                    arow += f"{r:.8f}" + " }"
                     
        amat += arow +"\n"

    amat += "};"
    
    print("// Matrix of coefficients for 2nd fit ( 5 > lambda1 => 11)")
    print(amat)
    print("// End matrix of coefficients")
    
    
# -------------------------------------------------- #
#   Convert equation
# -------------------------------------------------- #
    #eq = eq.replace ( ", ", "][")
            
    eq = eq.replace( "x1**2", "pow(x1,2)" )
    eq = eq.replace( "x1**3", "pow(x1,3)" )

    eq = eq.replace( "x2**2", "pow(x2,2)" )
    eq = eq.replace( "x2**3", "pow(x2,3)" )

    eq = eq.replace( "x3**2", "pow(x3,2)" )

    eq = eq.replace( "x4**2", "pow(x4,2)" )
    
    eq = eq.split(" + ")
    
    eq2 = []
    for e in eq:
        
        try:
            a = e.split("]*")[0].split("[")[1]
            a = a.split(",")
            
            m = int(a[0])
            n = int(a[1])
            
            e1 = e.split("*",1)[1]
            e1 = f"A[{m}][{n}]*" + e1
        except:
            e1 = "A[0][0]"

        eq2.append(e1)

    eq = eq2

    #total number of characters 
    tc = 0
    enew = "double Q =\t"
    
    for i in range(len(eq)):
        
        e = eq[i]
        
        if i != len(eq)-1:
            enew += e + " + "
        else:
            enew += e + ";"
            
        tc += len(e)
        
        if tc > 60:
            enew += "\n\t\t"
            tc = 0

    #print(enew)

#
#   MAIN
#
if __name__== "__main__":
    main()




