#include "Route.h"

void Route::SetNumber(const int number)
{
	if (number <= 0)
	{
		string message = "����� " + to_string(number) +
			" �� �������� �������������\n� �� ����� ���������� ����� �����";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_number = number;
}

void Route::SetDuration(const int duration)
{
	if (duration <= 0)
	{
		string message = "����� " + to_string(duration) +
			" �� �������� ������������� �����\n"
			"� �� ����� ���������� ����������������� �����";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_durationInMinutes = duration;
}

void Route::SetPeriodicity(const int periodicity)
{
	if (periodicity <= 0)
	{
		string message = "����� " + to_string(periodicity) +
			"�� �������� ������������� ������\n"
			"� �� ����� ���������� ������������� �����";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_periodicity = periodicity;
}

void Route::SetStops(string* stops, const int stopsCount)
{
	if (stopsCount < 0)
	{
		string message = "������������� �����  " + to_string(stopsCount) +
			" �� ����� ���������� ���������� ��������� �����";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
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
	SetStops(nullptr, 0);
}

Route::Route(const int number, const int duration, const int periodicity,
	const int stopsCount, string* stops)
{
	SetNumber(number);
	SetDuration(duration);
	SetPeriodicity(periodicity);
	SetStops(stops, stopsCount);
}
