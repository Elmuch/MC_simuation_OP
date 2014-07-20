
//European put option pricer
//

#ifndef PutOption_h
#define PutOption_h
#include "EuropeanOption.h"
#include "MyUtilities.h"
#include <cmath>
//#include <boost/math/distributions.hpp>
#include <vector>
using namespace Ngwachi;


class PutOption
{
private:
	EuropeanOption optdata; //Option parameters


public:
		PutOption ();
		~PutOption ();
		PutOption(EuropeanOption Op);
		PutOption(const PutOption& other);
		PutOption &operator =(const PutOption& other);

        //pricers
    double Price(const EuropeanOption &Opt) const;
	double Price_par (double C) const; //put-call parity
    double Price (double U) const;   //price given underlying asset
    double Price (PutOption &putopt, double param) const;

    //Price mesher
    vector<double>Price(const EuropeanOption & obj,vector<double> Mesh) const; //price for a range
    vector<double>Price(vector<double> Mesh, double param) const; //price for a range given a parameter

    //greeks
    double PutDelta(double U)const; //delta given asset price
    vector<double>PutDelta(EuropeanOption & obj,vector<double> Mesh)const; //delta for a range
    double PutDelta_approx(double h)const; //Approximate delta using divided differences

    //gamma
    double Putgamma (double U)const;  //gamma as a function of asset price
    vector<double> Putgamma (vector<double> Mesh) const; //gamma for a range
    double Putgamma_approx(double h) const; //approximate gamma



};
#endif
