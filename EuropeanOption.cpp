//


//
#include "EuropeanOption.h"
#include <cmath>
#include <iostream>
#include <boost/math/distributions.hpp>

EuropeanOption::EuropeanOption()
{
}
EuropeanOption::EuropeanOption(double Tval,double Kval, double sigval, double rval, double Uval, double bval)
	:T(Tval),K(Kval),sig(sigval),r(rval),U(Uval),b(bval)
{
}
EuropeanOption::~EuropeanOption ()
{
}
EuropeanOption::EuropeanOption(const EuropeanOption& other)
	:T(other.T),K(other.K),sig(other.sig),r(other.r),b(other.b),U(other.U)
{
}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& other)
{

	if (this == &other) return *this;
T=other.T;
U=other.U;
K=other.K;
b=other.b;
sig=other.sig;
r=other.r;
return *this;
}

double EuropeanOption::T_ () const {return T;}
double EuropeanOption::U_ () const {return U;}
double EuropeanOption::K_ () const {return K;}
double EuropeanOption::b_ () const {return b;}
double EuropeanOption::sig_ () const {return sig;}
double EuropeanOption::r_ () const {return r;}
