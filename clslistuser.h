#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsSlistuser : public clsScreen
{
  
  public:
  static void showlistuser()
  {
    vector<clsUser>cvusers=clsUser::fulllist();
    string subheader="("+to_string(cvusers.size())+") Users(s).";
    showscreen("User List Screen",subheader);
    cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
    cout<<"| "<<setw(10)<<left<<"Username "
    <<"| "<<setw(20)<<left<<"Full Name "
    <<"| "<<setw(12)<<left<<"Phone "
    <<"| "<<setw(25)<<left<<"Email "
    <<"| "<<setw(10)<<left<<"Password "
    <<"| "<<setw(5)<<left<<"Permissions";
    cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < cvusers.size(); i++)
    {
      cout<<"| "<<setw(10)<<left<<cvusers.at(i).getUsername()
    <<"| "<<setw(20)<<left<<cvusers.at(i).getFullname()
    <<"| "<<setw(12)<<left<<cvusers.at(i).getPhone()
    <<"| "<<setw(25)<<left<<cvusers.at(i).getEmail()
    <<"| "<<setw(10)<<left<<cvusers.at(i).getPassword()
    <<"| "<<setw(5)<<left<<cvusers.at(i).getPermission()<<endl;
    }
    cout<<"-----------------------------------------------------------------------------------------------------------\n";
  }
  
};

