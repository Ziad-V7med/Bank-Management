#pragma once
#include <bits/stdc++.h>
#include "clsFiles.h"
#include "clsScreen.h"
#include "clsInvalidate.h"
using namespace std;

class clsUpdateclient : public clsScreen
{
private:
static void Readclient(vector<Stclient>&svclient,int id)
{
    cout<<"\n Update Client Info.\n";
    cout<<"----------------------------\n";
    cout<<"Enter FullName    : ";  cin.ignore(1,'\n'); getline(cin,svclient.at(id).name);
    cout<<"Email             : ";  cin>>svclient.at(id).email;
    cout<<"Phone Number      : ";  cin>>svclient.at(id).phone;
    cout<<"Password          : ";  cin>>svclient.at(id).pincode;
    cout<<"Balance           : ";  cin>>svclient.at(id).balance;
}
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
 static void Updateclient()
 {
    vector<Stclient>svclient=clsFiles::fulllist(); int id; char c;
    showscreen("Update Client Screen");
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
  Readclient(svclient,id);
  cout<<"Are you Sure To Update Client ? (y - n) " ; cin>>c;
  if(c=='y' || c=='Y')
  {
        cout<<"Client Updated Successfully :-) \n";
        system("color 2F");
        clsutil::colorgoback();
        Printclient(svclient,id);
        clsFiles::saveinfile(svclient,"clients.txt");      
    }
    else cout<<"You Canceled Update Client..\n";
 }
 
};