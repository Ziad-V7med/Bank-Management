#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsFiles.h"
using namespace std;

class clsWithdraw : public clsScreen
{
 private:
 static void printclient(vector<Stclient>svclient,int id)
 {
        cout << "\nClient Card : ";
        cout << "\n________________________";
        cout << "\nFull Name   : " << svclient.at(id).name;
        cout << "\nEmail       : " << svclient.at(id).email;
        cout << "\nPhone       : " << svclient.at(id).phone;
        cout << "\nAcc. Number : " << svclient.at(id).account;
        cout << "\nPassword    : " << svclient.at(id).pincode;
        cout << "\nBalance     : " << svclient.at(id).balance;
        cout << "\n________________________\n\n";
 }
 static bool Iswithdraw(vector<Stclient>svclient,int id,int amount)
 {
   return amount<=stoi(svclient.at(id).balance);
 }
 public:
 static void Showwithdraw()
 {
    showscreen("Withdraw Screen");
    vector<Stclient>svclient=clsFiles::fulllist(); int id,amount; char c;
    do
   {
    cout<<"Please Enter Account Number : ";  string account=clsInvalidate::Readstring();
    id=clsFiles::indexclient(svclient,account);
    if(id==-1)
    {
      system("color 4F"); 
      cout<<"\nClient With ["<<account<<"] Not Found.\n";
      clsutil::colorgoback();
    }
    else break;
   } while (true);
   printclient(svclient,id);
   cout<<"Please Enter Withdraw Amount : "; amount=clsInvalidate::Readintnumber("Invalid Number : ");
   cout<<"\nAre you sure you want to perform this transaction ? "; cin>>c;
   if(c=='y' || c=='Y')
  {
      if(Iswithdraw(svclient,id,amount)) 
      {
          svclient.at(id).balance=to_string(stoi(svclient.at(id).balance)-amount);
          cout<<"\nAmount Withdraw Successfully :-) \n";
          system("color 2F");
          clsutil::colorgoback();
          cout<<"\nNew Balance Is : "<<svclient.at(id).balance;
          clsFiles::saveinfile(svclient,"clients.txt");      
      }
      else
      {
        cout<<"\nCannot Withdraw!!\n";
        cout<<"\nAmount to withdraw is : "<<amount;
        cout<<"\nYour Balance is       : "<<svclient.at(id).balance;
      }
    }
    else cout<<"\nYou Canceled Amount Withdraw..\n";
 }
};