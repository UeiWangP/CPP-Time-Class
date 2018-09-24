#include <ctime>
#include "../Lib/Time.h"
#pragma warning(disable : 4996)		//_CRT_SECURE_NO_WARNINGS

void Time::time_formatting()
{
	if (sec_ >= 60)
	{
		min_ += sec_ / 60;
		sec_ %= 60;
	}
	if (min_ >= 60)
	{
		hour_ += min_ / 60;
		min_ %= 60;
	}
	if (hour_ >= 24)
	{
		day_ += hour_ / 24;
		hour_ %= 24;
	}
}

void Time::date_formatting()
{
	while (day_ > days_of_a_month(month_))
	{
		day_ %= days_of_a_month(month_++);
	}
	if (month_ > Months_of_a_year)
	{
		year_ += month_ / Months_of_a_year;
		month_ %= Months_of_a_year;
	}
}

Time::Time(int year, int month, int day, int hour, int min, int sec)
{
	year_ = year;
	month_ = month;
	day_ = day;
	hour_ = hour;
	min_ = min;
	sec_ = sec;
	time_formatting();
	date_formatting();
}

Time::Time(char type, int x, int y, int z)
{
	if (type == 'T')	//the input is a time
	{
		hour_ = x;
		min_ = y;
		sec_ = z;
		time_formatting();
	}
	else if (type == 'D')	//the input is a date
	{
		year_ = x;
		month_ = y;
		day_ = z;
		date_formatting();
	}
	//should throw an exception here (not yet learned)
}

Time::Time(char format[3], int x, int y)
{
	if (format == "YM")	//Year-Month
	{
		year_ = x;
		month_ = y;
		date_formatting();
	}
	else if (format == "MD")	//Month-Day
	{
		month_ = x;
		day_ = y;
		date_formatting();
	}
	else if (format == "HM")	//Hour-Minute
	{
		hour_ = x;
		min_ = y;
		time_formatting();
	}
	else if (format == "MS")	//Minute-Second
	{
		min_ = x;
		sec_ = y;
		time_formatting();
	}
	//should throw an exception here (not yet learned)
}

Time::Time(tm * t)
{
	year_ = t->tm_year + 1900;
	month_ = t->tm_mon + 1;
	day_ = t->tm_mday;
	hour_ = t->tm_hour;
	min_ = t->tm_min;
	sec_ = t->tm_sec;
}

bool Time::is_leap_year(int year) const
{
	if (year % 100 != 0)
		if (year % 4 == 0)
			return true;
		else
			return false;
	else if (year % 400 == 0)
		return true;
	else return false;
}

int Time::days_of_a_month(int month) const
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 2)
		return is_leap_year(year_) ? 29 : 28;
	else return 30;
}

void Time::add_hour(int num)
{
	hour_ += num;
	time_formatting();
}

void Time::add_min(int num)
{
	min_ += num;
	time_formatting();
}

void Time::add_sec(int num)
{
	sec_ += num;
	time_formatting();
}

void Time::add_day(int num)
{
	day_ += num;
	date_formatting();
}

void Time::add_month(int num)
{
	month_ += num;
	date_formatting();
}

void Time::add_year(int num)
{
	year_ += num;
	date_formatting();
}

Time Time::operator-(const Time &t) const
{
	struct tm * tm_1=new tm, * tm_2=new tm;
	tm_1->tm_year = year_ - 1900;
	tm_1->tm_mon = month_ - 1;
	tm_1->tm_mday = day_;
	tm_1->tm_hour = hour_;
	tm_1->tm_min = min_;
	tm_1->tm_sec = sec_;
	tm_2->tm_year = t.year_ - 1900;
	tm_2->tm_mon = t.month_ - 1;
	tm_2->tm_mday = t.day_;
	tm_2->tm_hour = t.hour_;
	tm_2->tm_min = t.min_;
	tm_2->tm_sec = t.sec_;
	int seconds = difftime(mktime(tm_1), mktime(tm_2));
	delete tm_1, tm_2;
	Time result("MS", 0, seconds);
	return result;
}

Time Time::operator+(const Time &t) const
{
	Time result(year_ + t.year_, month_ + t.month_, day_ + t.day_, hour_ + t.hour_, min_ + t.min_, sec_ + t.sec_);
	return result;
}

Time current_time()
{
	time_t now;
	time(&now);		//get current time
	tm * tm_now = localtime(&now);		//convert to tm
	Time result(tm_now);	//convert to Time
	return result;
}