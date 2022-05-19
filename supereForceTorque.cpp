#include "supereForceTorque.h"

const double Tensors::eqQ( const double A[16][9], double x1, double x2, double x3, double x4 )
{
	const double Q =A[15][8]*pow(x1,3)*pow(x2,3)*pow(x3,2)*pow(x4,2) + A[15][7]*pow(x1,3)*pow(x2,3)*pow(x3,2)*x4 + 
                    A[15][6]*pow(x1,3)*pow(x2,3)*pow(x3,2) + A[15][5]*pow(x1,3)*pow(x2,3)*x3*pow(x4,2) + 
                    A[15][4]*pow(x1,3)*pow(x2,3)*x3*x4 + A[15][3]*pow(x1,3)*pow(x2,3)*x3 + 
                    A[15][2]*pow(x1,3)*pow(x2,3)*pow(x4,2) + A[15][1]*pow(x1,3)*pow(x2,3)*x4 + 
                    A[15][0]*pow(x1,3)*pow(x2,3) + A[14][8]*pow(x1,3)*pow(x2,2)*pow(x3,2)*pow(x4,2) + 
                    A[14][7]*pow(x1,3)*pow(x2,2)*pow(x3,2)*x4 + A[14][6]*pow(x1,3)*pow(x2,2)*pow(x3,2) + 
                    A[14][5]*pow(x1,3)*pow(x2,2)*x3*pow(x4,2) + A[14][4]*pow(x1,3)*pow(x2,2)*x3*x4 + 
                    A[14][3]*pow(x1,3)*pow(x2,2)*x3 + A[14][2]*pow(x1,3)*pow(x2,2)*pow(x4,2) + 
                    A[14][1]*pow(x1,3)*pow(x2,2)*x4 + A[14][0]*pow(x1,3)*pow(x2,2) + A[13][8]*pow(x1,3)*x2*pow(x3,2)*pow(x4,2) + 
                    A[13][7]*pow(x1,3)*x2*pow(x3,2)*x4 + A[13][6]*pow(x1,3)*x2*pow(x3,2) + 
                    A[13][5]*pow(x1,3)*x2*x3*pow(x4,2) + A[13][4]*pow(x1,3)*x2*x3*x4 + 
                    A[13][3]*pow(x1,3)*x2*x3 + A[13][2]*pow(x1,3)*x2*pow(x4,2) + A[13][1]*pow(x1,3)*x2*x4 + 
                    A[13][0]*pow(x1,3)*x2 + A[12][8]*pow(x1,3)*pow(x3,2)*pow(x4,2) + A[12][7]*pow(x1,3)*pow(x3,2)*x4 + 
                    A[12][6]*pow(x1,3)*pow(x3,2) + A[12][5]*pow(x1,3)*x3*pow(x4,2) + A[12][4]*pow(x1,3)*x3*x4 + 
                    A[12][3]*pow(x1,3)*x3 + A[12][2]*pow(x1,3)*pow(x4,2) + A[12][1]*pow(x1,3)*x4 + 
                    A[12][0]*pow(x1,3) + A[11][8]*pow(x1,2)*pow(x2,3)*pow(x3,2)*pow(x4,2) + 
                    A[11][7]*pow(x1,2)*pow(x2,3)*pow(x3,2)*x4 + A[11][6]*pow(x1,2)*pow(x2,3)*pow(x3,2) + 
                    A[11][5]*pow(x1,2)*pow(x2,3)*x3*pow(x4,2) + A[11][4]*pow(x1,2)*pow(x2,3)*x3*x4 + 
                    A[11][3]*pow(x1,2)*pow(x2,3)*x3 + A[11][2]*pow(x1,2)*pow(x2,3)*pow(x4,2) + 
                    A[11][1]*pow(x1,2)*pow(x2,3)*x4 + A[11][0]*pow(x1,2)*pow(x2,3) + A[10][8]*pow(x1,2)*pow(x2,2)*pow(x3,2)*pow(x4,2) + 
                    A[10][7]*pow(x1,2)*pow(x2,2)*pow(x3,2)*x4 + A[10][6]*pow(x1,2)*pow(x2,2)*pow(x3,2) + 
                    A[10][5]*pow(x1,2)*pow(x2,2)*x3*pow(x4,2) + A[10][4]*pow(x1,2)*pow(x2,2)*x3*x4 + 
                    A[10][3]*pow(x1,2)*pow(x2,2)*x3 + A[10][2]*pow(x1,2)*pow(x2,2)*pow(x4,2) + 
                    A[10][1]*pow(x1,2)*pow(x2,2)*x4 + A[10][0]*pow(x1,2)*pow(x2,2) + A[9][8]*pow(x1,2)*x2*pow(x3,2)*pow(x4,2) + 
                    A[9][7]*pow(x1,2)*x2*pow(x3,2)*x4 + A[9][6]*pow(x1,2)*x2*pow(x3,2) + 
                    A[9][5]*pow(x1,2)*x2*x3*pow(x4,2) + A[9][4]*pow(x1,2)*x2*x3*x4 + A[9][3]*pow(x1,2)*x2*x3 + 
                    A[9][2]*pow(x1,2)*x2*pow(x4,2) + A[9][1]*pow(x1,2)*x2*x4 + A[9][0]*pow(x1,2)*x2 + 
                    A[8][8]*pow(x1,2)*pow(x3,2)*pow(x4,2) + A[8][7]*pow(x1,2)*pow(x3,2)*x4 + 
                    A[8][6]*pow(x1,2)*pow(x3,2) + A[8][5]*pow(x1,2)*x3*pow(x4,2) + A[8][4]*pow(x1,2)*x3*x4 + 
                    A[8][3]*pow(x1,2)*x3 + A[8][2]*pow(x1,2)*pow(x4,2) + A[8][1]*pow(x1,2)*x4 + 
                    A[8][0]*pow(x1,2) + A[7][8]*x1*pow(x2,3)*pow(x3,2)*pow(x4,2) + A[7][7]*x1*pow(x2,3)*pow(x3,2)*x4 + 
                    A[7][6]*x1*pow(x2,3)*pow(x3,2) + A[7][5]*x1*pow(x2,3)*x3*pow(x4,2) + 
                    A[7][4]*x1*pow(x2,3)*x3*x4 + A[7][3]*x1*pow(x2,3)*x3 + A[7][2]*x1*pow(x2,3)*pow(x4,2) + 
                    A[7][1]*x1*pow(x2,3)*x4 + A[7][0]*x1*pow(x2,3) + A[6][8]*x1*pow(x2,2)*pow(x3,2)*pow(x4,2) + 
                    A[6][7]*x1*pow(x2,2)*pow(x3,2)*x4 + A[6][6]*x1*pow(x2,2)*pow(x3,2) + 
                    A[6][5]*x1*pow(x2,2)*x3*pow(x4,2) + A[6][4]*x1*pow(x2,2)*x3*x4 + A[6][3]*x1*pow(x2,2)*x3 + 
                    A[6][2]*x1*pow(x2,2)*pow(x4,2) + A[6][1]*x1*pow(x2,2)*x4 + A[6][0]*x1*pow(x2,2) + 
                    A[5][8]*x1*x2*pow(x3,2)*pow(x4,2) + A[5][7]*x1*x2*pow(x3,2)*x4 + A[5][6]*x1*x2*pow(x3,2) + 
                    A[5][5]*x1*x2*x3*pow(x4,2) + A[5][4]*x1*x2*x3*x4 + A[5][3]*x1*x2*x3 + 
                    A[5][2]*x1*x2*pow(x4,2) + A[5][1]*x1*x2*x4 + A[5][0]*x1*x2 + A[4][8]*x1*pow(x3,2)*pow(x4,2) + 
                    A[4][7]*x1*pow(x3,2)*x4 + A[4][6]*x1*pow(x3,2) + A[4][5]*x1*x3*pow(x4,2) + 
                    A[4][4]*x1*x3*x4 + A[4][3]*x1*x3 + A[4][2]*x1*pow(x4,2) + A[4][1]*x1*x4 + 
                    A[4][0]*x1 + A[3][8]*pow(x2,3)*pow(x3,2)*pow(x4,2) + A[3][7]*pow(x2,3)*pow(x3,2)*x4 + 
                    A[3][6]*pow(x2,3)*pow(x3,2) + A[3][5]*pow(x2,3)*x3*pow(x4,2) + A[3][4]*pow(x2,3)*x3*x4 + 
                    A[3][3]*pow(x2,3)*x3 + A[3][2]*pow(x2,3)*pow(x4,2) + A[3][1]*pow(x2,3)*x4 + 
                    A[3][0]*pow(x2,3) + A[2][8]*pow(x2,2)*pow(x3,2)*pow(x4,2) + A[2][7]*pow(x2,2)*pow(x3,2)*x4 + 
                    A[2][6]*pow(x2,2)*pow(x3,2) + A[2][5]*pow(x2,2)*x3*pow(x4,2) + A[2][4]*pow(x2,2)*x3*x4 + 
                    A[2][3]*pow(x2,2)*x3 + A[2][2]*pow(x2,2)*pow(x4,2) + A[2][1]*pow(x2,2)*x4 + 
                    A[2][0]*pow(x2,2) + A[1][8]*x2*pow(x3,2)*pow(x4,2) + A[1][7]*x2*pow(x3,2)*x4 + 
                    A[1][6]*x2*pow(x3,2) + A[1][5]*x2*x3*pow(x4,2) + A[1][4]*x2*x3*x4 + A[1][3]*x2*x3 + 
                    A[1][2]*x2*pow(x4,2) + A[1][1]*x2*x4 + A[1][0]*x2 + A[0][8]*pow(x3,2)*pow(x4,2) + 
                    A[0][7]*pow(x3,2)*x4 + A[0][6]*pow(x3,2) + A[0][5]*x3*pow(x4,2) + A[0][4]*x3*x4 + 
                    A[0][3]*x3 + A[0][2]*pow(x4,2) + A[0][1]*x4 + A[0][0];

		return Q;

}

