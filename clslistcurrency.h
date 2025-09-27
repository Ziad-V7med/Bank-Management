#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clslistcur : public clsScreen
{
  
  public:
  static void ShowListCurrency()
  {
    vector<clsCurrency>svcountries=clsCurrency::Fullfile();
    string subheader="("+to_string(svcountries.size())+") Currency(s).";
    showscreen("Currencies List Screen",subheader);
    cout<<"\n-------------------------------------------------------------------------------------------------------------------\n";
    cout<<"| "<<setw(40)<<left<<"Country "
    <<"| "<<setw(6)<<left<<"Code "
    <<"| "<<setw(35)<<left<<"Name "
    <<"| "<<setw(10)<<left<<"Rate/(1$) ";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < svcountries.size(); i++)
    {
      cout<<"| "<<setw(40)<<left<<svcountries.at(i).Country()
    <<"| "<<setw(6)<<left<<svcountries.at(i).CurrencyCode()
    <<"| "<<setw(35)<<left<<svcountries.at(i).CurrencyName()
    <<"| "<<setw(10)<<left<<svcountries.at(i).Rate()<<endl;
    }
    cout<<"-------------------------------------------------------------------------------------------------------------------\n";
  }
  
};

