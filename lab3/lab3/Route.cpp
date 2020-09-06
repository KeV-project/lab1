#include "Route.h"

void Route::SetNumber(const int number)
{
	//TODO: ����� +
	int const minNumber = 0;
	int const maxNumber = 1000000;
	AssertValueInRange(number, minNumber,
		maxNumber, NotInRange, "����� �����");
	this->_number = number;
}

void Route::SetDuration(const int duration)
{
	//TODO: ����� +
	int const minDuration = 1;
	int const maxDuration = 2147483647;
	AssertValueInRange(duration, minDuration, maxDuration, 
		NotPositive, "����������������� �����");
	this->_durationInMinutes = duration;
}

void Route::SetPeriodicity(const int periodicity)
{
	//TODO: ����� +
	int const minPeriodicity = 1;
	int const maxPeriodicity = 2147483647;
	AssertValueInRange(periodicity, minPeriodicity, maxPeriodicity, 
		NotPositive, "������������� �����");
	this->_periodicity = periodicity;
}

void Route::SetStops(string* stops, const int stopsCount)
{
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	//TODO: ����� +
	int const minStopsCount = 2;
	int const maxStopsCount = 10;
	AssertValueInRange(stopsCount, minStopsCount,
		maxStopsCount, NotInRange, "���������� ���������");
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