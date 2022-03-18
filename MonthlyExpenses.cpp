
#include "MonthlyExpenses.h"


void MonthlyExpenses::display(bool dayf, bool amountf, bool cf) {
	int start, end, catIndex;
	double amount1, amount2;
	string c;

	if (dayf == true && amountf == true && cf == true) {

		while (true) {
			cout << "Enter start day: ";
			cin >> start;
			if (start < 1 || start > daysExpenses.get_length())
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}
		while (true) {
			cout << "Enter end day: ";
			cin >> end;
			if (end < start || end > daysExpenses.get_length())
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}

		while (true) {
			cout << "Enter minimum amount: ";
			cin >> amount1;
			if (amount1 < 0 || amount1 > 1000000)
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}
		while (true) {
			cout << "Enter maximum amount: ";
			cin >> amount2;
			if (amount2 < amount1 || amount2 > 1000000)
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}

		cout << "Enter the name of the desired category:\n";
		cin.ignore();
		getline(cin, c);

		for (int i = start - 1; i < end; i++) {
			if (daysExpenses.get(i).get_dailyTotal() >= amount1 && daysExpenses.get(i).get_dailyTotal() <= amount2) {
				catIndex = daysExpenses.get(i).getCategoryByName(c);
				if (catIndex == -1) {

					cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
					cout << "Couldn't find the category this day.\n";
				}
				else {
					cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
					cout << daysExpenses.get(i).getCategortName(catIndex) << " ---> " << daysExpenses.get(i).getCategort(catIndex) << endl;
				}
			}
		}
	}
	else if (dayf == true && amountf == true && cf == false) {
		while (true) {
			cout << "Enter start day: ";
			cin >> start;
			if (start < 1 || start > daysExpenses.get_length())
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}
		while (true) {
			cout << "Enter end day: ";
			cin >> end;
			if (end < start || end > daysExpenses.get_length())
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}

		while (true) {
			cout << "Enter minimum amount: ";
			cin >> amount1;
			if (amount1 < 0 || amount1 > 1000000)
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}
		while (true) {
			cout << "Enter maximum amount: ";
			cin >> amount2;
			if (amount2 < amount1 || amount2 > 1000000)
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}

		for (int i = start - 1; i < end; i++) {
			if (daysExpenses.get(i).get_dailyTotal() >= amount1 && daysExpenses.get(i).get_dailyTotal() <= amount2) {
				cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
				daysExpenses.get(i).get_daileEx();
			}
		}
	}
	else if (dayf == true && amountf == false && cf == true) {
		while (true) {
			cout << "Enter start day: ";
			cin >> start;
			if (start < 1 || start > daysExpenses.get_length())
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}
		while (true) {
			cout << "Enter end day: ";
			cin >> end;
			if (end < start || end > daysExpenses.get_length())
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}

		cout << "Enter the name of the desired category:\n";
		cin.ignore();
		getline(cin, c);

		for (int i = start - 1; i < end; i++) {
			catIndex = daysExpenses.get(i).getCategoryByName(c);
			if (catIndex == -1) {

				cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
				cout << "Couldn't find the category this day.\n";
			}
			else {
				cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
				cout << daysExpenses.get(i).getCategortName(catIndex) << " ---> " << daysExpenses.get(i).getCategort(catIndex) << endl;
			}
		}
	}
	else if (dayf == true && amountf == false && cf == false) {
		while (true) {
			cout << "Enter start day: ";
			cin >> start;
			if (start < 1 || start > daysExpenses.get_length())
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}
		while (true) {
			cout << "Enter end day: ";
			cin >> end;
			if (end < start || end > daysExpenses.get_length())
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}

		for (int i = start - 1; i < end; i++) {
			cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
			daysExpenses.get(i).get_daileEx();
		}
	}
	else if (dayf == false && amountf == true && cf == true) {
		while (true) {
			cout << "Enter minimum amount: ";
			cin >> amount1;
			if (amount1 < 0 || amount1 > 1000000)
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}
		while (true) {
			cout << "Enter maximum amount: ";
			cin >> amount2;
			if (amount2 < amount1 || amount2 > 1000000)
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}

		cout << "Enter the name of the desired category:\n";
		cin.ignore();
		getline(cin, c);

		for (int i = 0; i < daysExpenses.get_length(); i++) {
			if (daysExpenses.get(i).get_dailyTotal() >= amount1 && daysExpenses.get(i).get_dailyTotal() <= amount2) {
				catIndex = daysExpenses.get(i).getCategoryByName(c);
				if (catIndex == -1) {

					cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
					cout << "Couldn't find the category this day.\n";
				}
				else {
					cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
					cout << daysExpenses.get(i).getCategortName(catIndex) << " ---> " << daysExpenses.get(i).getCategort(catIndex) << endl;
				}
			}
		}
	}
	else if (dayf == false && amountf == true && cf == false) {
		while (true) {
			cout << "Enter minimum amount: ";
			cin >> amount1;
			if (amount1 < 0 || amount1 > 1000000)
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}
		while (true) {
			cout << "Enter maximum amount: ";
			cin >> amount2;
			if (amount2 < amount1 || amount2 > 1000000)
				cout << "Invalid Input. Try again.\n";
			else
				break;
		}

		for (int i = 0; i < daysExpenses.get_length(); i++) {
			if (daysExpenses.get(i).get_dailyTotal() >= amount1 && daysExpenses.get(i).get_dailyTotal() <= amount2) {
				cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
				daysExpenses.get(i).get_daileEx();
			}
		}
	}
	else if (dayf == false && amountf == false && cf == true) {
		cout << "Enter the name of the desired category:\n";
		cin.ignore();
		getline(cin, c);

		for (int i = 0; i < daysExpenses.get_length(); i++) {
			catIndex = daysExpenses.get(i).getCategoryByName(c);
			if (catIndex == -1) {

				cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
				cout << "Couldn't find the category this day.\n";
			}
			else {
				cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
				cout << daysExpenses.get(i).getCategortName(catIndex) << " ---> " << daysExpenses.get(i).getCategort(catIndex) << endl;
			}
		}
	}
	else if (dayf == false && amountf == false && cf == false) {
		for (int i = 0; i < daysExpenses.get_length(); i++) {
			cout << "Day Number #" << daysExpenses.get(i).getDaynum() << endl;
			daysExpenses.get(i).get_daileEx();
		}
	}
}


MonthlyExpenses::MonthlyExpenses() {
	MonthlyIncome_remainder = 0;
}

void MonthlyExpenses::AddDayExpenses(DailyExpenses d){
	
	if ((MonthlyIncome_remainder - d.get_dailyTotal())< 0) {
		cout << "The Day expenses is larger than monthly income remainder" << endl;
	}
	else {
		daysExpenses.add(d);
		MonthlyIncome_remainder -= d.get_dailyTotal();
	}
}


double MonthlyExpenses::getRemainderMoney(){
	
	return MonthlyIncome_remainder;
}

string MonthlyExpenses::getMonthName()
{
	return month;
}

void MonthlyExpenses::setMonthName(string s)
{
	month = s;
}

void MonthlyExpenses::setMonthRemainder(double s)
{
	MonthlyIncome_remainder = s;
}
