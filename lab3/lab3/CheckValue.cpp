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
	//TODO: Тут я бы инвертировал логику и упростил выражение до
	// return (minLimit <= value && value >= maxLimit)
	// так будет проще читать с точки зрения понимания корректных допустимых границ
	// в вашем случае необходимо инвертировать логику, чтобы это прочитать
	if (value < minLimit || value > maxLimit)
	{
		return false;
	}
	return true;
}

void AssertValueInRange(const int value, const int minLimit,
	const int maxLimit, const MessageType& messageType,
	const string& content)
{
	if (!IsValueInRange(value, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(value, minLimit,
			maxLimit, messageType, content).c_str());
		throw exception(message);
	}
}