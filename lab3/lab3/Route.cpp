#include "Route.h"

void Route::SetNumber(const int number)
{
	//TODO: Дубль +
	int const minNumber = 0;
	int const maxNumber = 1000000;
	AssertValueInRange(number, minNumber,
		maxNumber, NotInRange, "номер рейса");
	this->_number = number;
}

void Route::SetDuration(const int duration)
{
	//TODO: Дубль +
	int const minDuration = 1;
	int const maxDuration = 2147483647;
	AssertValueInRange(duration, minDuration, maxDuration, 
		NotPositive, "продолжительность рейса");
	this->_durationInMinutes = duration;
}

void Route::SetPeriodicity(const int periodicity)
{
	//TODO: Дубль +
	int const minPeriodicity = 1;
	int const maxPeriodicity = 2147483647;
	AssertValueInRange(periodicity, minPeriodicity, maxPeriodicity, 
		NotPositive, "периодичность рейса");
	this->_periodicity = periodicity;
}

void Route::SetStops(string* stops, const int stopsCount)
{
	//TODO: Сообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы +
	//TODO: Дубль +
	int const minStopsCount = 2;
	int const maxStopsCount = 10;
	AssertValueInRange(stopsCount, minStopsCount,
		maxStopsCount, NotInRange, "количество остановок");
	this->_stopsCount = stopsCount;
	this->_stops = stops;
}

int Route::GetNumber()
{
	return this->_number;
}

int Route::GetDuration()
{
	return this->_durationInMinutes;
}

int Route::GetPeriodicity()
{
	return this->_periodicity;
}

int Route::GetStopsCount()
{
	return this->_stopsCount;
}

string* Route::GetStops()
{
	return this->_stops;
}

Route::Route()
{
	SetNumber(1);
	SetDuration(1);
	SetPeriodicity(1);
	SetStops(nullptr, 2);
}

Route::Route(const int number, const int duration, const int periodicity,
	const int stopsCount, string* stops)
{
	SetNumber(number);
	SetDuration(duration);
	SetPeriodicity(periodicity);
	SetStops(stops, stopsCount);
}

Route::~Route()
{
	delete [] _stops;
}

int FindRouteTo(Route** routes,
	const int routesCount, const string& findedStop)
{
	for (int i = 0; i < routesCount; i++)
	{
		for (int j = 0; j < routes[i]->GetStopsCount(); j++)
		{
			if (routes[i]->GetStops()[j] == findedStop)
			{
				return i;
			}
		}
	}
	return -1;
}