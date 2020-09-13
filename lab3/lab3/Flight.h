#pragma once
#include <iostream>
#include <string>
#include "ValueValidator.h"
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

	void SetDepartureTime(const int year, const int month,
		const int day, const int hour, const int minute);
	void SetDestinationTime(const int year, const int month,
		const int day, const int hour, const int minute);

public:
	void SetNumber(const int number);
	void SetDeparture(const string& departure);
	void SetDestination(const string& destination);
	void SetTime(const int departureYear,
		const int departureMonth, const int departureDay,
		const int departureHour, const int departureMinute,
		const int destinationYear, const int destinationMonth,
		const int destinationDay, const int destinationHour,
		const int destinationMinute);

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
	    const int destinationYear, const int destinationMonth, 
		const int destinationDay, const int destinationHour, 
		const int destinationMinute);

	void ChangeFlight(const int number, const string& departure,
		const string& destination, const int departureYear,
		const int departureMonth, const int departureDay,
		const int departureHour, const int departureMinute,
		const int destinationYear, const int destinationMonth, 
		const int destinationDay, const int destinationHour, 
		const int destinationMinute);

	int GetFlightTimeMinutes();
};