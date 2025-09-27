#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsShowmenu.h"
#include "clsLogregister.h"

class clslogout : public clsScreen
{

  static void login()
  {
       int trials = 3;
    do
    {
        cout<<"Enter Username : "; string username=clsInvalidate::Readstring();
        cout<<"Enter Password : "; string password=clsInvalidate::Readstring();
        if(!(clsUser::Islogin(username,password)))
        {
            system("color 4F"); 
            cout<<"\nInvalid Username/password!\n";
            cout<<"You have "<<--trials<<" Trials to login.\n";
            clsutil::colorgoback();
            if(!trials)
            {
                cout<<"\nYou have locked After 3 failed trials.";
                play = OFF;
                return;
            }
        }
        else 
        {
            system("color 2F"); 
            cout<<"\nUsername and Password Are Correct :-)\n";
            clsutil::colorgoback();
            Currentuser = clsUser::split(clsUser::checkuser("users.txt",username,password));
            clsregister::Addinlogfile("logFile.txt");
            break;
        }
    } while (true);

    while (LOGIN) clsMainscreen::showmainscreen();
  }
  public:
  static void Showlogin()
  {
    system("cls");
    showscreen("Login Screen");
    LOGIN=YES;
    login();
  }
};