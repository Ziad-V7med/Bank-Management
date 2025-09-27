#pragma once
#include <bits/stdc++.h>
#include "clsFiles.h"
#include "clsScreen.h"
#include "clsInvalidate.h"
using namespace std;

class clsDeleteclient : public clsScreen
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
static void Printemptyclient()
 {
        cout << "\nClient Card : ";
        cout << "\n________________________";
        cout << "\nFull Name   : ";
        cout << "\nEmail       : ";
        cout << "\nPhone       : ";
        cout << "\nAcc. Number : ";
        cout << "\nPassword    : ";
        cout << "\nBalance     : " << 0;
        cout << "\n________________________\n\n";
 }
 public:
 static void Deleteclient()
 {
   vector<Stclient>svclient=clsFiles::fulllist(); int id; char c;
   showscreen("Delete Client Screen");
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
  
  Printclient(svclient,id);

  cout<<"Are you Sure To Delete Client ? (y - n) " ; cin>>c;
  if(c=='y' || c=='Y')
  {
        cout<<"Client Deleted Successfully :-) \n";
        svclient.erase(svclient.begin()+id);
        system("color 2F");
        clsutil::colorgoback();
        Printemptyclient();
        clsFiles::saveinfile(svclient,"clients.txt");      
    }
    else cout<<"You Canceled Delete Client..\n";
 }
};

