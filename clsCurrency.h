#pragma once
#include <bits/stdc++.h>
using namespace std;

class clsCurrency
{
private:
    string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;
static vector<string> Readfile(string namefile)
{
    fstream myfile; myfile.open(namefile,ios::in);
    vector<string>vCountries;
    if(myfile.is_open())
    {
        string country;
        while (getline(myfile,country)) if (country!="") vCountries.push_back(country);
    }
    myfile.close();
    return vCountries;
}
static string join(clsCurrency cur,string separetor="#//#")
{
    return cur._Country+separetor+cur._CurrencyCode+separetor+cur._CurrencyName+separetor+to_string(cur._Rate);
}
static clsCurrency split(string record,string delim="#//#")
{
  vector<string>v2; int pos;
  while ((pos=record.find(delim))!=string::npos)
  {
    string word=record.substr(0,pos);
    v2.push_back(word);
    record.erase(0,pos+delim.size()); 
  }
  v2.push_back(record);
  return clsCurrency(v2.at(0),v2.at(1),v2.at(2),stof(v2.at(3)));
}
static void saveinfile(vector<clsCurrency> svcountries,string namefile)
{
    fstream myfile; myfile.open(namefile,ios::out);
    if(myfile.is_open())  for(auto &it : svcountries) myfile<<join(it)<<endl;
    myfile.close();
}
static string UpperCase(string text)
{
    for(auto &it:text) it=toupper(it);
    return text;
}
public:
clsCurrency(string Country,string CurrencyCode,string CurrencyName,float Rate)
	{
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
	}
    void setRate(float rate)
    {
        _Rate = rate;
    }
    string Country()
    {
        return _Country;
    }
    
    string CurrencyCode()
    {
        return _CurrencyCode;
    }
    
    string CurrencyName()
    {
        return _CurrencyName;
    }
    float Rate()
    {
        return _Rate;
    }
    static vector<clsCurrency> Fullfile()
    {
      vector<string>vcountries = Readfile("Currencies.txt");
      vector<clsCurrency> svcountries;
      for (auto &it : vcountries) svcountries.push_back(split(it));
      return svcountries;
    }
static clsCurrency findcountry(string country)
{
    fstream myfile; myfile.open("Currencies.txt",ios::in);
    if(myfile.is_open())
    {
        string line;
     while (getline(myfile,line))
     {
        if (line!="")
        {
            clsCurrency cur = split (line);
           if(UpperCase(cur._Country)==UpperCase(country)) 
           {
               myfile.close();
               return cur;
           }
        }
     }  
     myfile.close();
    }
    return clsCurrency ("0","0","0",0);
}
static clsCurrency findcurrencycode(string curcode)
{
    fstream myfile; myfile.open("Currencies.txt",ios::in);
    if(myfile.is_open())
    {
        string line;
     while (getline(myfile,line))
     {
        if (line!="")
        {
            clsCurrency cur = split (line);
           if(UpperCase(cur._CurrencyCode)==UpperCase(curcode))
           {
               myfile.close();
               return cur;
           }
        }
     }  
     myfile.close();
     return clsCurrency ("0","0","0",0);
    }
}
void printcountry()
{
    cout<<"\nCurrency Card : \n";
    cout<<"_____________________________\n";
    cout<<"Country  : "<<Country()<<'\n';
    cout<<"Code     : "<<CurrencyCode()<<'\n';
    cout<<"Name     : "<<CurrencyName()<<'\n';
    cout<<"Rate(1$) : "<<Rate()<<'\n';
    cout<<"_____________________________\n";

}
bool IsEmptyCurrency()
{
    return Country() == "0";
}
void update(float rate)
{
    vector<clsCurrency>svcountries = Fullfile();
    for (auto &it : svcountries)
    {
        if (it._Country==Country()) 
        {
            it._Rate=rate;
            setRate(rate);
            break;
        }
    }
    saveinfile(svcountries,"Currencies.txt");
}
};
