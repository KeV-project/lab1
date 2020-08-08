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
void PrintFlight(Flight& flight);
void ChangeFlight(Flight* flight, string flightNumber,
	int planeNumber, string departure, string destination,
	int duration, int distance, int passengers);
void DemoDynamicFlight();
void FindShortestFlight(Flight** flights, int flightsCize);
void DemoDynamicFlights();
void DemoFlight();