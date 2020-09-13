#include "Time.h"

void Time::SetYear(const int year)
{
	this->_year = year;
}

void Time::SetMonth(const int month)
{
	int const minMonth = 1;
	int const maxMonth = 12;
	ValueValidator::AssertValueInRange(month, minMonth,
		maxMonth, NotInRange, "мес€ц");
	this->_month = month;
}

void Time::SetDay(const int day)
{
	int const minDay = 1;
	int const maxDay = 31;
	ValueValidator::AssertValueInRange(day, minDay,
		maxDay, NotInRange, "день");
	this->_day = day;
}

void Time::SetHour(const int hour)
{
	int const minHour = 0;
	int const maxHour = 23;
	ValueValidator::AssertValueInRange(hour, minHour,
		maxHour, NotInRange, "час");
	this->_hour = hour;
}

void Time::SetMinute(const int minute)
{
	int const minMinute = 0;
	int const maxMinute = 59;
	ValueValidator::AssertValueInRange(minute, minMinute,
		maxMinute, NotInRange, "минуты");
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

string Time::GetTime()
{
	return to_string(_year) + "." + to_string(_month)
		+ "." + to_string(_day) + " " + to_string(_hour)
		+ ":" + to_string(_minute);
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

bool Time::IsTimeBeforeThen(Time& time)
{
	ValueValidator::AssertValueInRange(_year, -2400, time.GetYear(),
		InvalidTime, "год");
	if (time.GetYear() == _year)
	{
		ValueValidator::AssertValueInRange(_month, 1, time.GetMonth(),
			InvalidTime, "мес€ц");
		if (time.GetMonth() == _month)
		{
			ValueValidator::AssertValueInRange(_day, 1, time.GetDay(),
				InvalidTime, "день");
			if (time.GetDay() == _day)
			{
				ValueValidator::AssertValueInRange(_hour, 0, 
					time.GetHour(), InvalidTime, "час");
				if (time.GetHour() == _hour)
				{
					ValueValidator::AssertValueInRange(_minute, 1, 
						time.GetMinute(), InvalidTime, "минуты");
				}
			}
		}
	}
	return true;
}
