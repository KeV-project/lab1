#include "ValueValidator.h"

// Возвращает целое либо дробное число с 2 знаками после запятой в виде строки
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
			string message = "ИСКЛЮЧЕНИЕ: Число "
				+ ConversionFloatToString(value)
				+ "\nне входит в допустимый диапазон значений "
				+ "[" + ConversionFloatToString(minLimit) + ", "
				+ ConversionFloatToString(maxLimit)
				+ "]\nи не может определять " + content;
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		case NotPositive:
		{
			string message = "ИСКЛЮЧЕНИЕ: Число "
				+ ConversionFloatToString(value)
				+ " не является положительным\n"
				+ "и не может определять " + content;
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		case NotNonNegative:
		{
			string message = "ИСКЛЮЧЕНИЕ: Число "
				+ ConversionFloatToString(value)
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
				+ ConversionFloatToString(value)
				+ " опережает(/ют)" + content + " прибытия: "
				+ ConversionFloatToString(maxLimit);
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		}
	}
}
