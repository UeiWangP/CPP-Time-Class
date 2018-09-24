#include <iostream>
#include <ctime>
#include "../Lib/Time.h"
#pragma warning(disable : 4996)		//_CRT_SECURE_NO_WARNINGS
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
	time_t now;
	time(&now);		//get current time
	tm * tm_now = localtime(&now);		//convert to tm
	Time t2(tm_now);	//convert to Time
	Time time_diff = t1 - t2;
	cout << "Countdown: ";
	time_diff.show_time_separate();
}