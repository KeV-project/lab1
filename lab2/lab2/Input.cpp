#include "Input.h"

bool IsValueInRange(const int value, const int minLimit, const int maxLimit)
{
	if (value < minLimit || value > maxLimit)
	{
		return false;
	}
	return true;
}

bool IsValue()
{
	//TODO: К int можно не приводить и писать != вместо отрицания ==
	if (!(cin.get() == (int)'\n'))
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
