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

string MakeMessage(Time departureTime, Time destinationTime, 
	const int invalidTime, const MessageType& messageType)
{
	switch (messageType)
	{
		case InvalidYear:
		{
			string message = "����������: ��� ��������: " 
				+ to_string(invalidTime)
				+ " ������������ ���� ������: "
				+ to_string(departureTime.GetYear());
			return message;
		}
		case InvalidMonth:
		{
			string message = "����������: ����� ��������: "
				+ to_string(destinationTime.GetYear()) + "."
				+ to_string(invalidTime) + " ������������ ������ ������: "
				+ to_string(departureTime.GetYear()) + "."
				+ to_string(departureTime.GetMonth());
			return message;
		}
		case InvalidDay:
		{
			string message = "����������: ���� ��������: "
				+ to_string(destinationTime.GetYear()) + "."
				+ to_string(destinationTime.GetMonth()) + "."
				+ to_string(invalidTime) + " ������������ ���� ������: "
				+ to_string(departureTime.GetYear()) + "."
				+ to_string(departureTime.GetMonth()) + "."
				+ to_string(departureTime.GetDay());
			return message;
		}
		case InvalidHour:
		{
			string message = "����������: ����� ��������: "
				+ to_string(destinationTime.GetYear()) + "."
				+ to_string(destinationTime.GetMonth()) + "."
				+ to_string(destinationTime.GetDay())
				+ to_string(invalidTime) + "�"
				+ " ������������ ������� ������: "
				+ to_string(departureTime.GetYear()) + "."
				+ to_string(departureTime.GetMonth()) + "."
				+ to_string(departureTime.GetDay())
				+ to_string(departureTime.GetHour());
			return message;
		}
		case InvalidMinute:
		{
			string message = "����������: ����� ��������: "
				+ to_string(destinationTime.GetYear()) + "."
				+ to_string(destinationTime.GetMonth()) + "."
				+ to_string(destinationTime.GetDay())
				+ to_string(destinationTime.GetHour()) + ":"
				+ to_string(invalidTime)
				+ " ������������ ������� ������: "
				+ to_string(departureTime.GetYear()) + "."
				+ to_string(departureTime.GetMonth()) + "."
				+ to_string(departureTime.GetDay())
				+ to_string(departureTime.GetHour())
				+ to_string(departureTime.GetMinute());
			return message;
		}
	}
}
