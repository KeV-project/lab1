#pragma once

#include <iostream>
#include <string>

using namespace std;

class Time
{
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;
	int _second;

public:
	void SetYear(const int year);
	void SetMonth(const int month);
	void SetDay(const int day);
	void SetHour(const int hour);
	void SetMinute(const int minute);
	void SetSecond(const int second);

	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();
	int GetMinute();
	int GetSecond();

	Time();
	Time(const int year, const int month, const int day,
		const int hour, const int minute, const int second);
	
	string GetTime();
};

