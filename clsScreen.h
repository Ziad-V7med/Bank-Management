#pragma once
#include <bits/stdc++.h>
#include "clsUtil.h"
#include "clsInvalidate.h"
#include "clsGlopal.h"
using namespace std;

class clsScreen
{
  protected:
 static void showscreen(string header,string subheader="")

 {
   clsutil::Taps(5); cout<<"-------------------------------------------\n";
   clsutil::Taps(7); cout<<header<<'\n';
   if(subheader!="")
   {
      clsutil::Taps(7); cout<<" "<<subheader<<'\n';
   }
   clsutil::Taps(5); cout<<"-------------------------------------------\n\n";
   clsutil::Taps(5); cout<<"User : "<<Currentuser.getUsername()<<endl;
   clsDate nowdate;
   clsutil::Taps(5); cout<<"Date : "<<nowdate.printdate()<<"\n\n";
 }
};