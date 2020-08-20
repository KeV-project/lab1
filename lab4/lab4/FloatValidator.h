#pragma once
#include <iostream>
#include <string>

using namespace std;

static class FloatValidator
{
private:
	static bool IsValue();
	static bool IsValuePositive(const float value);
	static bool IsValueInRange(const float value,
		const float minLimit, const float maxLimit);

public:
	static void AssertValue();
	static void AssertPositiveValue(const float value, 
		const string& content);
	static void AssertValueInRange(const float value, 
		const float minLimit, const float maxLimit,
		const string& content);
};

