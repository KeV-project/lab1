#pragma once

#include <iostream>
#include "Output.h"

using namespace std;

struct Flight
{
	string FlightNumber;
	int PlaneNumber;
	//TODO: ����� �� ������ ���������, �������� ����� ������� ���� �� ����
	// ����� ������
	string Departure;
	// ����� ����������
	string Destination;
	// ����� ������ � �������
	int Duration;
	// ���������� � ��
	int Distance;
	//���������� ���������� �� �����
	int Passengers;
};

Flight* MakeFlight(const string& flightNumber, const int planeNumber,
	const string& departure, const string& destination, const int duration,
	const int distance, const int passengers);
Flight* CopyFlight(const Flight& flight);
void ReadFlight(Flight& flight);
void PrintFlight(const Flight& flight);
void ChangeFlight(Flight* flight, const string& flightNumber,
	const int planeNumber, const string& departure,
	const string& destination, const int duration,
	const int distance, const int passengers);
void DemoDynamicFlight();
void FindShortestFlight(Flight** flights, int flightsCize);
void DemoDynamicFlights();
void DemoFlight();