#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsFiles.h"
using namespace std;

class clsTotalbalance : public clsScreen
{
 private:
 static string Sumtotalbalance(vector<Stclient>svclient)
 {
     int sum=0;
     for(auto &it:svclient) sum+=stoi(it.balance);
     return to_string(sum); 
 }

 public:
 static void Showtotalbalance()
 {
    
    vector<Stclient>svclient=clsFiles::fulllist();
    string subheader="("+to_string(svclient.size())+") Clients(s).";
    showscreen("Balance List Screen",subheader);
    cout<<'\n'; clsutil::Taps(3);
    cout<<"-----------------------------------------------------------------------------\n";
    clsutil::Taps(4);
    cout<<"| "<<setw(15)<<left<<"Account Number "
    <<"| "<<setw(20)<<left<<"Client Name "
    <<"| "<<setw(12)<<left<<"Balance";
    cout<<'\n'; clsutil::Taps(3);
    cout<<"-----------------------------------------------------------------------------\n";
    for (int i = 0; i < svclient.size(); i++)
    {
    clsutil::Taps(4); 
    cout<<"| "<<setw(15)<<left<<svclient.at(i).account
    <<"| "<<setw(20)<<left<<svclient.at(i).name
    <<"| "<<setw(12)<<left<<svclient.at(i).balance<<endl;
    }
    clsutil::Taps(3);
    cout<<"-----------------------------------------------------------------------------\n";
    clsutil::Taps(6); cout<<"Total Balances Is : "<<Sumtotalbalance(svclient)<<'\n';
 }
};