const int Tensors::getRange( double lam1, double lam2, double e1, double e2 )
{
    int rangeId = -1;

    if ( lam2 > lam1 ) 
	{
		std::cout << "!!! Error, lam2 > lam1, this is not allowed !!!\n" ;
        std::cout << "!!! All values will be set to 0.0           !!!\n" ;
        return rangeId;
	}

    if ( lam1 < 0.2 || lam1 > 11.0 || e1 < 0.2 || e1 > 1.8 || e2 < 0.2 || e2 > 1.8 )
	{
		std::cout << "!!! Warning parameter outside range. Ensure that the parameters are within: !!!\n";
        std::cout << "!!! lambda1 = [0.2,11], lambda2 < lambda1, e1 = [0.2,1.8], e2 = [0.2,1.8]   !!!\n";
        std::cout << "!!! Code will run, but it will return unverified results.                   !!!\n";

        if (lam1 < 0.2) rangeId = 0;
        if (lam1 > 11.0) rangeId = 2;

	}
    else if ( lam1 >= 0.2 && lam1 < 1.0 )
	{
		rangeId = 0;
	}

	else if ( lam1 >= 1.0 && lam1 <= 5.0 )
	{
		rangeId = 1;
	}

	else if ( lam1 > 5.0 && lam1 <= 11.0 )
	{
		rangeId = 2;
	}

	else
	{
		std::cout << "!!! Unexpected error                        !!!\n";
        std::cout << "!!! All values will be set to 0.0           !!!\n" ;
	}

	return rangeId;
}


