#include "ValueValidator.h"
#include "ValueCorrector.h"

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
				+ ValueCorrector::ConversionFloatToString(value)
				+ "\n�� ������ � ���������� �������� �������� "
				+ "[" + ValueCorrector::ConversionFloatToString(minLimit) + ", "
				+ ValueCorrector::ConversionFloatToString(maxLimit)
				+ "]\n� �� ����� ���������� " + content;
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		case NotPositive:
		{
			string message = "����������: ����� "
				+ ValueCorrector::ConversionFloatToString(value)
				+ " �� �������� �������������\n"
				+ "� �� ����� ���������� " + content;
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		case NotNonNegative:
		{
			string message = "����������: ����� "
				+ ValueCorrector::ConversionFloatToString(value)
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
				+ ValueCorrector::ConversionFloatToString(value)
				+ " ���������(/��)" + content + " ��������: "
				+ ValueCorrector::ConversionFloatToString(maxLimit);
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		}
	}
}
