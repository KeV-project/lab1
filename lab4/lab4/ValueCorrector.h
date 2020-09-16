#pragma once
#include <string>

using namespace std;

static class ValueCorrector
{
public:
	static string ConversionFloatToString(const float value);
	static void RoundFloatToHundredths(float& value);
};

