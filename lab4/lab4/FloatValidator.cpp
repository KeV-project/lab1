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
	//TODO: Писал замечание в предыдущей лабе +
	return minLimit < value && maxLimit > value;
}

void FloatValidator::AssertValueInRange(const float value,
	const float minLimit, const float maxLimit,
	const MessageType& messageType, const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		//TODO: Дубль +
		switch (messageType)
		{
			case NotInRange:
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
			case NotPositive:
			{
				string message = "Число " + (to_string(value)).erase(5, 10)
					+ " не является положительным"
					+ "\nи не может определять " + content;
				char buf[255];
				strcpy_s(buf, message.c_str());
				throw exception(buf);
			}
		}
		
	}
}