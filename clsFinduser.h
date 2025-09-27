#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsFinduser : public clsScreen
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
static void Finduser()
{
    string username;
    showscreen("Find User Screen");
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
}
};