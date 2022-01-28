#include <iostream>
#include <math.h>

#include "resRotTensors.h"

// -------------------------------------------------------------------------------- //
//  Test code with the example of use of drag and torque 
//  model library for superellipsoidal particles, for the prediction
//  of translation, rotation and resistance tensor coefficients
// -------------------------------------------------------------------------------- //

int main() {


// validation on triaxial ellipsoid
	//double l1 = 5.0;
	//double l2 = 3.0;
	//double e1 = 1.0;
	//double e2 = 1.0; 

// validaiton on pollen se
	double l1 = 1.959;
	double l2 = 1.827;
	double e1 = 0.564;
	double e2 = 0.472;

	double Kxx = getKxx( l1, l2, e1, e2 );
	double Kyy = getKyy( l1, l2, e1, e2 );
	double Kzz = getKzz( l1, l2, e1, e2 );

	double Omegaxx = getOmegaxx( l1, l2, e1, e2 );
	double Omegayy = getOmegayy( l1, l2, e1, e2 );
	double Omegazz = getOmegazz( l1, l2, e1, e2 );

	double PIxx = getPIxx( l1, l2, e1, e2 );
	double PIyy = getPIyy( l1, l2, e1, e2 );
	double PIzz = getPIzz( l1, l2, e1, e2 );

	std::cout << "K     =" << Kxx << "  " << Kyy << "  " << Kzz << "\n";
	std::cout << "Omega =" << Omegaxx << "  " << Omegayy << "  " << Omegazz << "\n";
	std::cout << "PI    =" << PIxx << "  " << PIyy << "  " << PIzz << "\n";

	return 0;


}