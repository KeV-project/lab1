#pragma once
#include <iostream>
#include <string>
#include "ValueValidator.h"

using namespace std;

class Time
{
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;

public:
	void SetYear(const int year);
	void SetMonth(const int month);
	void SetDay(const int day);
	void SetHour(const int hour);
	void SetMinute(const int minute);

	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHour();
	int GetMinute();
	string GetTime();

	Time();
	Time(const int year, const int month, const int day,
		const int hour, const int minute);
	
	bool IsTimeBeforeThen(Time& time);
};

