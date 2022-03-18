#include <iostream>
#include <string>
#include<fstream>
#include"ArrayList.h"
#include"LinkedList_S.h"
#include"Stack_ll.h"
#include"DailyExpenses.h"
#include "User__.h"

bool login(User__ &U){
	string Usern, Upassword;
	cout << "enter Username And Password\n";
	cin >> Usern;
	cin.ignore();
	getline(cin, Upassword);

	if (U.loadFromFile(Usern)) {
		if (Usern == U.getUsername() && Upassword == U.getPassword()) {
			return true;
		}
		else {
		    cout << "Wrong UserName Or Password\n";
			return false;
		}
	}
	else {
		cout << "Wrong UserName Or User File Doesnot Exist\n";
		return false;
	}
	return false;
}

void U_register(User__ &u) {

	string Usern, Upassword, monthname;
	double monthlyicome;
	cout << "enter Username And Password\n";
	cin.ignore();
	getline(cin, Usern);
	getline(cin, Upassword);
	cout << "enter Month name And MonthlyIncome\n";
	cin >> monthname;
	cin >> monthlyicome;
	u.monthEx.setMonthName(monthname);
	u.setUserName(Usern);
	u.setPassword(Upassword);
	u.setMontlyIncome(monthlyicome);

}

void addDailyExpenses(User__ &u) {

	if (u.monthEx.daysExpenses.get_length() == 30) {
		cout << "the month is finished\n";
	}
	else if (u.monthEx.getRemainderMoney() <= 0) {
		cout << "You don't have any remaining income.\n";
	}
	else {
		DailyExpenses d;
		char answer;
		string categoryname;
		double money;
		cout << "day number " << u.monthEx.daysExpenses.get_length() + 1 << "__________\n";
		while (true) {
			cout << "enter the category name then the amount of money\n";
			cin >> categoryname; cin >> money;
			if (u.monthEx.getRemainderMoney() < money) {
				cout << "the amount of money you enterd is biger that the remainder\n";
				continue;
			}
			else {
				d.AddCategory(categoryname, money);
			}
			cout << "enter y to add onther category\n";
			cin >> answer;

			if ((char)tolower(answer) != 'y')
				break;
		}
		d.setDaynum(u.monthEx.daysExpenses.get_length() + 1);
		u.monthEx.AddDayExpenses(d);
	}
}


void displayDailyExpenses(User__ &u) {
	bool dayf, amountf, cf;
	char answer;

	cout << "Do you want to filter by days(y/n)? ";
	while (true) {
		cin >> answer;
		if (tolower(answer) == 'y') {
			dayf = true;
			break;
		}
		else if (tolower(answer) == 'n')  {
			dayf = false;
			break;
		}
		else {
			cout << "Invalid Input. Try Again: ";
		}
	}

	cout << "Do you want to filter by amount(y/n)? ";
	while (true) {
		cin >> answer;
		if (tolower(answer) == 'y') {
			amountf = true;
			break;
		}
		else if (tolower(answer) == 'n') {
			amountf = false;
			break;
		}
		else {
			cout << "Invalid Input. Try Again: ";
		}
	}

	cout << "Do you want to filter by category(y/n)? ";
	while (true) {
		cin >> answer;
		if (tolower(answer) == 'y') {
			cf = true;
			break;
		}
		else if (tolower(answer) == 'n') {
			cf = false;
			break;
		}
		else {
			cout << "Invalid Input. Try Again: ";
		}
	}
	u.monthEx.display(dayf, amountf, cf);
}


void menu(User__ &u) {

    int choise1 = 0;
		cout << "enter 1 for display Daily Expenses\n"
			<< "2 for addDailyExpenses\n"
			<< "3 for remaining monthly income\n"
			<< "4 for Save & exiting the programm\n";
		cin >> choise1;
		cin.ignore();

		if (choise1 == 1) {
			displayDailyExpenses(u);
		}
		else if (choise1 == 2) {
			addDailyExpenses(u);
		}
		else if (choise1 == 3) {
			cout << u.monthEx.getRemainderMoney() << endl;
		}
		else if (choise1 == 4) {
			u.saveToFile(u.getUsername());
			exit(0);
		}
		else {
			cout << "wrong value" << endl;
			menu(u);
		}

}


int main() {
	cout << "Do you want to register or login?\n";

	User__ u;
	int answer;
	do {
		cout << "1.Register\t2.Login\n";
		cin >> answer;
		if (answer == 1) {
			U_register(u);
			break;
		}
		else if (answer == 2) {
			if (login(u)) {
				break;
			}
		}
		else {
			cout << "Invalid input. Try again: ";
		}
	} while (true);
	
	while (true)
		menu(u);

	return 0;
}
