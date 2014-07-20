
#ifndef EuropeanOption_h
#define EuropeanOption_h
#include <vector>

using namespace std;

class EuropeanOption
{
private:
	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double b;		// Cost of carry
	double U;




public:
	EuropeanOption();
	virtual ~EuropeanOption();

	EuropeanOption(double Tval,double Kval, double sigval,double rval, double Uval, double bval);
	EuropeanOption& operator = (const EuropeanOption& other);
	EuropeanOption(const EuropeanOption& other);


	//Accessors
	double T_ () const; // get T
	double r_ () const;	//get r
	double sig_ () const;	//get sig
	double K_ () const;		//get K
	double b_ () const;		//get b
	double U_() const;		// get U


};

#endif
