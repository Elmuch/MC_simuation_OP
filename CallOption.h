
//pricers
//meshers
//greeks
//Exact solutions
///////////////////////////////////////


#include "EuropeanOption.h"
#include "PutOption.h"
#ifndef CALLOPTION_H
#define CALLOPTION_H


class CallOption
{
private:
	EuropeanOption optdata;


public:
		CallOption ();
		~CallOption ();
		CallOption(EuropeanOption Op) ;
		CallOption(const CallOption& other);
		CallOption& operator = (const CallOption& other);

        //pricers
        double Price(const EuropeanOption &Opt)const;
        double Price_par( double P) const;
        double Price (CallOption &calopt, double param) const;
        double Price (double U)const;
        //mesher
        vector<double>Price(const EuropeanOption & obj,vector<double> Mesh) const;
        vector<double>Price(vector<double> Mesh, double param)const;

            //greeks
            //delta
        double CallDelta( double U) const;   // delta as function of asset price
        vector<double>CallDelta(vector<double> Mesh); //delta for a value
        double CallDelta_approx(double h); //approximating Delta

        //Gamma
        double CallGamma( PutOption & opt); //gamma
        vector<double> Callgamma (PutOption &opt,vector<double> Mesh); //gamma on a range
        double CallGamma_approx(double h, PutOption & opt); //Approximate gamma
};

#endif // CALLOPTION_H
