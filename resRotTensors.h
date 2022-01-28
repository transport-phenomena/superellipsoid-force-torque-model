#ifndef RESROTTENSORS_H
#define RESROTTENSORS_H

#include <iostream>
#include <math.h>


// -------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------- //
//
//     Description
//
//          Model library for the drag and the torque on superellipsoidal particles in 
//          the Stokes flow. The library provides the translation, rotation and resistance 
//          tensor coefficients that are implemented into the drag and torque equation (eqs. 13,14), 
//          as described in the paper cited below. 
//
//          Particles are modelled by 4 geometric parameters: 
//              lambda1, lambda2, e1, e2 (eqs. 11,12)
//
//          Validity of the model is for the following parameter range:
//              lambda1 = [1,11], lambda2 < lambda1, e1 = [0.2,1.8], e2 = [0.2,1.8]
//
//     Authors
//
//          Mitja Štrakl(1), Matjaž Hriberšek(1), Jana Wedel(2), Paul Steinmann(2,3), Jure Ravnik(1)
//
//          (1) Faculty of Mechanical Engineering, 
//              University of Maribor, Smetanova 17, 
//              SI-2000, Maribor, Slovenia
//
//          (2) Institute of Applied Mechanics, 
//              Friedrich-Alexander Universität Erlangen-Nürnberg, 
//              Paul-Gordan-Str. 3, 
//              D-91052 Erlangen,Germany
//
//          (3) Glasgow Computational Engineering Centre, 
//              University of Glasgow, 
//              Glasgow, UK
//
//     Web
//
//          http://iepoi.fs.um.si/en
//          https://www.ltm.tf.fau.eu/
//
//     Licence
//
//          This software may be freely used provided that any results, that were obtained by the
//          use of this software or parts of it, cite the following paper:
//
//          Mitja Štrakl, Matjaž Hriberšek, Jana Wedel, Paul Sterinamnn, Jure Ravnik: A model for translation 
//          and rotation resistance tensors for superellipsoidal particles in Stokes flow. 
//          To appear in 2022/2023.
//
// -------------------------------------------------------------------------------- //
// -------------------------------------------------------------------------------- //

// Basic equation for all K,Omega,Pi functions
double eqQ( double A[16][9], double x1, double x2, double x3, double x4 );

// Functions to return K components
double getKxx( double lam1, double lam2, double e1, double e2 );
double getKyy( double lam1, double lam2, double e1, double e2 );
double getKzz( double lam1, double lam2, double e1, double e2 );

// Functions to return Omega components
double getOmegaxx( double lam1, double lam2, double e1, double e2 );
double getOmegayy( double lam1, double lam2, double e1, double e2 );
double getOmegazz( double lam1, double lam2, double e1, double e2 );

// Functions to return PI components
double getPIxx( double lam1, double lam2, double e1, double e2 );
double getPIyy( double lam1, double lam2, double e1, double e2 );
double getPIzz( double lam1, double lam2, double e1, double e2 );

#endif