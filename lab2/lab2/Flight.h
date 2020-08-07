#pragma once

#include <iostream>
#include "Output.h"

using namespace std;

struct Flight
{
	string FlightNumber;
	int PlaneNumber;
	// ����� ������
	string Departure;
	// ����� ����������
	string Destination;
	// ����� ������ � �������
	int Duration;
	int Distance;
	//���������� ���������� �� �����
	int Passengers;
};

Flight* MakeFlight(string flightNumber, int planeNumber, string departure,
	string destination, int duration, int distance, int passengers);
void ReadFlight(Flight& flight);
void PrintFlight(Flight& flight);
void ChangeFields(Flight* flight, string flightNumber,
	int planeNumber, string departure, string destination,
	int duration, int distance, int passengers);
void DemoFlight();