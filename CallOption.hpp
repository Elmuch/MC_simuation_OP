
// CallOption.
//functions to calculate exact solution for
//American call option
//


#ifndef CallOption_h
#define CallOption_h


#include "Option.h"  //pricers
#include "OptionData.h" //option parameters


class CallOption
{
    private:
        OptionData data;

    public:
        CallOption() {} //default constructor
        ~CallOption () {} //destructor
        CallOption(const CallOption& other): data(other.data) //copy constructor
        {
        }

        //Exact Call price
        double Price(const OptionData & data) const //takes an instance of Option data
        {
        return Ngwachi::PerpetualCall(data.K,data.S,data.sig,data.r,data.b); //call global perpetualCall function
        }

        //price for a range
        vector<double> Price(const OptionData &data, vector<double> Mesh)
        {
            vector<double> temp; //to store the price

            for (int i=0; i<Mesh.size();i++)
            {

                double opt =Ngwachi::PerpetualCall(data.K,Mesh[i],data.sig,data.r,data.b);//store values for a range
                temp.push_back(opt); //add the values to the vector
            }
	return temp; //return vector with price value
        }
};

#endif