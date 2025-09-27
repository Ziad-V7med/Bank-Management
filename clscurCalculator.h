#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsCurcalc : public clsScreen
{
private:
static double To_USD(double amount,clsCurrency cur1)
{
   return amount/cur1.Rate();
}
static double From_USD(double amount,clsCurrency cur1,clsCurrency cur2)
{
   return To_USD(amount,cur1)*cur2.Rate();
}
static void printcountry(clsCurrency cur1)
{
    cout<<"_____________________________\n";
    cout<<"Country  : "<<cur1.Country()<<'\n';
    cout<<"Code     : "<<cur1.CurrencyCode()<<'\n';
    cout<<"Name     : "<<cur1.CurrencyName()<<'\n';
    cout<<"Rate(1$) : "<<cur1.Rate()<<'\n';
    cout<<"_____________________________\n";

}
static void Exchange(clsCurrency cur1,clsCurrency cur2)
{
 if (cur1.CurrencyCode() == cur2.CurrencyCode())
  {
       system("color 4F");
       cout << "\nYou selected the same currency for both sides. No conversion needed.\n";
       clsutil::colorgoback();
       return;
  }
 cout<<"\nEnter Amount To Exchange : "; double amount = clsInvalidate::Readdoublenumber("Invalid Number ");
 cout<<"\nConvert From : \n";
 printcountry(cur1);
 if(cur1.CurrencyCode()=="USD")
 {
   cout<<"\n"<<amount<<" "<<cur1.CurrencyCode()<<" = "<<amount*cur2.Rate()<<" "<<cur2.CurrencyCode();
   return;
 }
   cout<<"\n"<<amount<<" "<<cur1.CurrencyCode()<<" = "<<To_USD(amount,cur1)<<" USD";
 if(cur2.CurrencyCode()!="USD")
 {
  cout<<"\n\nTo : \n";
  printcountry(cur2);
  cout<<"\n"<<amount<<" "<<cur1.CurrencyCode()<<" = "<<From_USD(amount,cur1,cur2)<<" "<<cur2.CurrencyCode();
 }
}
public:
static void curcalc()
{
    showscreen("Currency Calculator Screen");
    clsCurrency cur1 = clsCurrency::findcountry("");
    clsCurrency cur2 = clsCurrency::findcountry("");
    do
    {
        cout<<"Please Enter Currency1 Code : "; string code = clsInvalidate::Readstring();
        cur1 = clsCurrency::findcurrencycode(code);
        if(cur1.IsEmptyCurrency())
        {
            system("color 4F");
            cout<<"Not Found! Try Again : \n\n";
            clsutil::colorgoback();
            system("cls");
        }
    } while (cur1.IsEmptyCurrency());
    do
    {
        cout<<"Please Enter Currency2 Code : "; string code = clsInvalidate::Readstring();
        cur2 = clsCurrency::findcurrencycode(code);
        if(cur2.IsEmptyCurrency())
        {
            system("color 4F");
            cout<<"Not Found! Try Again : \n\n";
            clsutil::colorgoback();
        }
    } while (cur2.IsEmptyCurrency());
    Exchange(cur1,cur2);
}
};