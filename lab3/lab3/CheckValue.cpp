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