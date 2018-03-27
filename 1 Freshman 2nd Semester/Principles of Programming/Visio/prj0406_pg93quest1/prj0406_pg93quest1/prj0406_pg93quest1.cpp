#include<iostream>
using namespace std;
/*Input:Cost of one pencil, the inflation rate, number of years to calculate the price of 200 pencils
Output: Tells the cost of each pencil and which year the pencils will cost that much
*/
void main()
{
    //Constants and Variables
    float pcost, irate, tcost;            //cost of each pencil, inflation rate, total cost each year
    int nyears, penc=200, i;                //number of years to be buying pencil, number of pencils each year

    //Algorithm
    cout<<"What is the cost of each pencil:\t";
    cin>>pcost;
    cout<<"What is the inflation rate per year in percent:\t";
    cin>>irate;
    irate=irate/100;
    cout<<"How many years will you be buying pencils:\t";
    cin>>nyears;
    tcost=pcost*penc;
    cout<<"\n\nNow (year 1), 200 pencils will cost $"<<tcost<<".\n";
    for(i=2;i<=nyears;i++)
    {
        pcost=(pcost*irate)+pcost;
        tcost=pcost*penc;
        cout<<"For year "<<i<<", 200 pencils will cost $"<<tcost<<".\n";
    }
}