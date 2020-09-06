#include "Time.h"

void Time::SetYear(const int year)
{
	//TODO: ����� +
	int const minYear = 0;
	int const maxYear = 2021;
	AssertValueInRange(year, minYear,
		maxYear, NotInRange, "���");
	this->_year = year;
}

void Time::SetMonth(const int month)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minMonth = 1;
	int const maxMonth = 12;
	AssertValueInRange(month, minMonth,
		maxMonth, NotInRange, "�����");
	this->_month = month;
}

void Time::SetDay(const int day)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minDay = 1;
	int const maxDay = 31;
	AssertValueInRange(day, minDay,
		maxDay, NotInRange, "����");
	this->_day = day;
}

void Time::SetHour(const int hour)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minHour = 0;
	int const maxHour = 23;
	AssertValueInRange(hour, minHour,
		maxHour, NotInRange, "���");
	this->_hour = hour;
}

void Time::SetMinute(const int minute)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minMinute = 0;
	int const maxMinute = 59;
	AssertValueInRange(minute, minMinute,
		maxMinute, NotInRange, "������");
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
	SetYear(2021);
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
