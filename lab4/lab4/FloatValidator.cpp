#include "FloatValidator.h"

bool FloatValidator::IsValue()
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

bool FloatValidator::IsValueInRange(const float value,
	const float minLimit, const float maxLimit)
{
	//TODO: ������ ��� ���������� ��������� �������� �� ��������� � ���������� �����? ������ ��� ���� �� �������.
	return minLimit < value && maxLimit > value;
}

void FloatValidator::AssertValueInRange(const float value,
	const float minLimit, const float maxLimit,
	const MessageType& messageType, const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		switch (messageType)
		{
			case NotInRange:
			{
					//TODO: ��������� �� float ���������� ����� � ������� erase - ��� ����� - ����� �� ����������
				string message = "����� " + (to_string(value)).erase(5, 10)
					+ " �� ������ � ���������� �������� �������� ["
					+ (to_string(minLimit)).erase(5, 10) + ", "
					+ (to_string(maxLimit)).erase(5, 10)
					+ "]\n� �� ����� ���������� " + content;
				char buf[255];
				strcpy_s(buf, message.c_str());
				throw exception(buf);
			}
			case NotPositive:
			{
				string message = "����� " + (to_string(value)).erase(5, 10)
					+ " �� �������� �������������"
					+ "\n� �� ����� ���������� " + content;
				char buf[255];
				strcpy_s(buf, message.c_str());
				throw exception(buf);
			}
		}
		
	}
}