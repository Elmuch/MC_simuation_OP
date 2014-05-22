
// PutOption.h
//american put option.
//


#include "OptionData.h"
#include "Option.h"
#ifndef PUTOPTION_H_INCLUDED
#define PUTOPTION_H_INCLUDED




class PutOption
{
    private:
        OptionData data;

    public:
        PutOption() {} //default constructor
        ~PutOption () {} //destructor
        PutOption(const PutOption& other): data(other.data) //copy constructor
        {
        }
        double Price(const OptionData & data) const //takes instance of OptionData as argument
        {
        return Ngwachi::PerpetualPut(data.K,data.S,data.sig,data.r,data.b); //call global PerputalPut
        }

        vector<double> Price(const OptionData &data, vector<double> Mesh) //Price for a range
        {
            vector<double> temp; //to store the price

            for (int i=0; i<Mesh.size();i++)
            {

                double opt =Ngwachi::PerpetualPut(data.K,Mesh[i],data.sig,data.r,data.b);//store values for a range
                temp.push_back(opt); //add the values to the vector
            }
	return temp; //return vector with price value
        }


};
#endif
