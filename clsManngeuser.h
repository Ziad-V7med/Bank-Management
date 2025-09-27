#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clslistuser.h"
#include "clsAdduser.h"
#include "clsDeleteuser.h"
#include "clsUpdateuser.h"
#include "clsFinduser.h"
using namespace std;

class clsMangeuser : public clsScreen
{
 private:
 enum showmange { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6 };
 static short readoption()
 { 
   clsutil::Taps(5); cout<<"Choose What do you want to do ? [1 to 6] : ";
   int option=clsInvalidate::Readintnumberbetween(1,6,"Enter Number From 1 To 6 : ");
   return option;
  }
  static void gobackmange()
    {
        cout << "\n\nPress any key to go back to Mange Users Menue...";
        system("pause>0");
        Showmangeuser();
    }
 static void performtransactionoption(showmange option)
  {
   switch (option)
   {
       case showmange::eListUsers :
       system("cls");
       clsSlistuser::showlistuser();      
       gobackmange();
       break;
       case showmange::eAddNewUser :
       system("cls");
       clsAdduser::Adduser();       
       gobackmange();
       break;
       case showmange::eDeleteUser :
       system("cls");
       clsDeleteuser::Deleteuser();     
       gobackmange();
       break;
       case showmange::eUpdateUser :
       system("cls");
       clsUpdateuser::Updateuser();     
       gobackmange();
       break;
       case showmange::eFindUser :
       system("cls");
       clsFinduser::Finduser();      
       gobackmange();
       break;
       default:
       system("cls");
       clsutil::goback();
       break;
   }
   }
 public:
 static void Showmangeuser()
 {
    system("cls");
    showscreen("Mange Users Screen");
     clsutil::Taps(5); cout << "===========================================\n";
     clsutil::Taps(4); cout << "\t\t\tMange Users Menue\n";
     clsutil::Taps(5); cout << "===========================================\n";
     clsutil::Taps(6); cout << "[1] List Users.\n";
     clsutil::Taps(6); cout << "[2] Add New User.\n";
     clsutil::Taps(6); cout << "[3] Delete User.\n";
     clsutil::Taps(6); cout << "[4] Update User.\n";
     clsutil::Taps(6); cout << "[5] Find User.\n";
     clsutil::Taps(6); cout << "[6] Main Menue.\n";
     clsutil::Taps(5); cout << "===========================================\n";
     performtransactionoption((showmange)readoption());
 }
};