#pragma once
#include <bits/stdc++.h>
#include "clsUser.h"
using namespace std;

clsUser Currentuser = clsUser::getemptyuser();
enum bank {ON=1,OFF=0};
bank play = ON;
enum Logout {YES=1,NO=0};
Logout LOGIN = YES;
int client1,client2,amount;