void Tensors::calculateFor( Particle &Part )
{

    double lam1 = Part.l1;
    double lam2 = Part.l2;
    double e1 = Part.e1;
    double e2 = Part.e2;


    if ( Tensors::getRange( lam1, lam2, e1, e2) == -1 )
    {
        setKxx( 0.0 );
        setKyy( 0.0 );
        setKzz( 0.0 );

        setOmegaxx( 0.0 );
        setOmegayy( 0.0 );
        setOmegazz( 0.0 );

        setPIxx( 0.0 );
        setPIyy( 0.0 );
        setPIzz( 0.0 );
    }

    else if ( Tensors::getRange( lam1, lam2, e1, e2) == 0 )
    {
        setKxx( eqQ( Kxx::A0, lam1, lam2, e1, e2 ) );
        setKyy( eqQ( Kyy::A0, lam1, lam2, e1, e2 ) );
        setKzz( eqQ( Kzz::A0, lam1, lam2, e1, e2 ) );

        setOmegaxx( eqQ( Omegaxx::A0, lam1, lam2, e1, e2 ) );
        setOmegayy( eqQ( Omegayy::A0, lam1, lam2, e1, e2 ) );
        setOmegazz( eqQ( Omegazz::A0, lam1, lam2, e1, e2 ) );

        setPIxx( eqQ( PIxx::A0, lam1, lam2, e1, e2 ) );
        setPIyy( eqQ( PIyy::A0, lam1, lam2, e1, e2 ) );
        setPIzz( eqQ( PIzz::A0, lam1, lam2, e1, e2 ) );
    } 

    else if ( Tensors::getRange( lam1, lam2, e1, e2) == 1 )
    {
        setKxx( eqQ( Kxx::A1, lam1, lam2, e1, e2 ) );
        setKyy( eqQ( Kyy::A1, lam1, lam2, e1, e2 ) );
        setKzz( eqQ( Kzz::A1, lam1, lam2, e1, e2 ) );

        setOmegaxx( eqQ( Omegaxx::A1, lam1, lam2, e1, e2 ) );
        setOmegayy( eqQ( Omegayy::A1, lam1, lam2, e1, e2 ) );
        setOmegazz( eqQ( Omegazz::A1, lam1, lam2, e1, e2 ) );

        setPIxx( eqQ( PIxx::A1, lam1, lam2, e1, e2 ) );
        setPIyy( eqQ( PIyy::A1, lam1, lam2, e1, e2 ) );
        setPIzz( eqQ( PIzz::A1, lam1, lam2, e1, e2 ) );
    } 

    else if ( Tensors::getRange( lam1, lam2, e1, e2) == 2 )
    {
        setKxx( eqQ( Kxx::A2, lam1, lam2, e1, e2 ) );
        setKyy( eqQ( Kyy::A2, lam1, lam2, e1, e2 ) );
        setKzz( eqQ( Kzz::A2, lam1, lam2, e1, e2 ) );

        setOmegaxx( eqQ( Omegaxx::A2, lam1, lam2, e1, e2 ) );
        setOmegayy( eqQ( Omegayy::A2, lam1, lam2, e1, e2 ) );
        setOmegazz( eqQ( Omegazz::A2, lam1, lam2, e1, e2 ) );

        setPIxx( eqQ( PIxx::A2, lam1, lam2, e1, e2 ) );
        setPIyy( eqQ( PIyy::A2, lam1, lam2, e1, e2 ) );
        setPIzz( eqQ( PIzz::A2, lam1, lam2, e1, e2 ) );
    }

}

