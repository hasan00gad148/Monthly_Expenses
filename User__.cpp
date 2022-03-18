#include "User__.h"

User__::User__()
{
	Monthly_Income = 0.0;
}

void User__::setMontlyIncome(double m)
{
	Monthly_Income = m;
	monthEx.setMonthRemainder(m);
}

double User__::getMonthlyIncome()
{
	return Monthly_Income;
}

void User__::setUserName(string str)
{
	userName = str;
}

void User__::setPassword(string str)
{
	password = str;
}

string User__::getUsername()
{
	return userName;
}

string User__::getPassword()
{
	return password;
}

void User__::saveToFile(string username) {
	ofstream outfile (username +".txt");

	if (outfile.is_open()) {
		outfile << userName << endl;
		outfile << password << endl;
		outfile << monthEx.getMonthName() << endl;
		outfile << monthEx.daysExpenses.get_length() << endl;
		outfile << Monthly_Income << endl;
		outfile << monthEx.getRemainderMoney() << endl;

		if (monthEx.daysExpenses.get_length()!=0) {
			for (int i = 0; i < monthEx.daysExpenses.get_length(); i++)
			{
				outfile << monthEx.daysExpenses.get(i).getDaynum() << endl;
				outfile << monthEx.daysExpenses.get(i).dailyEx_names.get_length() << endl;
				for (int j = 0; j < monthEx.daysExpenses.get(i).dailyEx.get_length(); j++) {
					outfile << monthEx.daysExpenses.get(i).getCategortName(j) << endl;
					outfile << monthEx.daysExpenses.get(i).getCategort(j) << endl;
				}
			}
		}
		outfile.close();
	}
	else {
		cout << "File Is Not Open \n";
	}

}


bool User__::loadFromFile(string username) {
	ifstream infile(username + ".txt");
	if (infile.is_open()) {
		string s1, s2;
		int daysnum, categorynum;
		if(!infile.eof() && !infile.bad()) {
			infile >> userName;
			infile >> password;
			infile >> s1;
			monthEx.setMonthName(s1);
			infile >> s1;
			daysnum = std::stoi(s1);
			infile >> s1;
			setMontlyIncome(std::stod(s1));
			infile >> s1;
			monthEx.setMonthRemainder(std::stod(s1));
			for (int i = 0; i < daysnum; i++) 
			{
				DailyExpenses d;

				infile >> s1;
				d.setDaynum(std::stoi(s1));

				infile >> s1;
				categorynum = std::stoi(s1);

				for (int j = 0; j < categorynum; j++) {
					infile >> s1;
					infile >> s2;
					d.AddCategory(s1, std::stod(s2));
				}
				monthEx.AddDayExpenses(d);
			}

		}
		infile.close();
		return true;
	}
	else {
		cout << "File Is Not Open \n";
	}
	return false;
}


