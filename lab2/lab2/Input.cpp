#include "Input.h"

bool IsValueInRange(const int value, const int minLimit, const int maxLimit)
{
	if (value < minLimit || value > maxLimit)
	{
		return false;
	}
	return true;
}
