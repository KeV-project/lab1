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
void PrintTime(Time& event);
void ChangeTime(Time* event, int year, int month, int day,
	int hour, int minute, int second);
void DemoTime();