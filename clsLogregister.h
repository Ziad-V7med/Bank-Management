#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"

class clsregister : public clsScreen
{
  private:
  struct rigsterrecord
  {
    string history,username,fullname,password,permission;
  };
  static string join()
  {
     clsDate log;
     return log.printdate()+" - "+log.printtime()+"#//#"+Currentuser.getUsername()+"#//#"+Currentuser.getFullname()+
             +"#//#"+Currentuser.getPassword()+"#//#"+to_string(Currentuser.getPermission());
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
  static vector<rigsterrecord> split (string delim="#//#")
  {
      vector<string>vlogs=readfile("logFile.txt");
      vector<rigsterrecord>Stlogs;
      rigsterrecord logs;
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
            logs.username=v2.at(1);
            logs.fullname=v2.at(2);
            logs.password=v2.at(3);
            logs.permission=v2.at(4);
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
    vector<rigsterrecord>Stlogs=split();
    string subheader="("+to_string(Stlogs.size())+") Records(s).";
    showscreen("Login Register List Screen",subheader);
    cout<<'\n'; clsutil::Taps(3);
    cout<<"-----------------------------------------------------------------------------------\n";
    clsutil::Taps(3);
    cout<<"| "<<setw(25)<<left<<"Date/Time"
    <<"| "<<setw(10)<<left<<"User Name"
    <<"| "<<setw(15)<<left<<"Full Name"
    <<"| "<<setw(10)<<left<<"Password"
    <<"| "<<setw(4)<<left<<"Permission";
    cout<<'\n'; clsutil::Taps(3);
    cout<<"-----------------------------------------------------------------------------------\n";
    for (int i = 0; i < Stlogs.size(); i++)
    {
    clsutil::Taps(3); 
    cout<<"| "<<setw(25)<<left<<Stlogs.at(i).history
    <<"| "<<setw(10)<<left<<Stlogs.at(i).username
    <<"| "<<setw(15)<<left<<Stlogs.at(i).fullname
    <<"| "<<setw(10)<<left<<Stlogs.at(i).password
    <<"| "<<setw(4)<<left<<Stlogs.at(i).permission<<endl;
    }
    clsutil::Taps(3);
    cout<<"-----------------------------------------------------------------------------------\n";
  }
};