#include <bits/stdc++.h>
#include "clsInvalidate.h"
using namespace std;

class clsAddclient : public clsScreen
{
 private:
 static Stclient newclient;
 static void Readclientinfo(vector<Stclient>&svclient,string account)
 {
    cout<<"\nEnter FullName    : ";  cin.ignore(1,'\n'); getline(cin,newclient.name);
    cout<<"Email             : ";  cin>>newclient.email;
    cout<<"Phone Number      : ";  cin>>newclient.phone;
    cout<<"Password          : ";  cin>>newclient.pincode;
    cout<<"Balance           : ";  cin>>newclient.balance;
    newclient.account=account;
 }
 static void Printclient()
 {
        cout << "\nClient Card : ";
        cout << "\n________________________";
        cout << "\nFull Name   : " << newclient.name;
        cout << "\nEmail       : " << newclient.email;
        cout << "\nPhone       : " << newclient.phone;
        cout << "\nAcc. Number : " << newclient.account;
        cout << "\nPassword    : " << newclient.pincode;
        cout << "\nBalance     : " << newclient.balance;
        cout << "\n________________________\n";
 }
 public:
 static void Addnewclient()
 {
   string account; int id; char c;
   vector<Stclient>svclient=clsFiles::fulllist();
   showscreen("Add New Client Screen");
  do
  {
    cout<<"Please Enter Account Number : "; cin>>account;
    id=clsFiles::indexclient(svclient,account);
    if(id!=-1)
    {
      system("color 4F"); 
      cout<<"Account Number Is Arleady Used\n";
      clsutil::colorgoback();
    }
    else break;
  } while (true);
  
  Readclientinfo(svclient,account);
  cout<<"Are you Sure To Add Client ? (y - n) " ; cin>>c;
  if(c=='y' || c=='Y')
  {
        cout<<"Client Added Successfully :-) \n";
        svclient.push_back(newclient);
        system("color 2F");
        clsutil::colorgoback();
        clsFiles::saveinfile(svclient,"clients.txt");
        Printclient();
  }
  else  cout<<"You Canceled Add Client..\n";
 }
};
Stclient clsAddclient::newclient;
