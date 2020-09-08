#pragma once
#include <iostream>
#include <string>

using namespace std;

static class ValueValidator
{
private:
	static bool IsValuePositive(const int value);
	static bool IsValueInRange(const int value,
		const int minLimit, const int maxLimit);

public:
	static bool IsValue();

	static void AssertPositiveValue(const int value,
		const string& content);
	static void AssertValueInRange(const int value,
		const int minLimit, const int maxLimit,
		const string& content);
};


