#include "CheckValue.h"

bool IsValue()
{
	if (cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(32767, '\n');
		return false;
	}
	else
	{
		return true;
	}
}

bool IsValueInRange(const int value, const int minLimit, const int maxLimit)
{
	//TODO: ��� � �� ������������ ������ � �������� ��������� ��
	// return (minLimit <= value && value >= maxLimit)
	// ��� ����� ����� ������ � ����� ������ ��������� ���������� ���������� ������
	// � ����� ������ ���������� ������������� ������, ����� ��� ��������� +
	return (minLimit <= value && maxLimit >= value);
}

void AssertValueInRange(const int value, const int minLimit,
	const int maxLimit, const MessageType& messageType,
	const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		//TODO: ������� �� ��� ����� � AssertValueInRange, �.�. ���� ����� ��������� ��������� ������, �.�. �� ������� ��������� ���������
		//TODO: � AssertValueInRange, � ���������� �� ������ ��� +
		switch (messageType)
		{
			case NotInRange:
			{
				string message = "����������: ����� " + to_string(value)
					+ "\n�� ������ � ���������� �������� �������� "
					+ "[" + to_string(minLimit) + ", " + to_string(maxLimit)
					+ "]\n� �� ����� ���������� " + content;
				char sendMessage[255];
				strcpy_s(sendMessage, message.c_str());
				throw exception(sendMessage);
			}
			case NotPositive:
			{
				string message = "����������: ����� " + to_string(value)
					+ " �� �������� �������������\n"
					+ "� �� ����� ���������� " + content;
				char sendMessage[255];
				strcpy_s(sendMessage, message.c_str());
				throw exception(sendMessage);
			}
			case NotNonNegative:
			{
				string message = "����������: ����� " + to_string(value)
					+ " �� �������� ���������������\n"
					+ "� �� ����� ���������� " + content;
				char sendMessage[255];
				strcpy_s(sendMessage, message.c_str());
				throw exception(sendMessage);
			}
			case InvalidTime:
			{
				string message = "����������: " + content
					+ " ������: "
					+ to_string(value)
					+ " ���������(/��)" + content + " ��������: "
					+ to_string(maxLimit);
				char sendMessage[255];
				strcpy_s(sendMessage, message.c_str());
				throw exception(sendMessage);
			}
		}
	}
}