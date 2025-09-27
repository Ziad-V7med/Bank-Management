#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsFiles.h"

using namespace std;

class clsShowlist : public clsScreen
{
  
  public:
  static void ShowMenuScreen()
  {
    vector<Stclient>svclient=clsFiles::fulllist();
    string subheader="("+to_string(svclient.size())+") Clients(s).";
    showscreen("Client List Screen",subheader);
    cout<<"\n------------------------------------------------------------------------------------------------------\n";
    cout<<"| "<<setw(15)<<left<<"Account Number "
    <<"| "<<setw(20)<<left<<"Client Name "
    <<"| "<<setw(12)<<left<<"Phone "
    <<"| "<<setw(25)<<left<<"Email "
    <<"| "<<setw(10)<<left<<"Pin code "
    <<"| "<<setw(12)<<left<<"Balance";
    cout<<"\n------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < svclient.size(); i++)
    {
      cout<<"| "<<setw(15)<<left<<svclient.at(i).account
    <<"| "<<setw(20)<<left<<svclient.at(i).name
    <<"| "<<setw(12)<<left<<svclient.at(i).phone
    <<"| "<<setw(25)<<left<<svclient.at(i).email
    <<"| "<<setw(10)<<left<<svclient.at(i).pincode
    <<"| "<<setw(12)<<left<<svclient.at(i).balance<<endl;
    }
    cout<<"------------------------------------------------------------------------------------------------------\n";
  }
  
};

