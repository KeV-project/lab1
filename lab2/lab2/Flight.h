#pragma once

#include <iostream>
#include "Output.h"

using namespace std;

struct Flight
{
	string FlightNumber;
	int PlaneNumber;
	//TODO: Много не нужных комментов, названия полей говорят сами за себя +
	string Departure;
	string Destination;
	int DurationInMinutes;
	int DistanceInMeters;
	int Passengers;
};

Flight* MakeFlight(const string& flightNumber, const int planeNumber,
	const string& departure, const string& destination, const int durationInMinutes,
	const int distanceInMeters, const int passengers);
Flight* CopyFlight(const Flight& flight);
void ReadFlight(Flight& flight);
void PrintFlight(const Flight& flight);
void ChangeFlight(Flight* flight, const string& flightNumber,
	const int planeNumber, const string& departure,
	const string& destination, const int durationInMinutes,
	const int distanceInMeters, const int passengers);
void DemoDynamicFlight();
void FindShortestFlight(Flight** flights, const int flightsCount);
void DemoDynamicFlights();
void DemoFlight();