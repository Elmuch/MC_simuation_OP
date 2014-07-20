
//
//driver
//

#include "EuropeanOption.h"
#include <iostream>
#include "MyUtilities.h"
#include "CallOption.h"
#include "PutOption.h"
#include <vector>
#include <fstream>

using namespace Ngwachi;
using namespace std;

int main()
{
    int p = 6;
        char data[p];
    ifstream GetFromClient;
    GetFromClient.open("/home/ngwachi/Desktop/developer/optionData.txt");//created by rails client
        cout<<"reading from file"<<endl;

        for ( int n2=0; n2<p; ++n2)
        {
         GetFromClient >> data;
        cout<<data<<endl;
        }

    GetFromClient.close();

	double T = data[0];
	double K =data[1];
	double sig = data[2];
	double r = data[3];
	double S = data[4];
	double b = r-0.0;

    EuropeanOption Batch1(T,K,sig,r,S,b);
    CallOption C(Batch1);
    PutOption  P(Batch1);
    ofstream SendtoClient;
    SendtoClient.open("/home/ngwachi/Desktop/developer/results.json");
        SendtoClient <<"Hello some output here"<<endl;

    SendtoClient<<"---------------Batch1--------------------------------- \n"<<endl;

    //test  pricers
    SendtoClient <<"Call price: " <<C.Price(Batch1)<<", Put Price: " <<P.Price(Batch1)<<endl;
    SendtoClient<<"based on put-call parity: " <<C.Price_par(P.Price(Batch1)) //call price given Put price
    <<" , "<<P.Price_par(C.Price(Batch1))<<endl;        //put price given call price
    SendtoClient<< "Price given sig or T: Call: "<<C.Price(C,sig)<<" , Put: "<<P.Price(P,T)<<"\n"<<endl;    //price given volatility or maturity time

        //Test meshers
    vector<double> P_m= P.Price(Batch1,Mesh(40,60,10)); //put price mesher
     print(P_m,string("Put Price mesher: ")); //

    vector<double> P_m1= P.Price(Mesh(40,60,10),T);     //put price mesher given T
    print(P_m1,string("Put price mesher  given  T: "));

    vector<double> C_m= C.Price(Batch1,Mesh(40,60,10)); //call price  mesher
    print(C_m,string("Call Price mesher: "));   //

    vector<double> C_m1= C.Price(Mesh(40,60,10),sig);   //call price given sig
    print(C_m1,string("Call price mesher given sig : ")); //


SendtoClient<<"\n---------------Batch2--------------------------------- \n"<<endl;

        //Batch 2
    T=1.0; K=100; sig =0.2; r=0.0; S= 100; b=0.0;
    EuropeanOption Batch2 (T,K,sig,r,S,b);
    CallOption C2(Batch2);
    PutOption  P2(Batch2);

   //test  pricers
    SendtoClient <<"Call price: " <<C2.Price(Batch2)<<", Put Price: " <<P2.Price(Batch2)<<endl;
    SendtoClient<<"based on put-call parity: " <<C2.Price_par(P2.Price(Batch2)) //call price given Put price
    <<" , "<<P2.Price_par(C2.Price(Batch2))<<endl;        //put price given call price
    SendtoClient<< "Price given sig or T: Call: "<<C2.Price(C2,sig)<<" , Put: "<<P2.Price(P,T)<<endl;    //price given volatility or maturity time

    //Test meshers
    P_m= P2.Price(Batch2,Mesh(70,100,10)); //put price mesher
    print(P_m,string("Put Price mesher: "));

    P_m1= P2.Price(Mesh(70,100,10),T); // put price mesher given maturity Time
    print(P_m1,string("Put price mesher given T: ")); //put price on a range given sig or T

    C_m= C2.Price(Batch2,Mesh(70,100,10)); // Call price mesher
    print(C_m,string("Call Price mesher: "));   //

    C_m1= C2.Price(Mesh(70,100,10),sig); //call mesher given  volatiltiy
    print(C_m1,string("Call price mesher given sig ")); // call price on a range given sig or T

SendtoClient<<"\n---------------Batch3--------------------------------- \n"<<endl;

//Batch 3
    T=1.0; K=10; sig =0.5; r=0.12; S= 5; b=r-0.0;
    EuropeanOption Batch3(T,K,sig,r,S,b);
    CallOption C3(Batch3);
    PutOption  P3(Batch3);

   //test  pricers
    SendtoClient <<"Call price: " <<C3.Price(Batch3)<<", Put Price: " <<P3.Price(Batch3)<<endl;
    SendtoClient<<"based on put-call parity: " <<C3.Price_par(P3.Price(Batch3)) //call price given Put price
    <<" , "<<P3.Price_par(C3.Price(Batch3))<<endl;        //put price given call price
    SendtoClient<< "Price given sig or T: Call: "<<C3.Price(C3,sig)<<" , Put: "<<P3.Price(P,T)<<endl;    //price given volatility or maturity time

    //Test meshers
    P_m= P3.Price(Batch3,Mesh(1,5,1)); //put price mesher
    print(P_m,string("Put Price mesher: "));

    P_m1= P3.Price(Mesh(1,5,1),T); // put price mesher given maturity Time
    print(P_m1,string("Put price mesher given T: ")); //put price on a range given sig or T

    C_m= C3.Price(Batch3,Mesh(1,5,1)); // Call price mesher
    print(C_m,string("Call Price mesher: "));   //

    C_m1= C3.Price(Mesh(1,5,1),sig); //call mesher given  volatiltiy
    print(C_m1,string("Call price mesher given sig ")); //


SendtoClient<<"\n---------------Batch4--------------------------------- \n"<<endl;

//Batch 4
    T=30.0; K=100.0; sig =0.30; r=0.08; S= 100; b=r-0.0;
    EuropeanOption Batch4(T,K,sig,r,S,b);
    CallOption C4(Batch4);
    PutOption  P4(Batch4);

    SendtoClient <<"Call price: " <<C4.Price(Batch4)<<", Put Price: " <<P4.Price(Batch4)<<endl;
    SendtoClient<<"based on put-call parity: " <<C4.Price_par(P4.Price(Batch4)) //call price given Put price
    <<" , "<<P4.Price_par(C4.Price(Batch4))<<endl;        //put price given call price
    SendtoClient<< "Price given sig or T: Call: "<<C4.Price(C4,sig)<<" , Put: "<<P4.Price(P,T)<<endl;    //price given volatility or maturity time

    //Test meshers
    P_m= P4.Price(Batch4,Mesh(70,100,10)); //put price mesher
    print(P_m,string("Put Price mesher: "));

    P_m1= P4.Price(Mesh(70,100,10),T); // put price mesher given maturity Time
    print(P_m1,string("Put price mesher given T: ")); //put price on a range given sig or T

    C_m= C4.Price(Batch4,Mesh(70,100,10)); // Call price mesher
    print(C_m,string("Call Price mesher: "));   //

    C_m1= C4.Price(Mesh(70,100,10),sig); //call mesher given  volatiltiy

//Test Greeks
SendtoClient<<"\n------------------Greeks---------------------------" <<endl;
    S=105; T=0.5;  r=0.1;  b=0.0; sig =0.36; K=100;
    EuropeanOption greek(T,K,sig,r,S,b);
    CallOption Call(greek);
    PutOption Put(greek);

     //Test delta
    SendtoClient<<"Call delta: "<<Call.CallDelta(S)<<" Putdelta:  "<<Put.PutDelta(S)<<endl;

    //test meshers
    vector<double> Call_del= Call.CallDelta(Mesh(95,105,5)); //Call delta mesher
     print(Call_del, string ("Call delta mesher : "));

    vector<double> Put_del=Put.PutDelta(greek,Mesh(95,105,5));
    print(Put_del, string ("Put delta mesher : "));

    //test gamma
    SendtoClient <<"\n option gamma: "<<Put.Putgamma(S)<<endl;

    //gamma mesher
    vector<double> Put_gamma =Put.Putgamma(Mesh(95,105,5)); //put gamma mesher
    print(Put_gamma, string("Put gamma mesher:  "));

    vector<double> call_gamma =Call.Callgamma(Put,Mesh(95,105,5)); //call gamma mesher
    print(call_gamma, string("Call gamma mesher: ")); //



    // Test appromation of delta and  gamma
    SendtoClient<<"\n Approximation of sensitivities "<<endl;
for (double h = 2.0; h>0.1; h-=0.1) //test convergence from 1.0 to 0.1
{
    SendtoClient<<"h :"<<h<<" CallDelta: "<<Call.CallDelta_approx(h) //test call delta approximation
    <<" put delta: "<<Put.PutDelta_approx(h)    //test put delta approximation
    <<" Gamma: "<<Call.CallGamma_approx(h,Put)  //test gamma approximation
    <<endl;
}
SendtoClient.close();
	return 0;
} //end main





















