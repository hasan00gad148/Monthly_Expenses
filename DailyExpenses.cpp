#include "DailyExpenses.h"


DailyExpenses::DailyExpenses() {
  
}

double DailyExpenses::get_dailyTotal(){
    double sum = 0;
    for (int i = 0; i < dailyEx.get_length(); ++i) {
        sum += dailyEx.get(i);
    }
    return sum;
}


void DailyExpenses::get_daileEx(){

    for (int i = 0; i < dailyEx.get_length(); ++i) {
        cout << dailyEx_names.get(i) << " ----> " << dailyEx.get(i) << endl;
    }
}


double DailyExpenses::getCategort(int i) {
    return dailyEx.get(i);
}
string DailyExpenses::getCategortName(int i) {
    return dailyEx_names.get(i);
}

int DailyExpenses::getCategoryByName(string s) {

    for (int i = 0; i < dailyEx_names.get_length(); i++) {
        bool match = true;
        if (s.length() == dailyEx_names.get(i).length()) {
            for (int j = 0; j < s.length(); j++) {
                if (tolower(s[j]) != tolower(dailyEx_names.get(i)[j])) {
                    match = false;
                    break;
                }
            }
            if (match)
                return i;
        }
    }
    return -1;
}

void DailyExpenses::AddCategory(string str, double m){
    dailyEx_names.add(str);
    dailyEx.add(m);
}

void DailyExpenses::setDaynum(int x) { DayNum = x; }

int DailyExpenses::getDaynum(){return DayNum;}
