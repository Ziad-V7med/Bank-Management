#pragma once
#include <bits/stdc++.h>
#include "clsDate.h"
using namespace std;

class clsInvalidate
{
public:
static bool isnumberbetween(int val,int from,int to)
{
  return (val>=from && val<=to);
}
static bool isnumberbetween(double val,double from,double to)
{
  return (val>=from && val<=to);
}
static bool isdatebetween(clsDate dval,clsDate dfrom,clsDate dto)
{
  if (dto.dateisbefore(dto,dfrom))
  return (dval.dateisafter(dval,dto) && dval.dateisbefore(dval,dfrom) );
  return (dval.dateisafter(dval,dfrom) && dval.dateisbefore(dval,dto) );
}
static int Readintnumber(string Errormessage)
	{
		int Number;
		while (!(cin >> Number))
    {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Errormessage ;
    }
		return Number;
	}
static int Readpositiveintnumber()
{
	int number;
	do
	{
	  cout<<"Enter Positive Number : ";
	  number=Readintnumber("Invalid Number ");
	} while (number<=0);
	return number;		
}
static double Readdoublenumber(string Errormessage)
	{
		double Number;
		while (!(cin >> Number))
    {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Errormessage ;
		}
		return Number;
	}
static int Readintnumberbetween(int from,int to,string message)
{
	int number;
	do
	{
	 number = Readintnumber("Invalid Number\n");
	 if(isnumberbetween(number,from,to)) break;
	 else                                cout<<message;
    } while (true);
    return number;
}
static int Readdoublenumberbetween(double from,double to,string message)
{
  double number = Readintnumber("Invalid Number\n");
  if(!(isnumberbetween(number,from,to))) cout<<message<<endl;
  return number;
}
static bool Isvaliddate(clsDate his)
{
  return (!his.Isinvalid(his));
}
static string Readstring()
{
	string text; cin>>text;
	return text;
}
static string Fullname(string fname,string lname)
{
	return fname+" "+lname;
}

};
