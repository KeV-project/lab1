#pragma once
#include <string>
#include "MessageType.h"

using namespace std;

string MakeMessage(const int invalidNumber, const int minLimit, 
	const int maxLimit, const string& content);
string MakeMessage(const int invalidNumber, const MessageType& messageType,
	const string& content);
string MakeMessage();
string MakeMessage(const int departureYear, const int departureMonth, 
	const int departureDay, const int departureHour, 
	const int departureMinute, const int destinationYear, 
	const int destinationMonth, const int destinationDay, 
	const int destinationHour, const int destinationMinute,
	const MessageType& messageType);