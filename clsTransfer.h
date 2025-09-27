#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsFiles.h"
#include "clsGlopal.h"
#include "clsLogtransfer.h"

vector<Stclient>svclient=clsFiles::fulllist(); 

class clsTransfer : public clsScreen
{
private:
static void printclient(int id)
{
    cout<<"\nClient card : \n";
    cout<<"----------------------\n";
    cout<<"Full Name   : "<<svclient.at(id).name<<"\n";
    cout<<"Acc. Number : "<<svclient.at(id).account<<"\n";
    cout<<"Balance     : "<<svclient.at(id).balance<<"\n";
    cout<<"----------------------\n";
}
static bool Istransfer()
{
   return stoi(svclient.at(client1).balance)>=amount;
}
static void opertionoftransfer()
{
   do
   {
      cout<<"\nEnter Transfer Amount : ";  amount=clsInvalidate::Readintnumber("Invalid Number ");
      if(!(Istransfer()))
      {
          system("color 4F"); 
          cout<<"Amount Exceeds the available Balance! \n";
          clsutil::colorgoback();
      }
      else break;
   } while (true);
   cout<<"Are You Transfer "<<amount<<" To "<<svclient.at(client2).name<<" ? Y/N "; char c; cin>>c;
   if(c=='y' || c=='Y')
   {
       cout<<"\nTransfer Done Successfully..\n";
       system("color 2F");
       clsutil::colorgoback();
       svclient.at(client1).balance=to_string(stoi(svclient.at(client1).balance)-amount);
       svclient.at(client2).balance=to_string(stoi(svclient.at(client2).balance)+amount);
       clsFiles::saveinfile(svclient,"clients.txt");
       clslogtransfer::Addinlogfile("logTransfer.txt");
   }
   else
   {
        cout<<"\nYou Canceled Transfered!!\n";
        system("color 4F"); 
        clsutil::colorgoback();
   }
}
public:
static void showtransfer()
{
    for (int i = 1; i <= 2; i++)
    {
        int id;
         do
       {
          cout<<"\nPlease Enter Account Number To Transfer From : ";  string account=clsInvalidate::Readstring();
          id=clsFiles::indexclient(svclient,account);
          if(id==-1)
            {
                 system("color 4F"); 
                 cout<<"Account Number Is Not Found\n";
                 clsutil::colorgoback();
            }
           else break;
       } while (true);
       if(i==1) client1=id;
       else     client2=id;
       printclient(id);
    }
    opertionoftransfer();
    printclient(client1);
    printclient(client2);
}
};