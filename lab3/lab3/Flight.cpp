#include "Flight.h"

void Flight::SetNumber(const int number)
{
	//TODO: Дубль +
	int const minNumber = 0;
	int const maxNumber = 1000000;
	AssertValueInRange(number, minNumber,
		maxNumber, NotInRange, "номер рейса");
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
	const int day, const int hour, const int minute)
{
	this->_departureTime.SetYear(year);
	this->_departureTime.SetMonth(month);
	this->_departureTime.SetDay(day);
	this->_departureTime.SetHour(hour);
	this->_departureTime.SetMinute(minute);
}

void Flight::SetDestinationTime(const int year, const int month,
	const int day, const int hour, const int minute)
{
	//TODO: вообще не понял - что за логика тут закладывается, надо обсудить. 
	AssertValueInRange(_departureTime.GetYear(), 0, year,
		InvalidTime, "год");
	if (year == _departureTime.GetYear())
	{
		AssertValueInRange(_departureTime.GetMonth(), 1, month,
			InvalidTime, "месяц");
		if (month == _departureTime.GetMonth())
		{
			AssertValueInRange(_departureTime.GetDay(), 1, day,
				InvalidTime, "день");
			if (day == _departureTime.GetDay())
			{
				AssertValueInRange(_departureTime.GetHour(), 0, hour,
					InvalidTime, "час");
				if (hour == _departureTime.GetHour())
				{
					AssertValueInRange(_departureTime.GetMinute(), 1, minute,
						InvalidTime, "минуты");
				}
			}
		}
	}
	_destinationTime.SetYear(year);
	_destinationTime.SetMonth(month);
	_destinationTime.SetDay(day);
	_destinationTime.SetHour(hour);
	_destinationTime.SetMinute(minute);
}

void Flight::SetTime(const int departureYear, const int departureMonth,
	const int departureDay, const int departureHour,
	const int departureMinute, const int destinationYear,
	const int destinationMonth, const int destinationDay,
	const int destinationHour, const int destinationMinute)
{
	SetDepartureTime(departureYear, departureMonth, 
		departureDay, departureHour, departureMinute);
	SetDestinationTime(destinationYear, destinationMonth, 
		destinationDay, destinationHour, destinationMinute);
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
	SetDepartureTime(1, 1, 1, 1, 1);
	SetDestinationTime(2020, 12, 31, 23, 59);
}

Flight::Flight(const int number, const string& departure,
	const string& destination, const int departureYear,
	const int departureMonth, const int departureDay,
	const int departureHour, const int departureMinute,
	const int destinationYear, const int destinationMonth, 
	const int destinationDay, const int destinationHour, 
	const int destinationMinute)
{
	SetNumber(number);
	SetDeparture(departure);
	SetDestination(destination);
	SetDepartureTime(departureYear, departureMonth,
		departureDay, departureHour, departureMinute);
	SetDestinationTime(destinationYear, destinationMonth, 
		destinationDay, destinationHour, destinationMinute);
}

void Flight::ChangeFlight(const int number, const string& departure,
	const string& destination, const int departureYear,
	const int departureMonth, const int departureDay,
	const int departureHour, const int departureMinute,
	const int destinationYear, const int destinationMonth,
	const int destinationDay, const int destinationHour,
	const int destinationMinute)
{
	SetNumber(number);
	SetDeparture(departure);
	SetDestination(destination);
	SetDepartureTime(departureYear, departureMonth,
		departureDay, departureHour, departureMinute);
	SetDestinationTime(destinationYear, destinationMonth,
		destinationDay, destinationHour, destinationMinute);
}

int Flight::GetFlightTimeMinutes()
{
	//TODO: RSDN - локальные переменные + их можно сразу проиницииализировать подходящими значениями
	int DifHour = 0;
	int DifMinute = 0;
	DifHour = _destinationTime.GetHour() - _departureTime.GetHour();
	DifMinute = _destinationTime.GetMinute() 
		- _departureTime.GetMinute();
	return DifMinute + DifHour * 60;
}