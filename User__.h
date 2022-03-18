#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include"ArrayList.h"
#include"LinkedList_S.h"
#include"Stack_ll.h"
#include "MonthlyExpenses.h"
class User__
{
	string userName;
	string password;
	double Monthly_Income;

public:
	MonthlyExpenses monthEx;
	User__();
	void setMontlyIncome(double m);
	double getMonthlyIncome();
	void setUserName(string str);
	void setPassword(string str);
	string getUsername();
	string getPassword();
	void saveToFile(string username);
	bool loadFromFile(string username);
};

