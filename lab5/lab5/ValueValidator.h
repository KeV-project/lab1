#pragma once
#include <iostream>
#include <string>
#include "MessageType.h"

using namespace std;

static class ValueValidator
{
public:
    static bool IsValueInRange(const float value, const float minLimit,
        const float maxLimit);
    static bool IsValue();
    static void AssertValueInRange(const float value, const float minLimit,
        const float maxLimit, const MessageType& messageType,
        const string& content);
};

