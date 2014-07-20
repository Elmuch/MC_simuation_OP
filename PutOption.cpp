

//
#include "EuropeanOption.h"
#include "MyUtilities.h"
#include "PutOption.h"
#include <cmath>
#include <boost/math/distributions.hpp>
#include <vector>


PutOption::PutOption()
{
    //ctor
}

PutOption::~PutOption()
{
    //dtor
}
PutOption::PutOption(EuropeanOption Op) :optdata(Op)
 {
 }
PutOption::PutOption(const PutOption& other): optdata(other.optdata)
{
}

//pricers
//
double PutOption::Price(const EuropeanOption &Opt) const
{
    // black scholes
	double tmp = Opt.sig_() * sqrt(Opt.T_());

    double d1 = ( log(Opt.U_()/Opt.K_()) + (Opt.b_()+ (Opt.sig_()*Opt.sig_())*0.5 ) * Opt.T_() )/ tmp;
    double d2 = d1 - tmp;
    return (Opt.K_() * exp((-Opt.r_())*Opt.T_()) * N(-d2)) - (Opt.U_() * exp((Opt.b_()- Opt.r_()) * Opt.T_())* N(-d1));
}

//price based on put-call parity
double PutOption::Price_par ( double C) const
    {
	double P = (optdata.K_()*exp(-optdata.r_()*optdata.T_()));
	return (C+P-optdata.U_()); //put-call parity
    }


double PutOption::Price (double U) const
{
			double tmp = optdata.sig_() * sqrt(optdata.T_());

			double d1 = ( log(U/optdata.K_()) + (optdata.b_()+ (optdata.sig_()*optdata.sig_())*0.5 ) * optdata.T_() )/ tmp;
			double d2 = d1 - tmp;
			return (optdata.K_() * exp((-optdata.r_())*optdata.T_()) * N(-d2)) - (U * exp((optdata.b_()- optdata.r_()) * optdata.T_())* N(-d1));
}

//price given a parameter
double PutOption::Price (PutOption &putopt, double param) const
    {
        if (param == optdata.sig_() || param== optdata.T_()) //given sig ot T and holding other parameters constant
        return (putopt.Price(optdata));
    }

//Price mesher
vector<double>PutOption::Price(const EuropeanOption & obj,vector<double> Mesh) const//price for a range
{
    vector<double> temp;

    for (int i=0; i<Mesh.size();i++)
    {
       double opt = Price(Mesh[i]);
        temp.push_back(opt);
    }
return temp;
}
//
vector<double>PutOption::Price(vector<double> Mesh, double param) const
{
    if (param == optdata.sig_() || param == optdata.T_())
    {
        vector<double> temp;

        for (int i=0; i<Mesh.size();i++)
        {
            double opt = Price(Mesh[i]);
            temp.push_back(opt);
        }
     return temp;

    }
}
        //Greeks
double PutOption::PutDelta(double U)const //Delta
{
    //implementing formula for calculating PutOption delta
	double tmp = optdata.sig_() * sqrt(optdata.T_());

	double d1 = ( log(U/optdata.K_()) + (optdata.b_() + (optdata.sig_()*optdata.sig_())*0.5 ) * optdata.T_() )/ tmp;

	return exp((optdata.b_()-optdata.r_())*optdata.T_()) * (N(d1) - 1.0);
}

vector<double>PutOption::PutDelta(EuropeanOption & obj,vector<double> Mesh) const//delta for a range
{

    vector<double> temp;

    for (int i=0; i<Mesh.size();i++)
    {
       double opt = PutDelta(Mesh[i]); //
        temp.push_back(opt);
    }
     return temp;
}

//Delta approximation
double PutOption::PutDelta_approx(double h) const //h sets the boundaries -h and h
    {
   double temp= Price(optdata.U_()+h) -Price(optdata.U_()-h);  //
   return temp/(2*h);
    }

    //gamma
double PutOption::Putgamma (double U) const //gamma as a function of asset price
{
    //implementing function calculating putoption gamma
    double tmp = optdata.sig_() *sqrt(optdata.T_());

	double d1 = ( log(U/optdata.K_()) + (optdata.b_() + (optdata.sig_()*optdata.sig_())*0.5 ) * optdata.T_() )/ tmp;
	double d2 = d1 - tmp;

	return ( n(d1) * exp((optdata.b_()-optdata.r_())*optdata.T_()) ) / (U * tmp);

}

vector<double> PutOption::Putgamma (vector<double> Mesh) const //gamma for a range
{
vector<double> temp;

    for (int i=0; i<Mesh.size();i++)
    {
       double gamma = Putgamma(Mesh[i]); //
        temp.push_back(gamma);
    }
     return temp;
}

//Approximate gamma using divided differences
double PutOption::Putgamma_approx(double h) const
{
double temp= Price(optdata.U_()+h) - (2*Price(optdata.U_()))+ Price(optdata.U_()-h); //estimate gamma
   return temp/(h*h);
}





