#pragma once

#include <iostream>
#include "Output.h"

using namespace std;

struct Time
{
	int Year;
	int Month;
	int Day;
	// 0 - 23
	int Hour;
	int Minute;
	int Second;
};

Time* MakeTime(const int year, const int month, const int day,
	const int hour, const int minute, const int second);
Time* CopyTime(const Time& time);
void ReadTime(Time& event);
void PrintTime(const Time& event);
void ChangeTime(Time* event, const int year, const int month,
	const int day, const int hour, const int minute, const int second);
void DemoTime();