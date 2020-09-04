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
	if (IsValueInRange(year, _departureTime.GetYear(), 2021))
	{
		string message = MakeMessage(_departureTime, 
			_destinationTime, year, InvalidYear);
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	else if (year == _departureTime.GetYear())
	{
		//TODO: Дубль +
		if (IsValueInRange(month, _departureTime.GetMonth(), 12))
		{
			string message = MakeMessage(_departureTime,
				_destinationTime, month, InvalidMonth);
			char buf[255];
			strcpy_s(buf, message.c_str());
			throw exception(buf);
		}
		else if (month == _departureTime.GetMonth())
		{
			//TODO: Дубль +
			if (IsValueInRange(day, _departureTime.GetDay(), 31))
			{
				string message = MakeMessage(_departureTime,
					_destinationTime, day, InvalidDay);
				char buf[255];
				strcpy_s(buf, message.c_str());
				throw exception(buf);
			}
			else if (day == _departureTime.GetDay())
			{
				//TODO: Дубль +
				if (IsValueInRange(hour, _departureTime.GetHour(), 23))
				{
					string message = MakeMessage(_departureTime,
						_destinationTime, hour, InvalidHour);
					char buf[255];
					strcpy_s(buf, message.c_str());
					throw exception(buf);
				}
				else if (hour == _departureTime.GetHour())
				{
					//TODO: Дубль +
					if (IsValueInRange(minute, _departureTime.GetMinute(), 59))
					{
						string message = MakeMessage(_departureTime,
							_destinationTime, minute, InvalidMinute);
						char buf[255];
						strcpy_s(buf, message.c_str());
						throw exception(buf);
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
	//TODO: RSDN
	int DifHour = 0;
	int DifMinute = 0;
	DifHour = this->_destinationTime.GetHour() - this->_departureTime.GetHour();
	DifMinute = this->_destinationTime.GetMinute() 
		- this->_departureTime.GetMinute();
	return DifMinute + DifHour * 60;
}