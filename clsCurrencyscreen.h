#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clslistcurrency.h"
#include "clsFindcurrency.h"
#include "clsUpdatecurrency.h"
#include "clscurCalculator.h"
using namespace std;

class clsCurexchange : public clsScreen
{
  private:
  enum showcur {eListCurrency = 1, eFindCurrency = 2, eUpdateCurrency = 3, eCurrencyCalculator = 4, eMainmenue = 5};
  static short readoption()
  {
    clsutil::Taps(5); cout<<"Choose What do you want to do ? [1 to 5] : ";
    int option=clsInvalidate::Readintnumberbetween(1,5,"Enter Number From 1 To 5 : ");
    return option;
  }
  static void gobackcur()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menue...";
        system("pause>0");
        showCurrencyscreen();
    }
  static void performcurrencyoption(showcur option)
  { 
     switch (option)
            {
            case showcur::eListCurrency:
            {
                system("cls");
                clslistcur::ShowListCurrency();
                gobackcur();
                break;
            }
            case showcur::eFindCurrency:
                system("cls");
                clsFindcurrency::findcurrency();
                gobackcur();
                break;

            case showcur::eUpdateCurrency:
                system("cls");
                clsUpdatecurrency::updatecurrency();
                gobackcur();
                break;

            case showcur::eCurrencyCalculator:
                system("cls");
                clsCurcalc::curcalc();
                gobackcur();
                break;

            case showcur::eMainmenue:
                system("cls");
                clsutil::goback();
                break;
  }
}
public:
static void showCurrencyscreen()
        {
            system("cls");
            showscreen("Currency Exchange Main Screen");
            clsutil::Taps(5); cout << "===========================================\n";
            clsutil::Taps(4); cout << "\t\t\tCurrency Exchange Menue\n";
            clsutil::Taps(5); cout << "===========================================\n";
            clsutil::Taps(6); cout << "[1] List Currencies.\n";
            clsutil::Taps(6); cout << "[2] Find Currency.\n";
            clsutil::Taps(6); cout << "[3] Update Rate.\n";
            clsutil::Taps(6); cout << "[4] Currency Calculator.\n";
            clsutil::Taps(6); cout << "[5] Main Menue.\n";
            clsutil::Taps(5); cout << "===========================================\n";
            performcurrencyoption((showcur)readoption());
        }
};