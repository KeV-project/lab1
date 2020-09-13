#include "ValueValidator.h"

// ���������� ����� ���� ������� ����� � 2 ������� ����� ������� � ���� ������
string ValueValidator::ConversionFloatToString(const float value)
{
	int integerPart = value;
	int fractionalPart = 0;

	if (int((value - (int)value) * 100) < 0)
	{
		fractionalPart = int((value - (int)value) * -100);
	}
	else
	{
		fractionalPart = int((value - (int)value) * 100);
	}

	if (fractionalPart == 0)
	{
		return to_string(integerPart);
	}
	else
	{
		return to_string(integerPart) + "."
			+ to_string(fractionalPart);
	}
}

bool ValueValidator::IsValueInRange(const float value,
	const float minLimit, const float maxLimit)
{
	return (minLimit <= value && maxLimit >= value);
}

bool ValueValidator::IsValue()
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

void ValueValidator::AssertValueInRange(const float value,
	const float minLimit, const float maxLimit,
	const MessageType& messageType, const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		switch (messageType)
		{
		case NotInRange:
		{
			string message = "����������: ����� "
				+ ConversionFloatToString(value)
				+ "\n�� ������ � ���������� �������� �������� "
				+ "[" + ConversionFloatToString(minLimit) + ", "
				+ ConversionFloatToString(maxLimit)
				+ "]\n� �� ����� ���������� " + content;
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		case NotPositive:
		{
			string message = "����������: ����� "
				+ ConversionFloatToString(value)
				+ " �� �������� �������������\n"
				+ "� �� ����� ���������� " + content;
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		case NotNonNegative:
		{
			string message = "����������: ����� "
				+ ConversionFloatToString(value)
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
				+ ConversionFloatToString(value)
				+ " ���������(/��)" + content + " ��������: "
				+ ConversionFloatToString(maxLimit);
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		}
	}
}
