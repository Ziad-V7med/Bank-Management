#pragma once
#include <bits/stdc++.h>
#include "clsInvalidate.h"
#include "clsShowlist.h"
#include "clsAddclient.h"
#include "clsDeleteclient.h"
#include "clsUpdateclient.h"
#include "clsFindclient.h"
#include "clsTransaction.h"
#include "clsManngeuser.h"
#include "clsCurrencyscreen.h"
#include "clsLogregister.h"
#include "clsGlopal.h"
using namespace std;

class clsMainscreen : public clsScreen
{
  private:
  enum showmenu {eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
                 eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
                 eManageUsers = 7, eLogRegister = 8,eCurrency = 9, eLogout = 10,eExit = 11};
  static short readoption()
  {
    clsutil::Taps(5); cout<<"Choose What do you want to do ? [1 to 11] : ";
    int option=clsInvalidate::Readintnumberbetween(1,11,"Enter Number From 1 To 11 : ");
    return option;
  }
  static void logout()
  {
    Currentuser = clsUser::getemptyuser();
  }
  static bool ispermission(int option)
  {
     return (Currentuser.getPermission()&(1<<(option-1)) || Currentuser.getPermission()==-1);
  }
  static void headerNotaccess()
  {
      
      clsutil::Taps(5); cout<<"------------------------------------------------------------\n";
      clsutil::Taps(7); cout<<"Access Denied! Contact your Admin.\n";
      clsutil::Taps(5); cout<<"------------------------------------------------------------\n";
  }
  static void performmenuoption(showmenu option)
  { 
     switch (option)
            {
            case showmenu::eListClients:
            {
                system("cls");
                if(ispermission(1)) clsShowlist::ShowMenuScreen();
                else                headerNotaccess();
                clsutil::goback();
                break;
            }
            case showmenu::eAddNewClient:
                system("cls");
                if(ispermission(2)) clsAddclient::Addnewclient();
                else                headerNotaccess();
                clsutil::goback();
                break;

            case showmenu::eDeleteClient:
                system("cls");
                if(ispermission(3)) clsDeleteclient::Deleteclient();
                else                headerNotaccess();
                clsutil::goback();
                break;

            case showmenu::eUpdateClient:
                system("cls");
                if(ispermission(4)) clsUpdateclient::Updateclient();
                else                headerNotaccess();
                clsutil::goback();
                break;

            case showmenu::eFindClient:
                system("cls");
                if(ispermission(5)) clsFindclient::Findclient();
                else                headerNotaccess();
                clsutil::goback();
                break;

            case showmenu::eShowTransactionsMenue:
                system("cls");
                if(ispermission(6))  clsTransaction::Showtransaction();
                else                 {headerNotaccess(); clsutil::goback();}
                break;

            case showmenu::eManageUsers:
                system("cls");
                if(ispermission(7))  clsMangeuser::Showmangeuser();
                else                 {headerNotaccess(); clsutil::goback();}
                break;
            case showmenu::eLogRegister:
                system("cls");
                if(ispermission(8))  clsregister::showloginregister();
                else                 headerNotaccess();
                clsutil::goback();
                break;
            case showmenu::eCurrency:
                system("cls");
                if(ispermission(9))  clsCurexchange::showCurrencyscreen();
                else                 {headerNotaccess(); clsutil::goback();}
                break;

            case showmenu::eLogout:
                system("cls");
                LOGIN=NO;
                logout();
                break;
            default :
                system("cls");
                LOGIN=NO;
                play=OFF;
                break;
            } 
  }
  public:
 static void showmainscreen()
        {
            system("cls");
            showscreen("Main Screen");
            clsutil::Taps(5); cout << "===========================================\n";
            clsutil::Taps(4); cout << "\t\t\tMain Menue\n";
            clsutil::Taps(5); cout << "===========================================\n";
            clsutil::Taps(6); cout << "[1]  Show Client List.\n";
            clsutil::Taps(6); cout << "[2]  Add New Client.\n";
            clsutil::Taps(6); cout << "[3]  Delete Client.\n";
            clsutil::Taps(6); cout << "[4]  Update Client Info.\n";
            clsutil::Taps(6); cout << "[5]  Find Client.\n";
            clsutil::Taps(6); cout << "[6]  Transactions.\n";
            clsutil::Taps(6); cout << "[7]  Manage Users.\n";
            clsutil::Taps(6); cout << "[8]  Login Registers.\n";
            clsutil::Taps(6); cout << "[9]  Currency Exchange.\n";
            clsutil::Taps(6); cout << "[10] Logout.\n";
            clsutil::Taps(6); cout << "[11] Exit.\n";
            clsutil::Taps(5); cout << "===========================================\n";
            performmenuoption((showmenu)readoption());
        }
};