void Tensors::calculateFor( double lam1, double lam2, double e1, double e2 )
{

    if ( Tensors::getRange( lam1, lam2, e1, e2) == 0 )
    {
        setKxx( eqQ( Kxx::A0, lam1, lam2, e1, e2 ) );
        setKyy( eqQ( Kyy::A0, lam1, lam2, e1, e2 ) );
        setKzz( eqQ( Kzz::A0, lam1, lam2, e1, e2 ) );

        setOmegaxx( eqQ( Omegaxx::A0, lam1, lam2, e1, e2 ) );
        setOmegayy( eqQ( Omegayy::A0, lam1, lam2, e1, e2 ) );
        setOmegazz( eqQ( Omegazz::A0, lam1, lam2, e1, e2 ) );

        setPIxx( eqQ( PIxx::A0, lam1, lam2, e1, e2 ) );
        setPIyy( eqQ( PIyy::A0, lam1, lam2, e1, e2 ) );
        setPIzz( eqQ( PIzz::A0, lam1, lam2, e1, e2 ) );
    } 

    else if ( Tensors::getRange( lam1, lam2, e1, e2) == 1 )
    {
        setKxx( eqQ( Kxx::A1, lam1, lam2, e1, e2 ) );
        setKyy( eqQ( Kyy::A1, lam1, lam2, e1, e2 ) );
        setKzz( eqQ( Kzz::A1, lam1, lam2, e1, e2 ) );

        setOmegaxx( eqQ( Omegaxx::A1, lam1, lam2, e1, e2 ) );
        setOmegayy( eqQ( Omegayy::A1, lam1, lam2, e1, e2 ) );
        setOmegazz( eqQ( Omegazz::A1, lam1, lam2, e1, e2 ) );

        setPIxx( eqQ( PIxx::A1, lam1, lam2, e1, e2 ) );
        setPIyy( eqQ( PIyy::A1, lam1, lam2, e1, e2 ) );
        setPIzz( eqQ( PIzz::A1, lam1, lam2, e1, e2 ) );
    } 

    else if ( Tensors::getRange( lam1, lam2, e1, e2) == 2 )
    {
        setKxx( eqQ( Kxx::A2, lam1, lam2, e1, e2 ) );
        setKyy( eqQ( Kyy::A2, lam1, lam2, e1, e2 ) );
        setKzz( eqQ( Kzz::A2, lam1, lam2, e1, e2 ) );

        setOmegaxx( eqQ( Omegaxx::A2, lam1, lam2, e1, e2 ) );
        setOmegayy( eqQ( Omegayy::A2, lam1, lam2, e1, e2 ) );
        setOmegazz( eqQ( Omegazz::A2, lam1, lam2, e1, e2 ) );

        setPIxx( eqQ( PIxx::A2, lam1, lam2, e1, e2 ) );
        setPIyy( eqQ( PIyy::A2, lam1, lam2, e1, e2 ) );
        setPIzz( eqQ( PIzz::A2, lam1, lam2, e1, e2 ) );
    }

}

