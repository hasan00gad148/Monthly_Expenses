#pragma once
#include <iostream>
#include <string>
#include"ArrayList.h"
#include"Stack_ll.h"



class DailyExpenses
{

	int DayNum;

    public:
		ArrayList<string> dailyEx_names;
		ArrayList<double> dailyEx;

	DailyExpenses();

	double get_dailyTotal();

	double getCategort(int i);
	string getCategortName(int i);

	void get_daileEx();
    int getCategoryByName(string s);

	void AddCategory(string str, double m);

	void setDaynum(int x);
	int getDaynum();
};

