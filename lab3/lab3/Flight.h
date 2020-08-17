#pragma once

#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

class Flight
{
private:
	int _number;
	string _departure;
	string _destination;
	Time _departureTime;
	Time _destinationTime;

public:
	void SetNumber(const int number);
	void SetDeparture(const string& departure);
	void SetDestination(const string& destination);
	void SetDepartureTime(const int year, const int month,
		const int day, const int hour, const int minute, const int second);
	void SetDestinationTime(const int year, const int month,
		const int day, const int hour, const int minute, const int second);

	int GetNumber();
	string GetDeparture();
	string GetDestination();
	Time GetDepartureTime();
	Time GetDestinationTime();

	Flight();
	Flight(const int number, const string& departure,
		const string& destination, const int departureYear,
		const int departureMonth, const int departureDay,
		const int departureHour, const int departureMinute,
		const int departureSecond, const int destinationYear,
		const int destinationMonth, const int destinationDay,
		const int destinationHour, const int destinationMinute,
		const int destinationSecond);
};

