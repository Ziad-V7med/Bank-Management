#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsDeleteuser : public clsScreen
{
private:
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
static void Deleteuser()
{
    string username; char c; vector<clsUser>cvuser=clsUser::fulllist();
    showscreen("Delete User Screen");
    do
    {
      cout<<"Please Enter Username : ";  username=clsInvalidate::Readstring();
      if(!(clsUser::Isexist(username)))
      {
        system("color 4F"); 
        cout<<"\nUsername is Not Found Choose Another One :-) ";
        clsutil::colorgoback();
      }
      else break;
    } while (true);
    clsUser user = clsUser::split(clsUser::finduser("users.txt",username));
    Printuser(user);
    cout<<"\nAre you Sure To Delete User ? (y - n) " ; cin>>c;
    if(c=='y' || c=='Y')
    {
        cout<<"\nUser Deleted Successfully :-) \n";
        clsUser::saveDeleteuser("users.txt",cvuser,username);
        system("color 2F");
        clsutil::colorgoback();
     }
    else  cout<<"\nYou Canceled Delete User..\n";
    
    
}
};