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
	cout << "���: ";
	cin >> event.Year;
	cout << endl;
	cout << "�����: ";
	cin >> event.Month;
	cout << endl;
	cout << "����: ";
	cin >> event.Day;
	cout << endl;
	cout << "���: ";
	cin >> event.Hour;
	cout << endl;
	cout << "������: ";
	cin >> event.Minute;
	cout << endl;
	cout << "�������: ";
	cin >> event.Second;
	cout << endl;
}

void PrintTime(Time& event)
{
	cout << "���: " << event.Year << endl;
	cout << "�����: " << event.Month << endl;
	cout << "����: " << event.Day << endl;
	cout << "���: " << event.Hour << endl;
	cout << "������: " << event.Minute << endl;
	cout << "�������: " << event.Second << endl << endl;
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
	cout << "�������" << endl << endl;
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
	cout << "������ �������: " << endl << endl;
	for (int i = 0; i < eventsCount; i++)
	{
		cout << "������� �" << i + 1 << ":" << endl << endl;
		PrintTime(*events[i]);
	}
	PrintLine();
	for (int i = 0; i < eventsCount; i++)
	{
		delete events[i];
	}
	delete[] events;
}


