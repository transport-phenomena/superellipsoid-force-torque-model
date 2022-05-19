#ifndef SUPEREFORCETORQUE_H
#define SUPEREFORCETORQUE_H

#include <iostream>
#include <math.h>

#include "coeffsK.h"
#include "coeffsOmega.h"
#include "coeffsPI.h"

class TensorComponents
{
    private:
        double _Kxx, _Kyy, _Kzz;
        double _Omegaxx, _Omegayy, _Omegazz;
        double _PIxx, _PIyy, _PIzz;
    
    public:
        void setKxx( double val );
        void setKyy( double val );
        void setKzz( double val );

        void setOmegaxx( double val );
        void setOmegayy( double val );
        void setOmegazz( double val );

        void setPIxx( double val );
        void setPIyy( double val );
        void setPIzz( double val );

        const double Kxx();
        const double Kyy();
        const double Kzz();

        const double Omegaxx();
        const double Omegayy();
        const double Omegazz();

        const double PIxx();
        const double PIyy();
        const double PIzz();

};

class Particle
{
	public:

		std::string name;
		double l1;
		double l2;
		double e1;
		double e2;

		Particle( std::string name_, double l1_, double l2_, double e1_, double e2_ )
		{
			name = name_;
			l1 = l1_;
			l2 = l2_;
			e1 = e1_;
			e2 = e2_;
		} 
};

class Tensors : public TensorComponents
{
    private:
        int rangeId;

    public:
        const int getRange( double lam1, double lam2, double e1, double e2 );
        void calculateFor( double lam1, double lam2, double e1, double e2 );
        void calculateFor( Particle &Part );
        const double eqQ( const double A[16][9], double x1, double x2, double x3, double x4 );

};


#endif