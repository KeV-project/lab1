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
	return (minLimit <= value && maxLimit >= value);
}

void AssertValueInRange(const int value, const int minLimit,
	const int maxLimit, const MessageType& messageType,
	const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		switch (messageType)
		{
			case NotInRange:
			{
				string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(value)
					+ "\nне входит в допустимый диапазон значений "
					+ "[" + to_string(minLimit) + ", " + to_string(maxLimit)
					+ "]\nи не может определять " + content;
				char sendMessage[255];
				strcpy_s(sendMessage, message.c_str());
				throw exception(sendMessage);
			}
			case NotPositive:
			{
				string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(value)
					+ " не является положительным\n"
					+ "и не может определять " + content;
				char sendMessage[255];
				strcpy_s(sendMessage, message.c_str());
				throw exception(sendMessage);
			}
			case NotNonNegative:
			{
				string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(value)
					+ " не является неотрицательным\n"
					+ "и не может определять " + content;
				char sendMessage[255];
				strcpy_s(sendMessage, message.c_str());
				throw exception(sendMessage);
			}
			case InvalidTime:
			{
				string message = "ИСКЛЮЧЕНИЕ: " + content
					+ " вылета: "
					+ to_string(value)
					+ " опережает(/ют)" + content + " прибытия: "
					+ to_string(maxLimit);
				char sendMessage[255];
				strcpy_s(sendMessage, message.c_str());
				throw exception(sendMessage);
			}
		}
	}
}