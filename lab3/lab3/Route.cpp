#include "Route.h"

void Route::SetNumber(const int number)
{
	if (number <= 0)
	{
		string message = "����� " + to_string(number) +
			" �� �������� �������������\n� �� ����� ���������� ����� �����";
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
		string message = "����� " + to_string(duration) +
			" �� �������� ������������� ������\n"
			"� �� ����� ���������� ����������������� �����";
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
		string message = "����� " + to_string(periodicity) +
			" �� �������� ������������� ������\n"
			"� �� ����� ���������� ������������� �����";
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
		string message = "����� " + to_string(stopsCount) +
			" �� ������ � ���������� �������� �������� [0, 10]";
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
		cout << "������� ����� �����: ";
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
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ����������������� �����: ";
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
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ������������� �����: ";
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
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ���������� ��������� �����: ";
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
					cout << "������� ��������� �" << i + 1 << ": ";
					cin >> stops[i];
					cout << endl;
				}
			}
			SetStops(stops, stopsCount);
			break;
		}
		else
		{
			cout << "����������, ������� ������������� ����� �����";
			cout << endl << endl;
		}
	} while (true);
}

void Route::WriteRouteToConsole()
{
	cout << "���� �" << this->_number << " (" << this->_stops[0];
	cout << " - " << this->_stops[_stopsCount - 1] << ") ��������� � ���� ";
	cout << this->_durationInMinutes << " �����, " << endl;
	cout << "����������� �� ������� � �������������� � ";
	cout << this->_periodicity << " �����. " << endl;
	cout << "������� �������� " << this->_stopsCount << " ���������";
	cout << endl << endl;
}
