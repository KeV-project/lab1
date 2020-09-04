#pragma once
#include <string>
#include "MessageType.h"

using namespace std;

string MakeMessage(const int invalidNumber, const int minLimit, 
	const int maxLimit, const string& content);
string MakeMessage(const int invalidNumber, const MessageType& messageType,
	const string& content);
string MakeMessage();