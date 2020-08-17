#include "Flight.h"

void Flight::SetNumber(const int number)
{
	if (number < 0)
	{
		string message = "Отрицательное число " + to_string(number) +
			" не может определять номер рейса";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_number = number;
}

void Flight::SetDeparture(const string& departure)
{
	this->_departure = departure;
}

void Flight::SetDestination(const string& destination)
{
	this->_destination = destination;
}

void Flight::SetDepartureTime(const int year, const int month,
	const int day, const int hour, const int minute, const int second)
{
	this->_departureTime.SetYear(year);
	this->_departureTime.SetMonth(month);
	this->_departureTime.SetDay(day);
	this->_departureTime.SetHour(hour);
	this->_departureTime.SetMinute(minute);
	this->_departureTime.SetSecond(second);
}

void Flight::SetDestinationTime(const int year, const int month,
	const int day, const int hour, const int minute, const int second)
{
	if (year < this->_departureTime.GetYear())
	{
		string message = "Год прибытия: " + to_string(year) 
			+ " предшествует году вылета: " 
			+ to_string(_departureTime.GetYear());
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	else if (year == this->_departureTime.GetYear())
	{
		if (month < this->_departureTime.GetMonth())
		{
			string message = "Месяц прибытия: " 
				+ to_string(_destinationTime.GetYear()) + "." 
				+ to_string(month) + " предшествует месяцу вылета: "
				+ to_string(_departureTime.GetYear()) + "."
				+ to_string(_departureTime.GetMonth());
			char buf[255];
			strcpy_s(buf, message.c_str());
			throw exception(buf);
		}
		else if (month == this->_departureTime.GetMonth())
		{
			if (day < this->_departureTime.GetDay())
			{
				string message = "Дата прибытия: "
					+ to_string(_destinationTime.GetYear()) + "."
					+ to_string(_destinationTime.GetMonth()) + "."
					+ to_string(day) + " предшествует дате вылета: "
					+ to_string(_departureTime.GetYear()) + "."
					+ to_string(_departureTime.GetMonth()) + "."
					+ to_string(_departureTime.GetDay());
				char buf[255];
				strcpy_s(buf, message.c_str());
				throw exception(buf);
			}
			else if (day == this->_departureTime.GetDay())
			{
				if (hour < this->_departureTime.GetHour())
				{
					string message = "Время прибытия: "
						+ to_string(_destinationTime.GetYear()) + "."
						+ to_string(_destinationTime.GetMonth()) + "."
						+ to_string(_destinationTime.GetDay())
						+ to_string(hour) + "ч"
						+ " предшествует времени вылета: "
						+ to_string(_departureTime.GetYear()) + "."
						+ to_string(_departureTime.GetMonth()) + "."
						+ to_string(_departureTime.GetDay())
						+ to_string(_departureTime.GetHour());
					char buf[255];
					strcpy_s(buf, message.c_str());
					throw exception(buf);
				}
				else if (hour == this->_departureTime.GetHour())
				{
					if (minute < this->_departureTime.GetMinute())
					{
						string message = "Время прибытия: "
							+ to_string(_destinationTime.GetYear()) + "."
							+ to_string(_destinationTime.GetMonth()) + "."
							+ to_string(_destinationTime.GetDay())
							+ to_string(_destinationTime.GetHour()) + ":"
							+ to_string(minute)
							+ " предшествует времени вылета: "
							+ to_string(_departureTime.GetYear()) + "."
							+ to_string(_departureTime.GetMonth()) + "."
							+ to_string(_departureTime.GetDay())
							+ to_string(_departureTime.GetHour())
							+ to_string(_departureTime.GetMinute());
						char buf[255];
						strcpy_s(buf, message.c_str());
						throw exception(buf);
					}
					else if (minute == this->_departureTime.GetMinute())
					{
						if (second < this->_departureTime.GetSecond())
						{
							string message = "Время прибытия: "
								+ to_string(_destinationTime.GetYear()) + "."
								+ to_string(_destinationTime.GetMonth()) + "."
								+ to_string(_destinationTime.GetDay())
								+ to_string(_destinationTime.GetHour()) + ":"
								+ to_string(_destinationTime.GetMinute())
								+ to_string(second)
								+ " предшествует времени вылета: "
								+ to_string(_departureTime.GetYear()) + "."
								+ to_string(_departureTime.GetMonth()) + "."
								+ to_string(_departureTime.GetDay())
								+ to_string(_departureTime.GetHour())
								+ to_string(_departureTime.GetMinute())
								+ to_string(_departureTime.GetSecond());
							char buf[255];
							strcpy_s(buf, message.c_str());
							throw exception(buf);
						}
					}
				}
			}
		}
	}
	this->_destinationTime.SetYear(year);
	this->_destinationTime.SetMonth(month);
	this->_destinationTime.SetDay(day);
	this->_destinationTime.SetHour(hour);
	this->_destinationTime.SetMinute(minute);
	this->_destinationTime.SetSecond(second);
}

int Flight::GetNumber()
{
	return _number;
}

string Flight::GetDeparture()
{
	return _departure;
}

string Flight::GetDestination()
{
	return _destination;
}

Time Flight::GetDepartureTime()
{
	return _departureTime;
}

Time Flight::GetDestinationTime()
{
	return _destinationTime;
}

Flight::Flight()
{
	SetNumber(0);
	SetDeparture("");
	SetDestination("");
	SetDepartureTime(1, 1, 1, 1, 1, 1);
	SetDestinationTime(2020, 12, 31, 23, 59, 59);
}

Flight::Flight(const int number, const string& departure,
	const string& destination, const int departureYear,
	const int departureMonth, const int departureDay,
	const int departureHour, const int departureMinute,
	const int departureSecond, const int destinationYear,
	const int destinationMonth, const int destinationDay,
	const int destinationHour, const int destinationMinute,
	const int destinationSecond)
{
	SetNumber(number);
	SetDeparture(departure);
	SetDestination(destination);
	SetDepartureTime(departureYear, departureMonth,
		departureDay, departureHour, departureMinute,
		departureSecond);
	SetDestinationTime(destinationYear, destinationMonth, 
		destinationDay, destinationHour, destinationMinute,
		destinationSecond);
}
