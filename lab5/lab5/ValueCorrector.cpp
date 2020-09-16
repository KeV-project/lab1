#include "ValueCorrector.h"

// Возвращает целое либо дробное число с 2 знаками после запятой в виде строки
string ValueCorrector::ConversionFloatToString(const float value)
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

void ValueCorrector::RoundFloatToHundredths(float& value)
{
	value = roundf(value * 100) / 100;
}

