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

bool ValueValidator::IsValueInRange(const float value,
	const float minLimit, const float maxLimit)
{
	return (minLimit <= value && maxLimit >= value);
}

void ValueValidator::AssertValueInRange(const float value,
	const float minLimit, const float maxLimit,
	const MessageType& messageType, const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		switch (messageType)
		{
			case NotPositive:
			{
				string message = "Отрицательное число "
					+ to_string((int)value)
					+ " не может определять " + content;
				char buf[255];
				strcpy_s(buf, message.c_str());
				throw exception(buf);
			}
			case NotInRange:
			{
				string message = "Число " + to_string((int)value) + ".";
					if (int((value - (int)value) * 100) < 0)
					{
						message += to_string(int((value - (int)value) * -100));
					}
					else
					{
						message += to_string(int((value - (int)value) * 100));
					}
					message += "\nне входит в допустимый диапазон значений ["
					+ to_string(minLimit) + ", "
					+ to_string(maxLimit)
					+ "]\nи не может определять " + content;
				char buf[255];
				strcpy_s(buf, message.c_str());
				throw exception(buf);
			}
		}
		
	}
}