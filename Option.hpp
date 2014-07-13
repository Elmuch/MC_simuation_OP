
//american perpertual option
//black scholes exact solutions
///////////////////////////////
#ifndef Option_h
#define Option_h

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <boost/math/distributions.hpp>

using namespace std;
namespace Ngwachi 
{
  inline  double PerpetualCall (double K, double S, double sig, double r, double b)
    {
        double y1 = 0.5 - b/(sig*sig) + sqrt(pow((b/(sig*sig)-0.5),2) + (2.0*r/(sig*sig))); //

        return  (K/(y1-1.0)) * pow((((y1-1)*S)/(y1*K)), y1); //Callprice
    }

   inline double PerpetualPut (double K, double S, double sig, double r, double b)
    {
        double y2 = 0.5 - b/(sig*sig) - sqrt(pow((b/(sig*sig)-0.5),2) + (2.0*r/(sig*sig))); 

        return (K/(1.0-y2)) * pow((((y2-1)*S)/(y2*K)), y2); //putprice
    }

    //mesh producer
    inline vector<double>Mesh(double start, double end, double h) //
    {
    vector<double> temp; 

    for(start; start<=end; start+=h) 
    {
        temp.push_back(start); //add values to the vector
    }
    return temp;
    }

//utilities
    template <typename T>
    inline void print(const vector<T>& l, const string& comment)
    {
        cout << comment;
        typename vector<T>::const_iterator i;
        for (i = l.begin(); i != l.end(); ++i)
        {
			cout << *i << " , ";
        }

        cout << endl;
    }
	// Gaussian functions
    inline double n(double x)
	{
        boost::math::normal_distribution<> Mynormal(0.0,1.0); 

        return pdf(Mynormal,x);
    }

    //normal cdf
    inline double N(double x)
    { //boost normal distribution
        boost::math::normal_distribution<> Mynormal(0.0,1.0); 

        return cdf(Mynormal,x);
	}


}
#endif //Option_h
