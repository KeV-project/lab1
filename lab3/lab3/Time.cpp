#include "Time.h"

void Time::SetYear(const int year)
{
	if (year <= 0)
	{
		string message = "����� " + to_string(year) +
			" �� �������� �������������\n� �� ����� "
			"���������� ���";
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
		string message = "����� " + to_string(month) +
			" �� ������ � ���������� �������� �������� [1, 12]\n"
			"� �� ����� ���������� �����";
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
		string message = "����� " + to_string(day) +
			" �� ������ � ���������� �������� �������� [1, 31]\n"
			"� �� ����� ���������� ����";
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
		string message = "����� " + to_string(hour) +
			" �� ������ � ���������� �������� �������� [0, 23]\n"
			"� �� ����� ���������� ���";
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
		string message = "����� " + to_string(minute) +
			" �� ������ � ���������� �������� �������� [0, 59]\n"
			"� �� ����� ���������� ������";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_minute = minute;
}

void Time::SetSecond(const int second)
{
	if (second < 0 || second > 59)
	{
		string message = "����� " + to_string(second) +
			" �� ������ � ���������� �������� �������� [0, 59]\n"
			"� �� ����� ���������� �������";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_second = second;
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

int Time::GetSecond()
{
	return _second;
}

Time::Time()
{
	SetYear(2020);
	SetMonth(12);
	SetDay(31);
	SetHour(23);
	SetMinute(59);
	SetSecond(59);
}

Time::Time(const int year, const int month, const int day,
	const int hour, const int minute, const int second)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
	SetHour(hour);
	SetMinute(minute);
	SetSecond(second);
}

string Time::GetTime()
{
	return to_string(_year) + "." + to_string(_month) 
		+ "." + to_string(_day) + " " + to_string(_hour) 
		+ ":" + to_string( _minute) + ":" + to_string(_second);
}
