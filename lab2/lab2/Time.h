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

Time* MakeTime(int year, int month, int day,
	int hour, int minute, int second);
Time* CopyTime(Time& time);
void ReadTime(Time& event);
void PrintTime(Time& event);
void ChangeTime(Time* event, int year, int month, int day,
	int hour, int minute, int second);
void DemoTime();