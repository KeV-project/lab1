#include "Time.h"

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
}


