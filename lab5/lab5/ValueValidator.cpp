#include "ValueValidator.h"

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

bool ValueValidator::IsValueInRange(const int value,
	const int minLimit, const int maxLimit)
{
	if (value < minLimit || value > maxLimit)
	{
		return false;
	}
	return true;
}

bool ValueValidator::IsValueInRange(const float value,
	const float minLimit, const float maxLimit)
{
	if (value <= minLimit || value >= maxLimit)
	{
		return false;
	}
	return true;
}

bool ValueValidator::IsValuePositive(const int value)
{
	if (value > 0)
	{
		return true;
	}
	return false;
}

void ValueValidator::AssertPositiveValue(const int value,
	const string& content)
{
	if (!IsValuePositive(value))
	{
		string message = "Отрицательное число "
			+ (to_string(value)).erase(5, 10)
			+ " не может определять " + content;
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
}

void ValueValidator::AssertValueInRange(const int value,
	const int minLimit, const int maxLimit, const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		string message = "Число " + to_string(value)
			+ " не входит в допустимый диапазон значений ["
			+ to_string(minLimit) + ", "
			+ to_string(maxLimit)
			+ "]\nи не может определять " + content;
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
}

void ValueValidator::AssertValueInRange(const float value,
	const float minLimit, const float maxLimit, const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		string message = "Число " + (to_string(value)).erase(5, 10)
			+ " не входит в допустимый диапазон значений ["
			+ (to_string(minLimit)).erase(5, 10) + ", "
			+ (to_string(maxLimit)).erase(5, 10)
			+ "]\nи не может определять " + content;
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
}