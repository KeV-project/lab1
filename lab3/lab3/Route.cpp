#include "Route.h"

void Route::SetNumber(const int number)
{
	//TODO: Дубль
	if (number <= 0)
	{
		string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(number) +
			" не является положительным\nи не может определять номер рейса";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_number = number;
}

void Route::SetDuration(const int duration)
{
	//TODO: Дубль
	if (duration <= 0)
	{
		string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(duration) +
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
	//TODO: Дубль
	if (periodicity <= 0)
	{
		string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(periodicity) +
			" не является положительным\n"
			"и не может определять периодичность рейса";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_periodicity = periodicity;
}

void Route::SetStops(string* stops, const int stopsCount)
{
	//TODO: Сообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы
	//TODO: Дубль
	if (stopsCount < 2 || stopsCount > 10)
	{
		string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(stopsCount) +
			"\nне входит в допустимый диапазон значений [2, 10]";
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
	SetStops(nullptr, 2);
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
	delete [] _stops;
}

void Route::ReadRouteFromConsole()
{
	//TODO: Много дублей
	//TODO: Этот метод не должен тут находиться, т.к. таким образов вы прикалачиваете его к консоли, консольный ввод лучше вынести 
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
			}
		}
		else
		{
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные" << endl;
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
			}
		}
		else
		{
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные" << endl;
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
			}
		}
		else
		{
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные" << endl;
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите количество остановок рейса: ";
		int stopsCount = 0;
		cin >> stopsCount;
		cout << endl;
		if (IsValue() && stopsCount >= 2)
		{
			string* stops = new string[stopsCount];
			for (int i = 0; i < stopsCount; i++)
			{
				cout << "Введите остановку №" << i + 1 << ": ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, stops[i], '\n');
				cin.clear();
				cout << endl;
			}
			SetStops(stops, stopsCount);
			break;
		}
		else
		{
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные" << endl;
			cout << "Пожалуйста, введите целое число в диапазоне [2, 10]";
			cout << endl << endl;
		}
	} while (true);
}

void Route::WriteRouteToConsole()
{
	//TODO: Этот метод не должен тут находиться, т.к. таким образов вы прикалачиваете его к консоли, консольный ввод лучше вынести 
	cout << "Рейс №" << this->_number << " (" << this->_stops[0];
	cout << " - " << this->_stops[_stopsCount - 1] << ") находится в пути ";
	cout << this->_durationInMinutes << " минут, " << endl;
	cout << "отпраляется на маршрут с периодичностью в ";
	cout << this->_periodicity << " минут. " << endl;
	cout << "Маршрут включает " << this->_stopsCount << " остановок";
	cout << endl << endl;
}

int FindRouteTo(Route* routes,
	const int routesCount, const string& findedStop)
{
	for (int i = 0; i < routesCount; i++)
	{
		for (int j = 0; j < routes[i].GetStopsCount(); j++)
		{
			if (routes[i].GetStops()[j] == findedStop)
			{
				return i;
			}
		}
	}
	return -1;
}