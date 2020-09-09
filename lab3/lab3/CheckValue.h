#pragma once
#include <iostream>
#include <string>
#include "MessageType.h"

using namespace std;

bool IsValue();
bool IsValueInRange(const int value, const int minLimit,
    const int maxLimit);
void AssertValueInRange(const int value, const int minLimit,
    const int maxLimit, const MessageType& messageType, 
    const string& content);

