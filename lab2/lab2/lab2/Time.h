#pragma once

#include <iostream>

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

void DemoTime();