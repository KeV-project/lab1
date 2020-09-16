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
			string message = "ИСКЛЮЧЕНИЕ: Число "
				+ ValueCorrector::ConversionFloatToString(value)
				+ "\nне входит в допустимый диапазон значений "
				+ "[" + ValueCorrector::ConversionFloatToString(minLimit) + ", "
				+ ValueCorrector::ConversionFloatToString(maxLimit)
				+ "]\nи не может определять " + content;
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		case NotPositive:
		{
			string message = "ИСКЛЮЧЕНИЕ: Число "
				+ ValueCorrector::ConversionFloatToString(value)
				+ " не является положительным\n"
				+ "и не может определять " + content;
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		case NotNonNegative:
		{
			string message = "ИСКЛЮЧЕНИЕ: Число "
				+ ValueCorrector::ConversionFloatToString(value)
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
				+ ValueCorrector::ConversionFloatToString(value)
				+ " опережает(/ют)" + content + " прибытия: "
				+ ValueCorrector::ConversionFloatToString(maxLimit);
			char sendMessage[255];
			strcpy_s(sendMessage, message.c_str());
			throw exception(sendMessage);
		}
		}
	}
}
