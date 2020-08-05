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

void ReadFlight(Flight& flight);
void PrintFlight(Flight& flight);
void DemoFlight();