void TensorComponents::setKxx( double val )
{
    _Kxx = val;
}

void TensorComponents::setKyy( double val )
{
    _Kyy = val;
}

void TensorComponents::setKzz( double val )
{
    _Kzz = val;
}

void TensorComponents::setOmegaxx( double val )
{
    _Omegaxx = val;
}

void TensorComponents::setOmegayy( double val )
{
    _Omegayy = val;
}

void TensorComponents::setOmegazz( double val )
{
    _Omegazz = val;
}

void TensorComponents::setPIxx( double val )
{
    _PIxx = val;
}

void TensorComponents::setPIyy( double val )
{
    _PIyy = val;
}

void TensorComponents::setPIzz( double val )
{
    _PIzz = val;
}

const double TensorComponents::Kxx()
{
    return _Kxx;
}

const double TensorComponents::Kyy()
{
    return _Kyy;
}

const double TensorComponents::Kzz()
{
    return _Kzz;
}

const double TensorComponents::Omegaxx()
{
    return _Omegaxx;
}

const double TensorComponents::Omegayy()
{
    return _Omegayy;
}

const double TensorComponents::Omegazz()
{
    return _Omegazz;
}

const double TensorComponents::PIxx()
{
    return _PIxx;
}

const double TensorComponents::PIyy()
{
    return _PIyy;
}

const double TensorComponents::PIzz()
{
    return _PIzz;
}



/*

void TensorComponent::setA0( double X[16][9] )
{
    for (int i=0; i<16; i++)
    {
        for(int j=0; j<9; j++)
        {
            _A0[i][j] = X[i][j];
        }
    }
}

void TensorComponent::setA1( double X[16][9] )
{
    for (int i=0; i<16; i++)
    {
        for(int j=0; j<9; j++)
        {
            _A1[i][j] = X[i][j];
        }
    }
}

void TensorComponent::setA2( double X[16][9] )
{
    for (int i=0; i<16; i++)
    {
        for(int j=0; j<9; j++)
        {
            _A2[i][j] = X[i][j];
        }
    }
}
*/
