#pragma once

#include <iostream>
#include "Input.h"
#include "Output.h"

using namespace std;

struct Time
{
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
};

void SetYear(Time& event, const int year);
void SetMonth(Time& event, const int month);
void SetDay(Time& event, const int day);
void SetHour(Time& event, const int hour);
void SetMinute(Time& event, const int minute);
void SetSecond(Time& event, const int second);

Time* MakeTime(const int year, const int month, const int day,
	const int hour, const int minute, const int second);
Time* CopyTime(const Time& event);
Time* ReadTime();
void PrintTime(const Time& event);
void ChangeTime(Time* event, const int year, const int month,
	const int day, const int hour, const int minute, const int second);
void DemoTime();