#pragma once

#include <iostream>
#include <string>
#include "Input.h"
#include "MakeMessage.h"

using namespace std;

class Route
{
private:
	int _number;
	int _durationInMinutes;
	int _periodicity;
	int _stopsCount;
	string* _stops;

public:
	void SetNumber(const int number);
	void SetDuration(const int duration);
	void SetPeriodicity(const int periodicity);
	void SetStops(string* stops, const int stopsCount);

	int GetNumber();
	int GetDuration();
	int GetPeriodicity();
	int GetStopsCount();
	string* GetStops();

	Route();
	Route(const int number, const int duration, const int periodicity,
		const int stopsCount, string* stops);

	~Route();

	void ReadRouteFromConsole();
	void WriteRouteToConsole();
};

int FindRouteTo(Route* routes, const int routesCount,
	const string& findedStop);