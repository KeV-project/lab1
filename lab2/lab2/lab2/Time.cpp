#include "Time.h"

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
}


