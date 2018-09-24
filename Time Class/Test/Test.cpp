#include <iostream>
#include <ctime>
#include "Time.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
void test_date_basic();
void test_time_basic();
void test_plus1sec();
void test_time_difference();
int main()
{
	/*
	test_date_basic();
	cout << endl;
	test_time_basic();
	cout << endl;
	test_plus1sec();
	*/
	test_time_difference();
	cin.get();
	cin.get();
}

void test_date_basic()
{
	Time time('D',2012, 2, 29);
	time.add_day(1);
	time.show_date();
	cout << endl;
	Time time1('D', 2012, 12, 31);
	time1.add_day(1);
	time1.show_date();
}

void test_time_basic()
{
	Time time('T', 12, 59, 59);
	time.add_sec(1);
	time.show_time();
}

void test_plus1sec()
{
	Time time("MS", 0, 0);
	cout << "How many seconds do you want to add for Him?\n";
	int add;
	cin >> add;
	time.add_sec(add);
	cout << "Now Mr Jiang Zemin has ";
	time.show_time_separate();
	cout << "!";
}

void test_time_difference()
{
	int year, month, day, hour, min, sec;
	cout << "Enter date and time\n";
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
	Time t1(year, month, day, hour, min, sec);
	time_t now;
	time(&now);		//get current time
	tm * tm_now=localtime(&now);		//convert to tm
	Time t2(tm_now);	//convert to Time
	Time time_diff = t1 - t2;
	cout << "Time difference: "; time_diff.show_date_separate();
	cout << " ";
	time_diff.show_time_separate();
}