#pragma once
#include <iostream>
#include <string>
#include"ArrayList.h"
#include"LinkedList_S.h"
#include"Stack_ll.h"
#include"DailyExpenses.h"

class MonthlyExpenses
{
	double MonthlyIncome_remainder;
	string month;


public:
	ArrayList<DailyExpenses>daysExpenses;

	MonthlyExpenses();
	void AddDayExpenses(DailyExpenses d);


	void display(bool dayf, bool amountf, bool cf);
	
	double getRemainderMoney();

	void setMonthRemainder(double s);
	string getMonthName();
	void setMonthName(string s);

};

