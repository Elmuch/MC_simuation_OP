

//pricers
//sensitivities
//European Call Option
//////////////////////////////////////////////

#include "EuropeanOption.h"
#include "PutOption.h"
#include "CallOption.h"
#include "MyUtilities.h"
#include <cmath>
#include <vector>
using namespace std;
using namespace Ngwachi;

CallOption::CallOption()
{
    //ctor
}

CallOption::~CallOption()
{
    //dtor
}
CallOption::CallOption(EuropeanOption Op) :optdata(Op)
 {
 }
CallOption::CallOption(const CallOption& other): optdata(other.optdata)
{
}
CallOption &CallOption:: operator = (const CallOption& other)
		{
        if (this == &other) return *this;
		optdata= other.optdata;
		return *this;
		}
//option price with EuropeanOption the argument
double CallOption::Price(const EuropeanOption &Opt) const
{
//Exact solution for a pricing a put option
    double tmp = Opt.sig_() * sqrt(Opt.T_());
    double d1 = ( log(Opt.U_()/Opt.K_()) + (Opt.b_()+ (Opt.sig_()*Opt.sig_())*0.5 ) * Opt.T_() )/ tmp;
    double d2 = d1 - tmp;
    return (Opt.U_() * exp((Opt.b_()-Opt.r_())*Opt.T_()) * N(d1)) - (Opt.K_() * exp(-Opt.r_() * Opt.T_())* N(d2));
}

// price based on put-call parity

double CallOption::Price_par( double P) const
{
	double P_temp = (optdata.K_()*exp(-optdata.r_()*optdata.T_()));
	return (P+optdata.U_() - P_temp); //put-call parity
}
//price given volatility or maturity time
 double CallOption::Price (CallOption &calopt, double param) const
    {
        if (param == optdata.sig_() || param == optdata.T_()) //restrict the parameters
        return (calopt.Price(optdata));
    }


//price given underlying asset price
double CallOption::Price (double U) const
{
        //call price formula for exact solution
        double tmp = optdata.sig_() * sqrt(optdata.T_()); //
        double d1 = ( log(U/optdata.K_()) + (optdata.b_()+ (optdata.sig_()*optdata.sig_())*0.5 ) * optdata.T_() )/ tmp;
        double d2 = d1 - tmp;
        return (U * exp((optdata.b_()-optdata.r_())*optdata.T_()) * N(d1)) - (optdata.K_() * exp(-optdata.r_() * optdata.T_())* N(d2));

}

//Price mesher
//Price for a monotonically increasing range
vector<double>CallOption::Price(const EuropeanOption & obj,vector<double> Mesh) const
{
    vector<double> temp;

    for (int i=0; i<Mesh.size();i++)
    {
       double opt= Price(Mesh[i]);
        temp.push_back(opt);
    }
return temp;
}


    //Option prices for a range given a parameter.
vector<double>CallOption::Price(vector<double> Mesh, double param) const
{
    if (param == optdata.sig_() || param == optdata.T_())
    {
        vector<double> temp;

        for (int i=0; i<Mesh.size();i++)
        {
            double opt = Price(Mesh[i]); //Option price for a range of asset prices (i)
            temp.push_back(opt);
        }
            return temp; //return the prices

    }

}

//Option Sensitivities
//
double CallOption::CallDelta(double U) const //Calculate Delta  given price
{
    //Delta for a put Option
    //exact solution
	double tmp = optdata.sig_() * sqrt(optdata.T_());

	double d1 = ( log(U/optdata.K_()) + (optdata.b_() + (optdata.sig_()*optdata.sig_())*0.5 ) * optdata.T_() )/ tmp;


	return exp((optdata.b_()-optdata.r_())*optdata.T_()) * N(d1);
}

//Option Delta for a range
vector<double>CallOption::CallDelta(vector<double> Mesh)
{

    vector<double> temp;

    for (int i=0; i<Mesh.size();i++)
    {
       double opt = CallDelta(Mesh[i]); //
        temp.push_back(opt);
    }
     return temp;

}
//delta approximation using divided difference
double CallOption::CallDelta_approx(double h) //h set the boundaries
    {
   double temp=Price(optdata.U_()+h) -Price(optdata.U_()-h);
   return temp/(2*h);
    }

//Calculate Gamma
double CallOption::CallGamma( PutOption & opt)
{

	return opt.Putgamma(optdata.U_()); //use Putgamma, since put gamma = call gamma
}

//Delta for a range
vector<double>CallOption::Callgamma (PutOption &opt,vector<double> Mesh)
{
return (opt.Putgamma(Mesh)); //Call PutGamma.
}


//delta approximation using divided difference
double CallOption::CallGamma_approx(double h, PutOption & opt)
{
    return opt.Putgamma_approx(h); //Call Put-gamma
}
