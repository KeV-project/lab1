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
	if (value <= minLimit || value >= maxLimit)
	{
		return false;
	}
	return true;
}

bool FloatValidator::IsValuePositive(const float value)
{
	if (value > 0)
	{
		return true;
	}
	return false;
}

void FloatValidator::AssertValue()
{
	if (!IsValue())
	{
		throw exception("������� ������������ ��������.\n"
			"���������� ������� �����: ");
	}
}

void FloatValidator::AssertPositiveValue(const float value,
	const string& content)
{
	if (!IsValuePositive(value))
	{
		string message = "������������� ����� " 
			+ (to_string(value)).erase(5, 10)
			+ " �� ����� ���������� " + content;
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
}

void FloatValidator::AssertValueInRange(const float value,
	const float minLimit, const float maxLimit, const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		string message = "����� " + (to_string(value)).erase(5, 10) 
			+ " �� ������ � ���������� �������� �������� [" 
			+ (to_string(minLimit)).erase(5, 10) + ", " 
			+ (to_string(maxLimit)).erase(5, 10)
			+ "]\n� �� ����� ���������� " + content;
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
}