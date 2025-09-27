#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsFiles.h"
using namespace std;

class clsDeposit : public clsScreen
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
 public:
 static void Showdeposit()
 {
     showscreen("Deposit Screen");
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
   cout<<"Please Enter Deposit Amount : "; amount=clsInvalidate::Readintnumber("Invalid Number : ");
   cout<<"\nAre you sure you want to perform this transaction ? "; cin>>c;
   if(c=='y' || c=='Y')
  {
        svclient.at(id).balance=to_string(stoi(svclient.at(id).balance)+amount);
        cout<<"\nAmount Deposited Successfully :-) \n";
        system("color 2F");
        clsutil::colorgoback();
        cout<<"\nNew Balance Is : "<<svclient.at(id).balance;
        clsFiles::saveinfile(svclient,"clients.txt");      
    }
    else cout<<"\nYou Canceled Amount Deposited..\n";
 }
};