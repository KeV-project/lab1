#include "Time.h"

//TODO: ��������� +
Time* MakeTime(const int year, const int month, const int day,
	const int hour, const int minute, const int second)
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

Time* CopyTime(const Time& time)
{
	Time* copiedTime = new Time();
	copiedTime->Year = time.Year;
	copiedTime->Month = time.Month;
	copiedTime->Day = time.Day;
	copiedTime->Hour = time.Hour;
	copiedTime->Minute = time.Minute;
	copiedTime->Second = time.Second;
	return copiedTime;
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

void PrintTime(const Time& event)
{
	cout << "���: " << event.Year << endl;
	cout << "�����: " << event.Month << endl;
	cout << "����: " << event.Day << endl;
	cout << "���: " << event.Hour << endl;
	cout << "������: " << event.Minute << endl;
	cout << "�������: " << event.Second << endl << endl;
}

//TODO: ���������
void ChangeTime(Time* event, int year, int month, int day,
	int hour, int minute, int second)
{
	//TODO: ��� ������� �������� �� ���������� ��������, �������� ������ �������� 0 � ������ 12 � month � �.�.
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

	// Task 2.2.4.1
	cout << "������ � ���������� �� ���������:" << endl << endl;
	Time* pFirstEvent = &firstEvent;
	cout << "������������� firstEvent: " << endl << endl;
	PrintTime(firstEvent);
	cout << "���������� ������� firstEvent: " << endl << endl;
	ChangeTime(pFirstEvent, 2020, 12, 10, 5, 30, 1);
	PrintTime(*pFirstEvent);
	PrintLine();

	// Task 2.2.4.2
	Time* pFirstEvent2 = &firstEvent;
	cout << "����� ���������� firstEvent: ";
	cout << &firstEvent << endl << endl;
	cout << "����� � ��������� pFirstEvent: ";
	cout << pFirstEvent << endl << endl;
	cout << "����� � ��������� pFirstEvent2: ";
	cout << pFirstEvent2 << endl << endl;
	PrintLine();
}


