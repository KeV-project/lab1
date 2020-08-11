#include "Time.h"

void SetYear(Time& event, const int year)
{
	if (year <= 0)
	{
		throw exception("Поле год не может быть задано" 
			" числом меньше или равным 0");
	}
	event.Year = year;
}

void SetMonth(Time& event, const int month)
{
	if (month < 1 || month > 12)
	{
		throw exception("Поле месяц должно быть"
			" числом в промежутке [1, 12]");
	}
	event.Month = month;
}

void SetDay(Time& event, const int day)
{
	if (day < 1 || day > 31)
	{
		throw exception("Поле день должно быть"
			" числом в промежутке [1, 31]");
	}
	event.Day = day;
}

void SetHour(Time& event, const int hour)
{
	if (hour < 0 || hour > 23)
	{
		throw exception("Поле час должно быть"
			" числом в промежутке [0, 23]");
	}
	event.Hour = hour;
}

void SetMinute(Time& event, const int minute)
{
	if (minute < 0 || minute > 59)
	{
		throw exception("Поле минута должно быть"
			" числом в промежутке [0, 59]");
	}
	event.Minute = minute;
}

void SetSecond(Time& event, const int second)
{
	if (second < 0 || second > 59)
	{
		throw exception("Поле секунда должно быть"
			" числом в промежутке [0, 59]");
	}
	event.Second = second;
}

Time* MakeTime(const int year, const int month, const int day,
	const int hour, const int minute, const int second)
{
	Time* event = new Time();
	SetYear(*event, year);
	SetMonth(*event, month);
	SetDay(*event, day);
	SetHour(*event, hour);
	SetMinute(*event, minute);
	SetSecond(*event, second);
	return event;
}

Time* CopyTime(const Time& event)
{
	Time* copiedTime = new Time();
	copiedTime->Year = event.Year;
	copiedTime->Month = event.Month;
	copiedTime->Day = event.Day;
	copiedTime->Hour = event.Hour;
	copiedTime->Minute = event.Minute;
	copiedTime->Second = event.Second;
	return copiedTime;
}

Time* ReadTime()
{
	Time* event = new Time;
	do
	{
		cout << "Год: ";
		int year = 0;
		cin >> year;
		cout << endl;
		if (IsValue())
		{
			try
			{
				SetYear(*event, year);
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
			break;
		}
		else
		{
			cout << "Введено некорректное значение" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Месяц: ";
		int month = 0;
		cin >> month;
		cout << endl;
		if (IsValue())
		{
			try
			{
				SetMonth(*event, month);
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
			break;
		}
		else
		{
			cout << "Введено некорректное значение" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "День: ";
		int day = 0;
		cin >> day;
		cout << endl;
		if (IsValue())
		{
			try
			{
				SetDay(*event, day);
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
			break;
		}
		else
		{
			cout << "Введено некорректное значение" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Час: ";
		int hour = 0;
		cin >> hour;
		cout << endl;
		if (IsValue())
		{
			try
			{
				SetHour(*event, hour);
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
			break;
		}
		else
		{
			cout << "Введено некорректное значение" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Минута: ";
		int minute = 0;
		cin >> minute;
		cout << endl;
		if (IsValue())
		{
			try
			{
				SetMinute(*event, minute);
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
			break;
		}
		else
		{
			cout << "Введено некорректное значение" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Секунда: ";
		int second = 0;
		cin >> second;
		cout << endl;
		if (IsValue())
		{
			try
			{
				SetSecond(*event, second);
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
			break;
		}
		else
		{
			cout << "Введено некорректное значение" << endl << endl;
		}
	} while (true);
	return event;
}

void PrintTime(const Time& event)
{
	cout << "Год: " << event.Year << endl;
	cout << "Месяц: " << event.Month << endl;
	cout << "День: " << event.Day << endl;
	cout << "Час: " << event.Hour << endl;
	cout << "Минута: " << event.Minute << endl;
	cout << "Секунда: " << event.Second << endl << endl;
}

void ChangeTime(Time* event, const int year, const int month,
	const int day, const int hour, const int minute, const int second)
{
	SetYear(*event, year);
	SetMonth(*event, month);
	SetDay(*event, day);
	SetHour(*event, hour);
	SetMinute(*event, minute);
	SetSecond(*event, second);
}

void DemoTime()
{
	// Task 2.2.3.1
	Time firstEvent;
	SetYear(firstEvent, 2005);
	SetMonth(firstEvent, 12);
	SetDay(firstEvent, 5);
	SetHour(firstEvent, 13);
	SetMinute(firstEvent, 23);
	SetSecond(firstEvent, 17);

	// Task 2.2.3.2
	cout << "СОБЫТИЕ" << endl << endl;
	Time* secondEvent = ReadTime();
	PrintTime(*secondEvent);
	delete secondEvent;
	PrintLine();
	
	// Task 2.2.3.3
	const int eventsCount = 3;
	Time** events = new Time * [eventsCount]
	{
		MakeTime(2015, 10, 12, 1, 30, 12),
		MakeTime(2020, 6, 8, 10, 10, 7),
		MakeTime(1995, 12, 31, 23, 59, 0),
	};
	cout << "Массив событий: " << endl << endl;
	for (int i = 0; i < eventsCount; i++)
	{
		cout << "Событие №" << i + 1 << ":" << endl << endl;
		PrintTime(*events[i]);
	}
	PrintLine();
	for (int i = 0; i < eventsCount; i++)
	{
		delete events[i];
	}
	delete[] events;

	// Task 2.2.4.1
	cout << "Работа с указателем на структуру:" << endl << endl;
	Time* pFirstEvent = &firstEvent;
	cout << "Прямоугольник firstEvent: " << endl << endl;
	PrintTime(firstEvent);
	cout << "Измененное событие firstEvent: " << endl << endl;
	//TODO: Может прилететь исключение - нужна проверка. +
	ChangeTime(pFirstEvent, 2020, 12, 10, 5, 30, 1);
	PrintTime(*pFirstEvent);
	PrintLine();

	// Task 2.2.4.2
	Time* pFirstEvent2 = &firstEvent;
	cout << "Адрес переменной firstEvent: ";
	cout << &firstEvent << endl << endl;
	cout << "Адрес в указателе pFirstEvent: ";
	cout << pFirstEvent << endl << endl;
	cout << "Адрес в указателе pFirstEvent2: ";
	cout << pFirstEvent2 << endl << endl;
	PrintLine();
}


