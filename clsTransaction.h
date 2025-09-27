#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsDeposit.h"
#include "clsWithdraw.h"
#include "clsTotalbalance.h"
#include "clsTransfer.h"
#include "clsLogtransfer.h"
using namespace std;

class clsTransaction : public clsScreen
{
 private:
 enum showtrans {eDeposit=1,eWithdraw=2,eTotalbalance=3,eTransfer=4,eTransferLog=5,eMainmenu=6};
 static short readoption()
 { 
   clsutil::Taps(5); cout<<"Choose What do you want to do ? [1 to 6] : ";
   int option=clsInvalidate::Readintnumberbetween(1,6,"Enter Number From 1 To 6 : ");
   return option;
  }
  static void gobacktrans()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        Showtransaction();
    }
 static void performtransactionoption(showtrans option)
  {
   switch (option)
   {
       case showtrans::eDeposit :
       system("cls");
       clsDeposit::Showdeposit();      
       gobacktrans();
       break;
       case showtrans::eWithdraw :
       system("cls");
       clsWithdraw::Showwithdraw();      
       gobacktrans();
       break;
       case showtrans::eTotalbalance :
       system("cls");
       clsTotalbalance::Showtotalbalance();      
       gobacktrans();
       break;
       case showtrans::eTransfer :
       system("cls");
       clsTransfer::showtransfer();
       gobacktrans();
       break;
       case showtrans::eTransferLog :
       system("cls");
       clslogtransfer::showloginregister();
       gobacktrans();
       break;
       default:
       system("cls");
       clsutil::goback();
       break;
   }
   }
 public:
 static void Showtransaction()
 {
    system("cls");
    showscreen("Transaction Screen");
     clsutil::Taps(5); cout << "===========================================\n";
     clsutil::Taps(4); cout << "\t\t\tTransaction Menue\n";
     clsutil::Taps(5); cout << "===========================================\n";
     clsutil::Taps(6); cout << "[1] Deposit.\n";
     clsutil::Taps(6); cout << "[2] Withdraw.\n";
     clsutil::Taps(6); cout << "[3] Total Balances.\n";
     clsutil::Taps(6); cout << "[4] Transfer.\n";
     clsutil::Taps(6); cout << "[5] Transfer Log.\n";
     clsutil::Taps(6); cout << "[6] Main Menue.\n";
     clsutil::Taps(5); cout << "===========================================\n";
     performtransactionoption((showtrans)readoption());
 }
};