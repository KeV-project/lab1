#pragma once

#include <iostream>

using namespace std;

struct Flight
{
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

void DemoFlight();