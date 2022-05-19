import numpy as np
import os
import sys

sys.path.append('../../superStlJun21/')

import src.forcesMoments as fm


var = "PI"

fnamesA0 = [
    "fits_smallLambda_o32/"+var+"xx_coeffs_A.dat",
    "fits_smallLambda_o32/"+var+"yy_coeffs_A.dat",
    "fits_smallLambda_o32/"+var+"zz_coeffs_A.dat",  
]

fnamesA1 = [
    "fits_1214_o32/"+var+"xx_coeffs_A.dat",
    "fits_1214_o32/"+var+"yy_coeffs_A.dat",
    "fits_1214_o32/"+var+"zz_coeffs_A.dat",  
]

fnamesA2 = [
    "fits_5345_o32/"+var+"xx_coeffs_A.dat",
    "fits_5345_o32/"+var+"yy_coeffs_A.dat",
    "fits_5345_o32/"+var+"zz_coeffs_A.dat",  
]

K_A0, K_A1, K_A2 = [], [], []

for i in range(3):
    
    eq, a0, sc = fm.readFits( fnamesA0[i] )
    eq, a1, sc = fm.readFits( fnamesA1[i] )
    eq, a2, sc = fm.readFits( fnamesA2[i] )
    
    K_A0.append( a0 )
    K_A1.append( a1 )
    K_A2.append( a2 )
    
    
def writeA( f, k, A, alabel, tensor ):
    
 
    if k == 0:
        first = "const double " + tensor + "xx" + "::" + alabel + "[16][9] = {"
    elif k == 1:
        first = "const double " + tensor + "yy" + "::" + alabel + "[16][9] = {"
    elif k ==2:
        first = "const double " + tensor + "zz" + "::" + alabel + "[16][9] = {"

    if alabel == "A0":
        comment = "// Range R0: ( 0.2 => lambda1 > 1 )"
    elif alabel == "A1":
        comment = "// Range R1: ( 1 => lambda1 => 5 )"
    elif alabel == "A2":
        comment = "// Range R2: ( 5 > lambda1 => 11 )"
        
    f.write( comment + "\n")
    
    f.write( first + "\n")
    for i in range(len(A)):

        st = "\t{ "
        for j in range(len(A[0])):
            
            st += str( round(A[i,j],12) ) + ", "

        if i < len(A)-1:
            st += " },\n"
        else:
            st += " }\n"
            
        f.write(st)
    
    f.write("};\n")
    f.write("\n")

def writeTensor( tensor, A0, A1, A2 ):

    fname = "coeffs" + tensor + ".cpp"
    f = open( fname, "w+" )
    
    f.write( "#ifndef COEFFS" + tensor.upper() + "_H" + "\n" )
    f.write( "#define COEFFS" + tensor.upper() + "_H" + "\n" )
    
    f.write( "\n" )
    
    for k in range(3):
        
        f.write("\n")
        
        if var == "K":
            if k == 0:
                header  = "// ---------------------------------------------------------- //" + "\n"
                header += "//  Coefficient matrices for Kxx                              //" + "\n"
                header += "// ---------------------------------------------------------- //" + "\n"
            elif k == 1:
                header  = "// ---------------------------------------------------------- //" + "\n"
                header += "//  Coefficient matrices for Kyy                              //" + "\n"
                header += "// ---------------------------------------------------------- //" + "\n"
            elif k == 2:
                header  = "// ---------------------------------------------------------- //" + "\n"
                header += "//  Coefficient matrices for Kzz                              //" + "\n"
                header += "// ---------------------------------------------------------- //" + "\n"
                
        elif var == "Omega":
            if k == 0:
                header  = "// ---------------------------------------------------------- //" + "\n"
                header += "//  Coefficient matrices for Omegaxx                          //" + "\n"
                header += "// ---------------------------------------------------------- //" + "\n"
            elif k == 1:
                header  = "// ---------------------------------------------------------- //" + "\n"
                header += "//  Coefficient matrices for Omegayy                          //" + "\n"
                header += "// ---------------------------------------------------------- //" + "\n"
            elif k == 2:
                header  = "// ---------------------------------------------------------- //" + "\n"
                header += "//  Coefficient matrices for Omegazz                          //" + "\n"
                header += "// ---------------------------------------------------------- //" + "\n"
                
        elif var == "PI":
            if k == 0:
                header  = "// ---------------------------------------------------------- //" + "\n"
                header += "//  Coefficient matrices for PIxx                             //" + "\n"
                header += "// ---------------------------------------------------------- //" + "\n"
            elif k == 1:
                header  = "// ---------------------------------------------------------- //" + "\n"
                header += "//  Coefficient matrices for PIyy                             //" + "\n"
                header += "// ---------------------------------------------------------- //" + "\n"
            elif k == 2:
                header  = "// ---------------------------------------------------------- //" + "\n"
                header += "//  Coefficient matrices for PIzz                             //" + "\n"
                header += "// ---------------------------------------------------------- //" + "\n"
            
        f.write( header + "\n\n")
        
        writeA( f, k, A0[k], "A0", tensor )
        writeA( f, k, A1[k], "A1", tensor )
        writeA( f, k, A2[k], "A2", tensor )

    f.write( "#endif" + "\n" )

writeTensor( var, K_A0, K_A1, K_A2 )