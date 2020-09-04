#include "Route.h"

void Route::SetNumber(const int number)
{
	//TODO: Дубль +
	int const minLimit = 0;
	int const maxLimit = 1000000;
	if (!IsValueInRange(number, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(number, minLimit,
			maxLimit, "номер рейса").c_str());
		throw exception(message);
	}
	this->_number = number;
}

void Route::SetDuration(const int duration)
{
	//TODO: Дубль +
	int const minLimit = 1;
	int const maxLimit = 2147483647;
	if (!IsValueInRange(duration, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(duration, NotPositive,
			"продолжительность рейса").c_str());
		throw exception(message);
	}
	this->_durationInMinutes = duration;
}

void Route::SetPeriodicity(const int periodicity)
{
	//TODO: Дубль +
	int const minLimit = 1;
	int const maxLimit = 2147483647;
	if (!IsValueInRange(periodicity, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(periodicity, NotPositive,
			"периодичность рейса").c_str());
		throw exception(message);
	}
	this->_periodicity = periodicity;
}

void Route::SetStops(string* stops, const int stopsCount)
{
	//TODO: Сообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы +
	//TODO: Дубль +
	int const minLimit = 2;
	int const maxLimit = 10;
	if (!IsValueInRange(stopsCount, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(stopsCount, minLimit,
			maxLimit, "количество остановок").c_str());
		throw exception(message);
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