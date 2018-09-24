#include <iostream>
#include <ctime>
#include "../Lib/Time.h"
using namespace std;
void countdown();

int main()
{
	countdown();
	cin.get();
	cin.get();
}

void countdown()
{
	cout << "----------µ¹¼ÆÊ±¼ÆËãÆ÷----------\n";	//translation: Countdown calculator
	int year, month, day, hour, min, sec;
	cout << "     Enter date and time\n";
	cout << "Year: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;
	cout << "Hour: ";
	cin >> hour;
	cout << "Min: ";
	cin >> min;
	cout << "Sec:";
	cin >> sec;
	cout << "\nCalculating....\n\n";
	Time t1(year, month, day, hour, min, sec);
	Time t2 = current_time();
	Time time_diff = t1 - t2;
	cout << "Countdown: ";
	time_diff.show_time_separate();
}