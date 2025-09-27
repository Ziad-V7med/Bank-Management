#pragma once
#include <bits/stdc++.h>
#include "clsFiles.h"
#include "clsScreen.h"
#include "clsInvalidate.h"
using namespace std;

class clsFindclient : public clsScreen
{
private:
static void Printclient(vector<Stclient>svclient,int id)
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
 static void Findclient()
 {
    vector<Stclient>svclient=clsFiles::fulllist(); int id; 
    showscreen("Find Client Screen");
   do
   {
    cout<<"Please Enter Account Number : ";  string account=clsInvalidate::Readstring();
    id=clsFiles::indexclient(svclient,account);
    if(id==-1)
    {
      system("color 4F"); 
      cout<<"Account Number Is Not Found\n";
      clsutil::colorgoback();
    }
    else break;
  } while (true);
  cout<<"\nClient Found :-)\n\n";
  system("color 2F");
  clsutil::colorgoback();
  Printclient(svclient,id);
  clsFiles::saveinfile(svclient,"clients.txt");      
 }
};