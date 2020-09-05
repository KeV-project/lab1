#include "Flight.h"

void Flight::SetNumber(const int number)
{
	//TODO: Дубль +
	int const minNumber = 0;
	int const maxNumber = 1000000;
	if (!IsValueInRange(number, minNumber, maxNumber))
	{
		char message[255];
		strcpy_s(message, MakeMessage(number, minNumber,
			maxNumber, "номер рейса").c_str());
		throw exception(message);
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
	//TODO: Дубль +
	if (!IsValueInRange(year, _departureTime.GetYear(), 2021))
	{
		char message[255];
		strcpy_s(message, MakeMessage(_departureTime.GetYear(),
			_departureTime.GetMonth(), _departureTime.GetDay(),
			_departureTime.GetHour(), _departureTime.GetMinute(),
			year, month, day, hour, minute, InvalidYear).c_str());
		throw exception(message);
	}
	else if (year == _departureTime.GetYear())
	{
		//TODO: Дубль +
		if (!IsValueInRange(month, _departureTime.GetMonth(), 12))
		{
			char message[255];
			strcpy_s(message, MakeMessage(_departureTime.GetYear(),
				_departureTime.GetMonth(), _departureTime.GetDay(),
				_departureTime.GetHour(), _departureTime.GetMinute(),
				year, month, day, hour, minute, InvalidMonth).c_str());
			throw exception(message);
		}
		else if (month == _departureTime.GetMonth())
		{
			//TODO: Дубль +
			if (!IsValueInRange(day, _departureTime.GetDay(), 31))
			{
				char message[255];
				strcpy_s(message, MakeMessage(_departureTime.GetYear(),
					_departureTime.GetMonth(), _departureTime.GetDay(),
					_departureTime.GetHour(), _departureTime.GetMinute(),
					year, month, day, hour, minute, InvalidDay).c_str());
				throw exception(message);
			}
			else if (day == _departureTime.GetDay())
			{
				//TODO: Дубль +
				if (!IsValueInRange(hour, _departureTime.GetHour(), 23))
				{
					char message[255];
					strcpy_s(message, MakeMessage(_departureTime.GetYear(),
						_departureTime.GetMonth(), _departureTime.GetDay(),
						_departureTime.GetHour(), _departureTime.GetMinute(),
						year, month, day, hour, minute, InvalidHour).c_str());
					throw exception(message);
				}
				else if (hour == _departureTime.GetHour())
				{
					//TODO: Дубль +
					if (!IsValueInRange(minute, _departureTime.GetMinute(), 59))
					{
						char message[255];
						strcpy_s(message, MakeMessage(_departureTime.GetYear(),
							_departureTime.GetMonth(), _departureTime.GetDay(),
							_departureTime.GetHour(), _departureTime.GetMinute(),
							year, month, day, hour, minute, InvalidMinute).c_str());
						throw exception(message);
					}
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
	//TODO: RSDN +
	int DifHour = 0;
	int DifMinute = 0;
	DifHour = _destinationTime.GetHour() - _departureTime.GetHour();
	DifMinute = _destinationTime.GetMinute() 
		- _departureTime.GetMinute();
	return DifMinute + DifHour * 60;
}