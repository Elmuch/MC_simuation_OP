
// PutOption.h
//american put option.
//


#include "OptionData.h"
#include "Option.h"
#ifndef PUTOPTION_H_INCLUDED
#define PUTOPTION_H_INCLUDED



//TODO consider a namespace
class PutOption
{
    private:
        OptionData data;

    public:
        PutOption() {} 
        ~PutOption () {} 
        PutOption(const PutOption& other): data(other.data) 
        {
        }
        double Price(const OptionData & data) const 
        {
        return Ngwachi::PerpetualPut(data.K,data.S,data.sig,data.r,data.b); 
        }

        vector<double> Price(const OptionData &data, vector<double> Mesh) 
        {
            vector<double> temp; 

            for (int i=0; i<Mesh.size();i++)
            {

                double opt =Ngwachi::PerpetualPut(data.K,Mesh[i],data.sig,data.r,data.b);
                temp.push_back(opt); 
            }
	return temp; 
        }


};
#endif
