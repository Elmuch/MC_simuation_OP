
//Option.h
//functions for pricing american perpertual option
//exact solutions using black scholes model
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

    //pricer for american  call option
  inline  double PerpetualCall (double K, double S, double sig, double r, double b)
    {
        //black scholes exact solutions model
        double y1 = 0.5 - b/(sig*sig) + sqrt(pow((b/(sig*sig)-0.5),2) + (2.0*r/(sig*sig))); //

        return  (K/(y1-1.0)) * pow((((y1-1)*S)/(y1*K)), y1); //Callprice
    }

    //pricer for American Put option
   inline double PerpetualPut (double K, double S, double sig, double r, double b)
    {

         //black scholes exact solutions model
        double y2 = 0.5 - b/(sig*sig) - sqrt(pow((b/(sig*sig)-0.5),2) + (2.0*r/(sig*sig))); 

        return (K/(1.0-y2)) * pow((((y2-1)*S)/(y2*K)), y2); //putprice
    }

    //mesh producer function
    inline vector<double>Mesh(double start, double end, double h) //
    {
    vector<double> temp; //to store values

    for(start; start<=end; start+=h) //loop from start to end on an interval of h
    {
        temp.push_back(start); //add values to the vector
    }
    return temp;
    }



    //function for printing vectors
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
	//Normal pdf
    inline double n(double x)
	{
        boost::math::normal_distribution<> Mynormal(0.0,1.0); //standard normal variable

        return pdf(Mynormal,x);
    }

    //normal cdf
    inline double N(double x)
    { //boost normal distribution
        boost::math::normal_distribution<> Mynormal(0.0,1.0); //standard normal variable

        return cdf(Mynormal,x);
	}


} //end namespace
#endif //Option_h
