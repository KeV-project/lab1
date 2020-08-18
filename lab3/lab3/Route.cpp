#include "Route.h"

void Route::SetNumber(const int number)
{
	if (number <= 0)
	{
		string message = "Число " + to_string(number) +
			" не является положительным\nи не может определять номер рейса";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_number = number;
}

void Route::SetDuration(const int duration)
{
	if (duration <= 0)
	{
		string message = "Число " + to_string(duration) +
			" не является положительным числом\n"
			"и не может определять продолжительность рейса";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_durationInMinutes = duration;
}

void Route::SetPeriodicity(const int periodicity)
{
	if (periodicity <= 0)
	{
		string message = "Число " + to_string(periodicity) +
			" не является положительным числом\n"
			"и не может определять периодичность рейса";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_periodicity = periodicity;
}

void Route::SetStops(string* stops, const int stopsCount)
{
	if (stopsCount < 0 || stopsCount > 10)
	{
		string message = "Число " + to_string(stopsCount) +
			" не входит в допустимый диапазон значений [0, 10]";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_stopsCount = stopsCount;
	this->_stops = stops;
}

int Route::GetNumber()
{
	return this->_number;
}

int Route::GetDuration()
{
	return this->_durationInMinutes;
}

int Route::GetPeriodicity()
{
	return this->_periodicity;
}

int Route::GetStopsCount()
{
	return this->_stopsCount;
}

string* Route::GetStops()
{
	return this->_stops;
}

Route::Route()
{
	SetNumber(1);
	SetDuration(1);
	SetPeriodicity(1);
	SetStops(nullptr, 0);
}

Route::Route(const int number, const int duration, const int periodicity,
	const int stopsCount, string* stops)
{
	SetNumber(number);
	SetDuration(duration);
	SetPeriodicity(periodicity);
	SetStops(stops, stopsCount);
}

Route::~Route()
{
	delete [] this->_stops;
}

void Route::ReadRouteFromConsole()
{
	do
	{
		cout << "Введите номер рейса: ";
		int number = 0;
		cin >> number;
		cout << endl;
		if (IsValue())
		{
			try
			{
				SetNumber(number);
				break;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
		}
		else
		{
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите продолжительность рейса: ";
		int duration = 0;
		cin >> duration;
		cout << endl;
		if (IsValue())
		{
			try
			{
				SetDuration(duration);
				break;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
		}
		else
		{
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите периодичность рейса: ";
		int periodicity = 0;
		cin >> periodicity;
		cout << endl;
		if (IsValue())
		{
			try
			{
				SetPeriodicity(periodicity);
				break;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
		}
		else
		{
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите количество остановок рейса: ";
		int stopsCount = 0;
		cin >> stopsCount;
		cout << endl;
		if (IsValue() && stopsCount >= 0)
		{
			string* stops = nullptr;
			if (stopsCount > 0)
			{
				stops = new string[stopsCount];
				for (int i = 0; i < stopsCount; i++)
				{
					cout << "Введите остановку №" << i + 1 << ": ";
					cin >> stops[i];
					cout << endl;
				}
			}
			SetStops(stops, stopsCount);
			break;
		}
		else
		{
			cout << "Пожалуйста, введите положительное целое число";
			cout << endl << endl;
		}
	} while (true);
}

void Route::WriteRouteToConsole()
{
	cout << "Рейс №" << this->_number << " (" << this->_stops[0];
	cout << " - " << this->_stops[_stopsCount - 1] << ") находится в пути ";
	cout << this->_durationInMinutes << " минут, " << endl;
	cout << "отпраляется на маршрут с периодичностью в ";
	cout << this->_periodicity << " минут. " << endl;
	cout << "Маршрут включает " << this->_stopsCount << " остановок";
	cout << endl << endl;
}
