#include "Time.h"

void Time::SetYear(const int year)
{
	if (year <= 0)
	{
		string message = "„исло " + to_string(year) +
			" не €вл€етс€ положительным\nи не может "
			"определ€ть год";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_year = year;
}

void Time::SetMonth(const int month)
{
	if (month < 1 || month > 12)
	{
		string message = "„исло " + to_string(month) +
			" не входит в допустимый диапазон значений [1, 12]\n"
			"и не может определ€ть мес€ц";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_month = month;
}

void Time::SetDay(const int day)
{
	if (day < 1 || day > 31)
	{
		string message = "„исло " + to_string(day) +
			" не входит в допустимый диапазон значений [1, 31]\n"
			"и не может определ€ть день";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_day = day;
}

void Time::SetHour(const int hour)
{
	if (hour < 0 || hour > 23)
	{
		string message = "„исло " + to_string(hour) +
			" не входит в допустимый диапазон значений [0, 23]\n"
			"и не может определ€ть час";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_hour = hour;
}

void Time::SetMinute(const int minute)
{

	if (minute < 0 || minute > 59)
	{
		string message = "„исло " + to_string(minute) +
			" не входит в допустимый диапазон значений [0, 59]\n"
			"и не может определ€ть минуту";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
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
