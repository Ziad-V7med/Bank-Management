#pragma once
#include <bits/stdc++.h>
#include "clsUtil.h"
using namespace std;

class clsUser
{
 private:
 string firstname,lastname,username,phone,email,password;  int permission;
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

static string join(clsUser data)
{
  return data.firstname+"#//#"+data.lastname+"#//#"+data.email+"#//#"+data.phone+"#//#"+
         data.username+"#//#"+clsutil::Encryption(data.password,1)+"#//#"+to_string(data.permission);
}
 public:
 void setFirstname(string fname) 
    {
        firstname = fname;
    }
    void setLastname(string lname) 
    {
        lastname = lname;
    }
    void setUsername(string uname) 
    {
        username = uname;
    }
    void setPhone(string ph) 
    {
        phone = ph;
    }
    void setEmail(string mail) 
    {
        email = mail;
    }
    void setPassword(string pass) 
    {
        password = pass;
    }
    void setPermission(int perm)
    {
        permission = perm;
    }
    string getFirstname() 
    {
        return firstname;
    }
    string getLastname() 
    {
        return lastname;
    }
    string getUsername()
    {
        return username;
    }
    string getPhone() 
    {
        return phone;
    }
    string getEmail()
    {
        return email;
    }
    string getPassword()
    {
        return password;
    }
    int getPermission()
    {
        return permission;
    }
    string getFullname()
    {
      return firstname+" "+lastname;
    }
  static clsUser getemptyuser()
    {
        return clsUser ("","","","","","",0);
    }
 clsUser (string fname,string lname,string em,string ph,string usname,string pass,int per)
 {
    firstname=fname;
    lastname=lname;
    username=usname;
    phone=ph;
    email=em;
    password=pass;
    permission=per;
 }

static void saveinfile(vector<clsUser>&sv,string namefile)
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
  static vector<clsUser>fulllist()
  {
     vector<string>vuser=fileinvector("users.txt");
     vector<clsUser>cvuser;
    for (int i = 0; i < vuser.size(); i++)
    {
      clsUser user=split(vuser.at(i));
      cvuser.push_back(user);
    }
    return cvuser;
  }

  static string finduser(string namefile,string username)
{
  fstream myfile;
   myfile.open(namefile,ios::in);
   if(myfile.is_open())
   {
       string line;
       while(getline(myfile,line))
       {
         if(line!="")
         {
             clsUser user=split(line);
             if(user.getUsername()==username)
             {
                 myfile.close();
                 return line;
             } 
         }
         
       }
       myfile.close();
   }
   return "";
}
  static string checkuser(string namefile,string username,string password)
{
  fstream myfile;
   myfile.open(namefile,ios::in);
   if(myfile.is_open())
   {
       string line;
       while(getline(myfile,line))
       {
         if(line!="")
         {
             clsUser user=split(line);
             if(user.getUsername()==username && user.getPassword()==password)
             {
                 myfile.close();
                 return line;
             } 
         }
         
       }
       myfile.close();
   }
   return "";
}
static bool Isexist(string username)
{
    return (finduser("users.txt",username)!="");
}
static bool Islogin(string username,string password)
{
    return (checkuser("users.txt",username,password)!="");
}
static void saveAddnewuser(string filename,clsUser user)
{
  fstream myfile;
  myfile.open(filename,ios::out | ios::app);
  if(myfile.is_open())
  {
    string line=join(user);
    myfile<<line<<endl;
  }
  myfile.close();
}
static void saveDeleteuser(string filename,vector<clsUser>cvuser,string username)
{
  fstream myfile;
  myfile.open(filename,ios::out);
  if(myfile.is_open())
  {
    for (int i = 0; i < cvuser.size(); i++)
    {
      if (cvuser.at(i).username!=username) myfile<<join(cvuser.at(i))<<endl;
    }
  }
  myfile.close();
}
static clsUser split(string record,string delim="#//#")
{
  vector<string>v2; int pos;
  while ((pos=record.find(delim))!=string::npos)
  {
    string word=record.substr(0,pos);
    v2.push_back(word);
    record.erase(0,pos+delim.size()); 
  }
  v2.push_back(record);
  return clsUser(v2.at(0),v2.at(1),v2.at(2),v2.at(3),v2.at(4),clsutil::Decryption(v2.at(5),1),stoi(v2.at(6)));
}
};
