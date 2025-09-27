#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsFindcurrency : public clsScreen
{
public:
static void findcurrency()
{
    showscreen("Find Currency Screen");
    cout<<"Find By : [1] Code OR [2] Country ? "; int option = clsInvalidate::Readintnumberbetween(1,2,"Enter 1 OR 2 : ");
    if (option==1)
    {
        cout<<"Enter Currency Code : "; string code = clsInvalidate::Readstring();
        clsCurrency cur1 = clsCurrency::findcurrencycode(code);
        if(cur1.IsEmptyCurrency()) 
        {
            system("color 4F");
            cout<<"\nThe Country Is Not Found!!\n";
            clsutil::colorgoback();
        }
        else
        {
            system("color 2F");
            cout<<"\nCurrency Found :-) \n";
            clsutil::colorgoback();
            cur1.printcountry();
        }
    }
    else
    {
        cout<<"Enter Country Name : "; string country = clsInvalidate::Readstring();
        clsCurrency cur2 = clsCurrency::findcountry(country);
        if(cur2.IsEmptyCurrency()) 
        {
            system("color 4F");
            cout<<"\nThe Country Is Not Found!!\n";
            clsutil::colorgoback();
        }
        else
        {
            system("color 2F");
            cout<<"\nCurrency Found :-) \n";
            clsutil::colorgoback();
            cur2.printcountry();
        }
    }
}
};