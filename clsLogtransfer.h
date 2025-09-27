#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsFiles.h"

class clslogtransfer : public clsScreen
{
  private:
   struct logtrans
  {
    string history,AccountClient1,AccountClient2,amount,balanceClient1,balanceClient2,username;
  };
  static string join()
  {
     clsDate log; vector<Stclient>svclient=clsFiles::fulllist(); 
     return log.printdate()+" - "+log.printtime()+"#//#"+svclient.at(client1).account+"#//#"+
     svclient.at(client2).account+"#//#"+to_string(amount)+"#//#"+svclient.at(client1).balance+"#//#"+
     svclient.at(client2).balance+"#//#"+Currentuser.getUsername();
  }
  static vector<string> readfile(string filename)
  {
     vector<string>vlogs; fstream myfile; myfile.open(filename,ios::in);
    if(myfile.is_open()) 
    {
       string line;
       if(myfile.is_open())
      {
           while (getline(myfile,line))  if (line!="") vlogs.push_back(line);
           myfile.close();
      }
    }
    return vlogs;
  }
  static vector<logtrans> split (string delim="#//#")
  {
      vector<string>vlogs=readfile("logTransfer.txt");
      vector<logtrans>Stlogs;
      logtrans logs;
      for (int i = 0; i < vlogs.size(); i++)
      {
        vector<string>v2; int pos;
        while ((pos=vlogs.at(i).find(delim))!=string::npos)
      {
           string word=vlogs.at(i).substr(0,pos);
           v2.push_back(word);
           vlogs.at(i).erase(0,pos+delim.size()); 
      }
            v2.push_back(vlogs.at(i));
            logs.history=v2.at(0);
            logs.AccountClient1=v2.at(1);
            logs.AccountClient2=v2.at(2);
            logs.amount=v2.at(3);
            logs.balanceClient1=v2.at(4);
            logs.balanceClient2=v2.at(5);
            logs.username=v2.at(6);
            Stlogs.push_back(logs);
      }
      return Stlogs;
  }
  public:
  static void Addinlogfile(string filename)
  {
    fstream myfile; myfile.open(filename,ios::out | ios::app);
    if(myfile.is_open())   myfile<<join()<<endl;
    myfile.close();
  }
  static void showloginregister()
  {
    vector<logtrans>Stlogs=split();
    string subheader="("+to_string(Stlogs.size())+") Records(s).";
    showscreen("Transfer Log List Screen",subheader);
    cout<<'\n'; clsutil::Taps(3);
    cout<<"---------------------------------------------------------------------------------------------------------\n";
    clsutil::Taps(3);
    cout<<"| "<<setw(25)<<left<<"Date/Time"
    <<"| "<<setw(10)<<left<<"s.Acct"
    <<"| "<<setw(10)<<left<<"d.Acct"
    <<"| "<<setw(12)<<left<<"Amount"
    <<"| "<<setw(12)<<left<<"s.Balance"
    <<"| "<<setw(12)<<left<<"d.Balance"
    <<"| "<<setw(10)<<left<<"Username";
    cout<<'\n'; clsutil::Taps(3);
    cout<<"---------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < Stlogs.size(); i++)
    {
    clsutil::Taps(3); 
    cout<<"| "<<setw(25)<<left<<Stlogs.at(i).history
    <<"| "<<setw(10)<<left<<Stlogs.at(i).AccountClient1
    <<"| "<<setw(10)<<left<<Stlogs.at(i).AccountClient2
    <<"| "<<setw(12)<<left<<Stlogs.at(i).amount
    <<"| "<<setw(12)<<left<<Stlogs.at(i).balanceClient1
    <<"| "<<setw(12)<<left<<Stlogs.at(i).balanceClient2
    <<"| "<<setw(10)<<left<<Stlogs.at(i).username<<endl;
    }
    clsutil::Taps(3);
    cout<<"---------------------------------------------------------------------------------------------------------\n";
  }
};