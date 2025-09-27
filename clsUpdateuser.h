#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsUpdateuser : public clsScreen
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
     cout<<"\nShow Client list    y/n : "; cin>>c; sum(sum_per,c,0);
     cout<<"\nAdd New Client      y/n : "; cin>>c; sum(sum_per,c,1);
     cout<<"\nDelete Client       y/n : "; cin>>c; sum(sum_per,c,2);
     cout<<"\nUpdate Client       y/n : "; cin>>c; sum(sum_per,c,3);
     cout<<"\nFind Client         y/n : "; cin>>c; sum(sum_per,c,4);
     cout<<"\nTransaction         y/n : "; cin>>c; sum(sum_per,c,5);
     cout<<"\nMange Users         y/n : "; cin>>c; sum(sum_per,c,6);
     cout<<"\nLogin Register      y/n : "; cin>>c; sum(sum_per,c,7);
     cout<<"\nCurrency Exchange   y/n : "; cin>>c; sum(sum_per,c,8);
    }
    if(sum_per==511) return -1;
    return sum_per;
}
static int Readuser( vector<clsUser>&cvuser,string username)
{
    for (int i = 0; i < cvuser.size(); i++)
    {
       if(cvuser.at(i).getUsername()==username)
       {
            cout<<"\nEnter FirstName  : "; cvuser.at(i).setFirstname(clsInvalidate::Readstring());
            cout<<"\nEnter LastName   : "; cvuser.at(i).setLastname(clsInvalidate::Readstring());
            cout<<"\nEnter Email      : "; cvuser.at(i).setEmail(clsInvalidate::Readstring());
            cout<<"\nEnter Phone      : "; cvuser.at(i).setPhone(clsInvalidate::Readstring());
            cout<<"\nEnter Password   : "; cvuser.at(i).setPassword(clsInvalidate::Readstring());
            cout<<"\nEnter Permission : "; cvuser.at(i).setPermission(permission());
            cvuser.at(i).setUsername(username);
            return i;
       }
    }
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
static void Updateuser()
{
    string username; char c; vector<clsUser>cvuser=clsUser::fulllist();
    showscreen("Update User Screen");
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
    cout<<"\nAre you Sure To Update User ? (y - n) " ; cin>>c;
    if(c=='y' || c=='Y')
    {
        int id=Readuser(cvuser,username);
        cout<<"\nUser Updated Successfully :-) \n";
        clsUser::saveinfile(cvuser,"users.txt");
        system("color 2F");
        Printuser(cvuser.at(id));
        clsutil::colorgoback();
     }
    else  cout<<"\nYou Canceled Update User..\n";
}
};