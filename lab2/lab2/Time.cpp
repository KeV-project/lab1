#include "Time.h"

Time* MakeTime(int year, int month, int day,
	int hour, int minute, int second)
{
	Time* time = new Time();
	time->Year = year;
	time->Month = month;
	time->Day = day;
	time->Hour = hour;
	time->Minute = minute;
	time->Second = second;
	return time;
}

void ReadTime(Time& event)
{
	cout << "Год: ";
	cin >> event.Year;
	cout << endl;
	cout << "Месяц: ";
	cin >> event.Month;
	cout << endl;
	cout << "День: ";
	cin >> event.Day;
	cout << endl;
	cout << "Час: ";
	cin >> event.Hour;
	cout << endl;
	cout << "Минута: ";
	cin >> event.Minute;
	cout << endl;
	cout << "Секунда: ";
	cin >> event.Second;
	cout << endl;
}

void PrintTime(Time& event)
{
	cout << "Год: " << event.Year << endl;
	cout << "Месяц: " << event.Month << endl;
	cout << "День: " << event.Day << endl;
	cout << "Час: " << event.Hour << endl;
	cout << "Минута: " << event.Minute << endl;
	cout << "Секунда: " << event.Second << endl << endl;
}

void ChangeTime(Time* event, int year, int month, int day,
	int hour, int minute, int second)
{
	event->Year = year;
	event->Month = month;
	event->Day = day;
	event->Hour = hour;
	event->Minute = minute;
	event->Second = second;
}

void DemoTime()
{
	// Task 2.2.3.1
	Time firstEvent;
	firstEvent.Year = 2003;
	firstEvent.Month = 10;
	firstEvent.Day = 13;
	firstEvent.Hour = 22;
	firstEvent.Minute = 54;
	firstEvent.Second = 11;

	// Task 2.2.3.2
	Time secondEvent;
	cout << "СОБЫТИЕ" << endl << endl;
	ReadTime(secondEvent);
	PrintTime(secondEvent);
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


