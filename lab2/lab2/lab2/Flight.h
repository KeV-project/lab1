#pragma once

#include <iostream>
#include "Output.h"

using namespace std;

struct Flight
{
	string FlightNumber;
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

void ReadFlight(Flight& flight);
void PrintFlight(Flight& flight);
void DemoFlight();