#include <iostream>
#include <math.h>

#include "supereForceTorque.h"

// -------------------------------------------------------------------------------- //
//  Test code with the example of use of drag and torque 
//  model library for superellipsoidal particles, for the prediction
//  of translation, rotation and resistance tensor coefficients
// -------------------------------------------------------------------------------- //

// -------------------------------------------------------------------------------- //
// Particles from paper:
// -------------------------------------------------------------------------------- //
// Štrakl, M., Hriberšek, M., Wedel, J., Steinmann, P., Ravnik, J. (2022) 
// A Model for Translation and Rotation Resistance Tensors for Superellipsoidal
// Particles in Stokes Flow. J. Mar. Sci. Eng. 2022, 10, 369. 
// doi:10.3390/jmse10030369
// -------------------------------------------------------------------------------- //
// Tables 2,3,4
Particle Sphere( "Sphere.I", 1.0, 1.0, 1.0, 1.0 );
Particle Prolate( "Prolate.II", 5.0, 1.0, 1.0, 1.0 );
Particle Triaxial( "Triaxial.III", 5.0, 3.0, 1.0, 1.0 );
Particle Rectangular( "Rectangual.IV", 5.0, 5.0, 0.2, 0.2 );
Particle Pyramid( "Pyramid.V", 10.0, 10.0, 1.5, 1.5 );

// Table 5
Particle Pollen( "Pollen", 1.96, 1.83, 0.564, 0.472 );



// -------------------------------------------------------------------------------- //
// Aditional cylinder particles (lambda < 1)
// -------------------------------------------------------------------------------- //
// - validation data provided in: valid_cylinder_particles.pdf
//
//
// -------------------------------------------------------------------------------- //

Particle Cylinder5( "Cylinder5", 0.2, 0.2, 0.2, 1 );
Particle Cylinder4( "Cylinder4", 0.25, 0.25, 0.2, 1 );
Particle Cylinder2_5( "Cylinder2.5", 0.4, 0.4, 0.2, 1 );
Particle Cylinder2( "Cylinder2", 0.5, 0.5, 0.2, 1 );
Particle Cylinder1_67( "Cylinder1.67", 0.6, 0.6, 0.2, 1 );
Particle Cylinder1( "Cylinder1", 1, 1, 0.2, 1 );

// Must throw warning for this one, data outside range
// - calculated by extrapolation
Particle Cylinder8( "Cylinder8", 0.125, 0.125, 0.2, 1 );

// -------------------------------------------------------------------------------- //
// Aditional prolate particles
// -------------------------------------------------------------------------------- //
// - validation data provided in: valid_cylinder_particles.pdf
// - 2 equal prolates, one elongated in X and another in Z
// - to compare forces and moments, obtained by tensor coefficients
// 	 from fit range R0 and fit range R1 (see: valid_cylinder_particles.pdf)
//
// -------------------------------------------------------------------------------- //
Particle Prolate0_2( "Prolate0.2", 0.2, 0.2, 1, 1 );
Particle Prolate5( "Prolate5", 5, 1, 1, 1 );



void printTensors( Tensors &Tens, Particle &Part );

int main() {

// ------------------------------------- //
// 	Example of use
// ------------------------------------- //

	Tensors KOmPi;

	// 	Calculate tensor components for particle:
	//	-option 1: calculate with particle parameters

	// calculateFor( lambda1, lambda2, e1, e2 )
	KOmPi.calculateFor( 5.0, 1.0, 1.0, 1.0 );
	
	//	-option 2: calculate with Particle class
	//  <Class Particle> <Object Name>( "partilce name", lambda1, lambda2, e1, e2 )
	Particle TestPart( "TestPart", 5.0, 1.0, 1.0, 1.0 );

	// calculateFor( Particle class object )
	KOmPi.calculateFor( TestPart );

	// 	Get tensor components:
	// 	-for example component Kyy
	double myKyy = KOmPi.Kyy();


	// --------------------------------------------
	// Printout for validation
	// --------------------------------------------

	// Functions for simplified printouts
	printTensors( KOmPi, Sphere );
	printTensors( KOmPi, Prolate );
	printTensors( KOmPi, Triaxial );
	printTensors( KOmPi, Rectangular );
	printTensors( KOmPi, Pyramid );

	printTensors( KOmPi, Pollen );

	printTensors( KOmPi, Cylinder5 );
	printTensors( KOmPi, Cylinder4 );
	printTensors( KOmPi, Cylinder2_5 );
	printTensors( KOmPi, Cylinder2 );
	printTensors( KOmPi, Cylinder1_67 );
	printTensors( KOmPi, Cylinder1 );
	printTensors( KOmPi, Cylinder8 );

	printTensors( KOmPi, Prolate0_2 );
	printTensors( KOmPi, Prolate5 );

	// --------------------------------------------

	return 0;


}

void printTensors( Tensors &Tens, Particle &Part )
{
	Tens.calculateFor( Part );
	std::cout << "--------------------------------------------------" << "\n";
	std::cout << "Tensors for particle " << Part.name << "\n";
	std::cout << "--------------------------------------------------" << "\n";
	std::cout << "K     =" << Tens.Kxx() << "  " << Tens.Kyy() << "  " << Tens.Kzz() << "\n";
	std::cout << "Omega =" << Tens.Omegaxx() << "  " << Tens.Omegayy() << "  " << Tens.Omegazz() << "\n";
	std::cout << "PI    =" << Tens.PIxx() << "  " << Tens.PIyy() << "  " << Tens.PIzz() << "\n";
	std::cout << "--------------------------------------------------" << "\n";
	std::cout << "\n";		
}