#pragma once
#include <bits/stdc++.h>
using namespace std;

class clsutil
{
public:
    enum Character {capital=1,small,digit,symbol,mix};
    struct date
    {
      int day,month,year;
    };
clsutil(int day,int month,int year)
{
 date history;
 history.day=day; history.month=month; history.year=year;
}
static void Srand()
{
 srand((unsigned)time(NULL));
}
static int Getrandom(int from,int to)
{
  return rand()%(to-from+1)+from;
}
static char Getcharrandom(Character ch)
{
  switch (ch)
  {
  case Character::capital :
  return (char)Getrandom('A','Z');
  case Character::small :
  return (char)Getrandom('a','z');
  case Character::digit :
  return (char)Getrandom('0','9');
  case Character::symbol :
  return (char)Getrandom(33,47);
  default:
  ch=(Character)Getrandom(1,4);
  return Getcharrandom(ch);
  }
}
static string Generateword(Character ch,int length)
{
  string word="";
  for (int i = 0; i < length; i++) word+=Getcharrandom(ch);
  return word; 
}
static string Generatekey(Character ch)
{
  return Generateword(ch,4)+"-"+Generateword(ch,4)+"-"+Generateword(ch,4)+"-"+Generateword(ch,4);
}
static void Generatekeys(Character ch,int line)
{
  for (int i = 1; i <= line; i++)
  {
    cout<<"Key ["<<i<<"] : "<<Generatekey(ch)<<'\n';
  }
}
static void Swap(int &num1,int &num2)
{
  int temp=num1;
  num1=num2;
  num2=temp;
}
static void Swap(double &num1,double &num2)
{
  double temp=num1;
  num1=num2;
  num2=temp;
}
static void Swap(string &s1,string &s2)
{
  string temp=s1;
  s1=s2;
  s2=temp;
}
static void Swap(date &his1,date &his2)
{
  date temp;
  temp.day=his1.day; temp.month=his1.month; temp.year=his1.year;
  his1.day=his2.day; his1.month=his2.month; his1.year=his2.year;
  his2.day=temp.day; his2.month=temp.month; his2.year=temp.year;
}
string Datetostring(date his)
{
  return to_string(his.day)+"/"+to_string(his.month)+"/"+to_string(his.year);
}
static void Shufflearray(int arr[],int size)
{
  for (int i = size-1; i >= 0; i--)
  {
    int j=Getrandom(0,i);
    Swap(arr[i],arr[j]);
  }
  for  (int i = 0;i < size; i++) cout<<arr[i]<<" ";
  cout<<"\n";
}
static void Shufflearray(string arr[],int size)
{
  for (int i = size-1; i >= 0; i--)
  {
    int j=Getrandom(0,i);
    Swap(arr[i],arr[j]);
  }
  for  (int i = 0;i < size; i++) cout<<arr[i]<<" ";
  cout<<"\n";
}
static void Fillarraywithnumber(int arr[],int size,int from,int to)
{
  for  (int i = 0;i < size; i++)
  arr[i]=Getrandom(from,to);
  for  (int i = 0;i < size; i++) cout<<arr[i]<<" ";
  cout<<"\n";
}
static void Fillarraywithword(string arr[],int size,Character ch,int length)
{
  for  (int i = 0;i < size; i++)
  arr[i]=Generateword(ch,length);
  for  (int i = 0;i < size; i++) cout<<arr[i]<<" ";
  cout<<"\n";
}
static void Fillarraywithkey(string arr[],int size,Character ch)
{
  for  (int i = 0;i < size; i++)
  arr[i]=Generatekey(ch);
  for  (int i = 0;i < size; i++) cout<<arr[i]<<"\n";
}
static void Taps(int times)
{
   for  (int i = 0;i < times; i++) cout<<'\t';
}
static string Encryption(string text,int key)
{
   for (int i = 0; i < text.size(); i++)  text[i]+=key;
   return text;
}
static string Decryption(string text,int key)
{
   for (int i = 0; i < text.size(); i++)  text[i]-=key;
   return text;
}
static void goback()
  {
  cout<<setw(37)<<left<<"Press any key to go back main menue...";
  system("pause>0");
  }
  static void colorgoback()
{
	cout<<"Press any key to Continue...\n";
  system("pause>0");
	system("color 0F");
	cout<<'\n';
}
};
