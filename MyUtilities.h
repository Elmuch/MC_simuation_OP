
//Utilities.h
//mesh producer

///////////////////////////////
#ifndef MYUTILITIES_H
#define MYUTILITIES_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
//#include <boost/math/distributions.hpp>

using namespace std;
namespace Ngwachi
{
//mesh producer
inline vector<double>Mesh(double start, double end, double h) //
{
    vector<double> temp;

    for(start; start<=end; start+=h) // interval of h
    {
        temp.push_back(start);
    }
    return temp;
}

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
//inline double n(double x)
	//{
//boost::math::normal_distribution<> Mynormal(0.0,1.0); //standard normal variable

//return pdf(Mynormal,x);
	//}

//normal cdf
//inline double N(double x)
	//{ //boost normal distribution
//boost::math::normal_distribution<> Mynormal(0.0,1.0);

//return cdf(Mynormal,x);
	//}
//}
#endif
