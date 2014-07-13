

//calculate exact solution 
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
        CallOption() {} 
        ~CallOption () {} 
        CallOption(const CallOption& other): data(other.data) 
        {
        }

        //Exact Call price
        double Price(const OptionData & data) const 
        {
        return Ngwachi::PerpetualCall(data.K,data.S,data.sig,data.r,data.b); 
        }

        //price for a range
        vector<double> Price(const OptionData &data, vector<double> Mesh)
        {
            vector<double> temp; 

            for (int i=0; i<Mesh.size();i++)
            {

                double opt =Ngwachi::PerpetualCall(data.K,Mesh[i],data.sig,data.r,data.b);//TODO check the mesher for holes!
                temp.push_back(opt);
            }
	return temp; 
        }
};

#endif