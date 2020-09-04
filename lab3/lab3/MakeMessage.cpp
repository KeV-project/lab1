#include "MakeMessage.h"

string MakeMessage(const int invalidNumber, const int minLimit, 
	const int maxLimit, const string& content)
{
	string message = "����������: ����� " + to_string(invalidNumber)
		+ "\n�� ������ � ���������� �������� �������� "
		+ "[" + to_string(minLimit) + ", "  + to_string(maxLimit)
		+ "]\n� �� ����� ���������� " + content;
	return message;
}

string MakeMessage(const int invalidNumber, const MessageType& messageType,
	const string& content)
{
	switch (messageType)
	{
		case NotPositive:
		{
			string message = "����������: ����� " + to_string(invalidNumber)
				+ " �� �������� �������������\n"
				+ "� �� ����� ���������� " + content;
			return message;
		}
		case NotNonNegative:
		{
			string message = "����������: ����� " + to_string(invalidNumber)
				+ " �� �������� ���������������\n"
				+ "� �� ����� ���������� " + content;
			return message;
		}
		case NotNumber:
		{
			string message = "����������: ������������ ������� ������\n"
				"����������, ������� ����� �����";
			return message;
		}
	}
}

string MakeMessage()
{
	string message = "����������: ������������ ������� ������\n"
		"����������, ������� ����� �����";
	return message;
}

string MakeMessage(const int departureYear, const int departureMonth,
	const int departureDay, const int departureHour,
	const int departureMinute, const int destinationYear,
	const int destinationMonth, const int destinationDay,
	const int destinationHour, const int destinationMinute,
	const MessageType& messageType)
{
	switch (messageType)
	{
		case InvalidYear:
		{
			string message = "����������: ��� ��������: " 
				+ to_string(destinationYear)
				+ " ������������ ���� ������: "
				+ to_string(departureYear);
			return message;
		}
		case InvalidMonth:
		{
			string message = "����������: ����� ��������: "
				+ to_string(destinationYear) + "."
				+ to_string(destinationMonth) + "\n������������ ������ ������: "
				+ to_string(departureYear) + "."
				+ to_string(departureMonth);
			return message;
		}
		case InvalidDay:
		{
			string message = "����������: ���� ��������: "
				+ to_string(destinationHour) + "."
				+ to_string(destinationMonth) + "."
				+ to_string(destinationDay) + "\n������������ ���� ������: "
				+ to_string(departureYear) + "."
				+ to_string(departureMonth) + "."
				+ to_string(departureDay);
			return message;
		}
		case InvalidHour:
		{
			string message = "����������: ����� ��������: "
				+ to_string(destinationYear) + "."
				+ to_string(destinationMonth) + "."
				+ to_string(destinationDay) + " "
				+ to_string(destinationHour) + " �\n"
				+ " ������������ ������� ������: "
				+ to_string(departureYear) + "."
				+ to_string(departureMonth) + "."
				+ to_string(departureDay) + " "
				+ to_string(departureHour);
			return message;
		}
		case InvalidMinute:
		{
			string message = "����������: ����� ��������: "
				+ to_string(destinationYear) + "."
				+ to_string(destinationMonth) + "."
				+ to_string(destinationDay) + " "
				+ to_string(destinationHour) + ":"
				+ to_string(destinationMinute)
				+ "\n������������ ������� ������: "
				+ to_string(departureYear) + "."
				+ to_string(departureMonth) + "."
				+ to_string(departureDay) + " "
				+ to_string(departureHour) + ":"
				+ to_string(departureMinute);
			return message;
		}
	}
}
