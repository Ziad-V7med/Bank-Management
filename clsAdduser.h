#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsAdduser : public clsScreen
{
private:
static void sum(int &sum_per,char c,int op)
{
    if (c=='y' || c=='Y') sum_per+=pow(2,op);
}
static int permission()
{    
    char c; int sum_per{};
    cout<<"\nDo you want to give full access ? y/n "; cin>>c;
    if(c=='y' || c=='Y') return -1;
    else 
    {
     cout<<"\nDo you want to give access to : \n"; 
     cout<<"\nShow Client list y/n : "; cin>>c; sum(sum_per,c,0);
     cout<<"\nAdd New Client   y/n : "; cin>>c; sum(sum_per,c,1);
     cout<<"\nDelete Client    y/n : "; cin>>c; sum(sum_per,c,2);
     cout<<"\nUpdate Client    y/n : "; cin>>c; sum(sum_per,c,3);
     cout<<"\nFind Client      y/n : "; cin>>c; sum(sum_per,c,4);
     cout<<"\nTransaction      y/n : "; cin>>c; sum(sum_per,c,5);
     cout<<"\nMange Users      y/n : "; cin>>c; sum(sum_per,c,6);
    }
    if(sum_per==127) return -1;
    return sum_per;
}
static void Readuser(clsUser &user,string username)
{
  cout<<"\nEnter FirstName  : "; user.setFirstname(clsInvalidate::Readstring());
  cout<<"\nEnter LastName   : "; user.setLastname(clsInvalidate::Readstring());
  cout<<"\nEnter Email      : "; user.setEmail(clsInvalidate::Readstring());
  cout<<"\nEnter Phone      : "; user.setPhone(clsInvalidate::Readstring());
  cout<<"\nEnter Password   : "; user.setPassword(clsInvalidate::Readstring());
  cout<<"\nEnter Permission : "; user.setPermission(permission());
  user.setUsername(username);
}
static void Printuser(clsUser user)
 {
        cout << "\nClient Card : ";
        cout << "\n________________________";
        cout << "\nFull Name      : " << user.getFullname();
        cout << "\nEmail          : " << user.getEmail();
        cout << "\nPhone          : " << user.getPhone();
        cout << "\nUser Name      : " << user.getUsername();
        cout << "\nPassword       : " << user.getPassword();
        cout << "\nPermission     : " << user.getPermission();
        cout << "\n________________________\n";
 }
public:
static void Adduser()
{
    string username; char c;
    showscreen("Add New User Screen");
    do
    {
      cout<<"Please Enter Username : ";  username=clsInvalidate::Readstring();
      if(clsUser::Isexist(username))
      {
        system("color 4F"); 
        cout<<"\nUsername is already used Choose another one :-) ";
        clsutil::colorgoback();
      }
      else break;
    } while (true);
    clsUser user=clsUser::getemptyuser();
    Readuser(user,username);
    cout<<"\nAre you Sure To Add User ? (y - n) " ; cin>>c;
    if(c=='y' || c=='Y')
    {
        cout<<"\nUser Added Successfully :-) \n";
        clsUser::saveAddnewuser("users.txt",user);
        system("color 2F");
        clsutil::colorgoback();
     }
    else  cout<<"\nYou Canceled Add User..\n";
    Printuser(user);
    
}
};