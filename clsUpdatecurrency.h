#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsUpdatecurrency : public clsScreen
{
private:
static void rateupdate(clsCurrency cur)
{
  cout<<"\nUpdate Currency Rate : \n";
  cout<<"_________________________\n";
  cout<<"Enter New Rate : "; double rate = clsInvalidate::Readdoublenumber("Invalid Number ");
  system("color 2F");
  cout<<"\nCurrency Rate Updated Succesfully :-) \n";
  clsutil::colorgoback();
  cur.update(rate);
  cur.printcountry();
}
public:
static void updatecurrency()
{
    showscreen("Update Currency Screen");
  
        cout<<"Enter Currency Code : "; string code = clsInvalidate::Readstring();
        clsCurrency cur = clsCurrency::findcurrencycode(code);
        if(cur.IsEmptyCurrency()) 
        {
            system("color 4F");
            cout<<"\nThe Country Is Not Found!!\n";
            clsutil::colorgoback();
        }
        else
        {
            cur.printcountry();
            cout<<"\nAre You Sure you want to update the rate of this currency ? Y/N "; char c; cin>>c;
            if (c=='y' ||c=='Y') rateupdate(cur);
            else                 cout<<"\nYou Canceled Update The Rate.\n";
            
        }
}
};