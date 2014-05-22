
//
// OptionData.hpp
//
// Encapsulate option data.
//
// (

#ifndef OptionData_HPP
#define OptionData_HPP
using namespace std;

// Encapsulate all data in one place
struct OptionData
{ // Option data

	double K; //strike
	double r;   //interest rate
	double sig; //volatility
	double S;   //asset price
	double b;   //const of carry


};


#endif