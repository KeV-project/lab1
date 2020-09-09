#pragma once
#include <iostream>
#include <string>

using namespace std;

static class FloatValidator
{
private:
	static bool IsValue();
	static bool IsValueInRange(const float value,
		const float minLimit, const float maxLimit);

public:
	static void AssertValue();
		const string& content);
	static void AssertValueInRange(const float value, 
		const float minLimit, const float maxLimit,
		const string& content);
};

