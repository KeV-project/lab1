#pragma once

#include <iostream>

using namespace std;

struct Flight
{
	int PlaneNumber;
	// Пункт Вылета
	string Departure;
	// Пункт назначения
	string Destination;
	// Время полета в минутах
	int Duration;
	int Distance;
	//Количество пассажиров на борту
	int Passengers;
};

void DemoFlight();