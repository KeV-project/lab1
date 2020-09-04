#include "Time.h"

void Time::SetYear(const int year)
{
	//TODO: ����� +
	int const minYear = 0;
	int const maxYear = 2020;
	if (!IsValueInRange(year, minYear, maxYear))
	{
		char message[255];
		strcpy_s(message, MakeMessage(year, minYear,
			maxYear, "���").c_str());
		throw exception(message);
	}
	this->_year = year;
}

void Time::SetMonth(const int month)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minMonth = 1;
	int const maxMonth = 12;
	if (!IsValueInRange(month, minMonth, maxMonth))
	{
		char message[255];
		strcpy_s(message, MakeMessage(month, minMonth,
			maxMonth, "�����").c_str());
		throw exception(message);
	}
	this->_month = month;
}

void Time::SetDay(const int day)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minDay = 1;
	int const maxDay = 31;
	if (!IsValueInRange(day, minDay, maxDay))
	{
		char message[255];
		strcpy_s(message, MakeMessage(day, minDay,
			maxDay, "����").c_str());
		throw exception(message);
	}
	this->_day = day;
}

void Time::SetHour(const int hour)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minHour = 0;
	int const maxHour = 23;
	if (!IsValueInRange(hour, minHour, maxHour))
	{
		char message[255];
		strcpy_s(message, MakeMessage(hour, minHour,
			maxHour, "���").c_str());
		throw exception(message);
	}
	this->_hour = hour;
}

void Time::SetMinute(const int minute)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minMinute = 0;
	int const maxMinute = 59;
	if (!IsValueInRange(minute, minMinute, maxMinute))
	{
		char message[255];
		strcpy_s(message, MakeMessage(minute, minMinute,
			maxMinute, "������").c_str());
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
