#include "Time.h"

void Time::SetYear(const int year)
{
	//TODO: ƒубль +
	int const minLimit = 0;
	int const maxLimit = 2020;
	if (!IsValueInRange(year, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(year, minLimit,
			maxLimit, "год").c_str());
		throw exception(message);
	}
	this->_year = year;
}

void Time::SetMonth(const int month)
{
	//TODO: ƒубль +
	//TODO: —ообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы +
	int const minLimit = 1;
	int const maxLimit = 12;
	if (!IsValueInRange(month, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(month, minLimit,
			maxLimit, "мес€ц").c_str());
		throw exception(message);
	}
	this->_month = month;
}

void Time::SetDay(const int day)
{
	//TODO: ƒубль +
	//TODO: —ообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы +
	int const minLimit = 1;
	int const maxLimit = 31;
	if (!IsValueInRange(day, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(day, minLimit,
			maxLimit, "день").c_str());
		throw exception(message);
	}
	this->_day = day;
}

void Time::SetHour(const int hour)
{
	//TODO: ƒубль +
	//TODO: —ообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы +
	int const minLimit = 0;
	int const maxLimit = 23;
	if (!IsValueInRange(hour, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(hour, minLimit,
			maxLimit, "час").c_str());
		throw exception(message);
	}
	this->_hour = hour;
}

void Time::SetMinute(const int minute)
{
	//TODO: ƒубль +
	//TODO: —ообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы +
	int const minLimit = 0;
	int const maxLimit = 59;
	if (!IsValueInRange(minute, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(minute, minLimit,
			maxLimit, "минуты").c_str());
		throw exception(message);
	}
	this->_minute = minute;
}

int Time::GetYear()
{
	return _year;
}

int Time::GetMonth()
{
	return _month;
}

int Time::GetDay()
{
	return _day;
}

int Time::GetHour()
{
	return _hour;
}

int Time::GetMinute()
{
	return _minute;
}

Time::Time()
{
	SetYear(2020);
	SetMonth(12);
	SetDay(31);
	SetHour(23);
	SetMinute(59);
}

Time::Time(const int year, const int month, const int day,
	const int hour, const int minute)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
	SetHour(hour);
	SetMinute(minute);
}

string Time::GetTime()
{
	return to_string(_year) + "." + to_string(_month) 
		+ "." + to_string(_day) + " " + to_string(_hour) 
		+ ":" + to_string( _minute);
}
