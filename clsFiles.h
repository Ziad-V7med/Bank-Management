#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
using namespace std;

struct Stclient
{
    string account,name,pincode,phone,email,balance;
};
class clsFiles
{
 public:

static vector<string> fileinvector(string namefile)
{
   fstream myfile; vector<string>v1;
   myfile.open(namefile,ios::in);
   if(myfile.is_open())
   {
       string line;
       while(getline(myfile,line))
           if(line!="")
           v1.push_back(line);
   }
   myfile.close();
   return v1;
}
static vector<string> split(string record,string delim="#//#")
{
  vector<string>v2; int pos;
  while ((pos=record.find(delim))!=string::npos)
  {
    string word=record.substr(0,pos);
    v2.push_back(word);
    record.erase(0,pos+delim.size()); 
  }
  v2.push_back(record);
  return v2;
}
static Stclient detailclients(vector<string>v2)
{
  Stclient client;
  client.name=v2.at(0);
  client.email=v2.at(1);
  client.phone   =v2.at(2);
  client.account  =v2.at(3);
  client.pincode=clsutil::Decryption(v2.at(4),1);
  client.balance=v2.at(5);
  return client;
}
static string join(Stclient data)
{
  return data.name+"#//#"+data.email+"#//#"+data.phone+"#//#"+data.account+"#//#"+clsutil::Encryption(data.pincode,1)+"#//#"+data.balance;
}
static void saveinfile(vector<Stclient>&sv,string namefile)
{
   fstream myfile; 
   myfile.open(namefile,ios::out);
   if(myfile.is_open())
   {
    for (int i = 0; i < sv.size(); i++)
    {
      string record=join(sv[i]);
      myfile<<record<<endl;
    }
   }
   myfile.close();
}
static vector<Stclient> dataofclients(Stclient client)
{
  vector<Stclient>svclient;
  svclient.push_back(client);
  return svclient;
}
  static vector<Stclient> fulllist()
  {
     vector<string>vclient=fileinvector("clients.txt");
     vector<Stclient>svclient;
    for (int i = 0; i < vclient.size(); i++)
    {
      Stclient client=detailclients(split(vclient.at(i)));
      svclient.push_back(client);
    }
    return svclient;
  }

static int indexclient(vector<Stclient>svclient,string account)
{
  int id=-1;
  for (int i = 0; i < svclient.size(); i++)
  {
    if(svclient.at(i).account==account) return i;
  }
  return id;
}
};
