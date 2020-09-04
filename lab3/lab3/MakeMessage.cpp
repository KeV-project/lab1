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
