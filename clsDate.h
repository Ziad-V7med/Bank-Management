#pragma once
#pragma warning(disable : 4996)
#include <bits/stdc++.h>
using namespace std;

class clsDate
{
private:
struct date
{
    int day,month,year;
}his;
public:
clsDate()
{
 time_t t = time(0); 
 tm* now = localtime(&t); 
 his.day=now->tm_mday;
 his.month=now->tm_mon + 1;
 his.year=now->tm_year + 1900;
}
clsDate(int day,int month,int year)
{ 
 his.day=day; his.month=month; his.year=year;
}
int Getday()
{
    return his.day;
}
int Getmonth()
{
    return his.month;
}
int Getyear()
{
    return his.year;
}
date Gethistory()
{
  return his;
}
string printdate()
{
   return to_string(Getday())+"/"+to_string(Getmonth())+"/"+to_string(Getyear());
}
string printtime()
{
    time_t t = time(0); 
    tm* now = localtime(&t); 
    return to_string(now->tm_hour)+":"+to_string(now->tm_min)+":"+to_string(now->tm_sec);
}
bool dateisbefore(clsDate his1,clsDate his2)
{
 return ((his1.Getyear()<his2.Getyear())||
 (his1.Getyear()==his2.Getyear() && his1.Getmonth()<his2.Getmonth())||
 (his1.Getyear()==his2.Getyear() && his1.Getmonth()==his2.Getmonth() && his1.Getday()<his2.Getday()));
}
bool dateisafter(clsDate his1,clsDate his2)
{
    return (!dateisbefore(his1,his2));
}
bool Isleap(clsDate his)
{
  return ((his.Getyear()%4==0 && his.Getyear()%100!=0) || his.Getyear()%400==0);
}
int numberofdaysinmonth(clsDate his)
{
 vector<int>month={0,31,28,31,30,31,30,31,31,30,31,30,31};
 return (his.Getmonth()==2)? (Isleap(his)? 29:28) : month.at(his.Getmonth());
}
bool Isinvalid(clsDate his)
{
 if(his.Getyear()<1) return true;
 if(his.Getmonth()<1 || his.Getmonth()>12 ) return true;
 if(his.Getday()<1 || his.Getday()>31 )     return true;
 if(numberofdaysinmonth(his)<his.Getday())  return true;
 return false;
}
};