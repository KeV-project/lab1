#include "MakeMessage.h"

string MakeMessage(const int invalidNumber, const int minLimit, 
	const int maxLimit, const string& content)
{
	string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(invalidNumber)
		+ "\nне входит в допустимый диапазон значений "
		+ "[" + to_string(minLimit) + ", "  + to_string(maxLimit)
		+ "]\nи не может определять " + content;
	return message;
}

string MakeMessage(const int invalidNumber, const MessageType& messageType,
	const string& content)
{
	switch (messageType)
	{
		case NotPositive:
		{
			string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(invalidNumber)
				+ " не является положительным\n"
				+ "и не может определять " + content;
			return message;
		}
		case NotNonNegative:
		{
			string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(invalidNumber)
				+ " не является неотрицательным\n"
				+ "и не может определять " + content;
			return message;
		}
		case NotNumber:
		{
			string message = "ИСКЛЮЧЕНИЕ: Некорректные входные данные\n"
				"Пожалуйста, введите целое число";
			return message;
		}
	}
}

string MakeMessage()
{
	string message = "ИСКЛЮЧЕНИЕ: Некорректные входные данные\n"
		"Пожалуйста, введите целое число";
	return message;
}

string MakeMessage(Time departureTime, Time destinationTime, 
	const int invalidTime, const MessageType& messageType)
{
	switch (messageType)
	{
		case InvalidYear:
		{
			string message = "ИСКЛЮЧЕНИЕ: Год прибытия: " 
				+ to_string(invalidTime)
				+ " предшествует году вылета: "
				+ to_string(departureTime.GetYear());
			return message;
		}
		case InvalidMonth:
		{
			string message = "ИСКЛЮЧЕНИЕ: Месяц прибытия: "
				+ to_string(destinationTime.GetYear()) + "."
				+ to_string(invalidTime) + " предшествует месяцу вылета: "
				+ to_string(departureTime.GetYear()) + "."
				+ to_string(departureTime.GetMonth());
			return message;
		}
		case InvalidDay:
		{
			string message = "ИСКЛЮЧЕНИЕ: Дата прибытия: "
				+ to_string(destinationTime.GetYear()) + "."
				+ to_string(destinationTime.GetMonth()) + "."
				+ to_string(invalidTime) + " предшествует дате вылета: "
				+ to_string(departureTime.GetYear()) + "."
				+ to_string(departureTime.GetMonth()) + "."
				+ to_string(departureTime.GetDay());
			return message;
		}
		case InvalidHour:
		{
			string message = "ИСКЛЮЧЕНИЕ: Время прибытия: "
				+ to_string(destinationTime.GetYear()) + "."
				+ to_string(destinationTime.GetMonth()) + "."
				+ to_string(destinationTime.GetDay())
				+ to_string(invalidTime) + "ч"
				+ " предшествует времени вылета: "
				+ to_string(departureTime.GetYear()) + "."
				+ to_string(departureTime.GetMonth()) + "."
				+ to_string(departureTime.GetDay())
				+ to_string(departureTime.GetHour());
			return message;
		}
		case InvalidMinute:
		{
			string message = "ИСКЛЮЧЕНИЕ: Время прибытия: "
				+ to_string(destinationTime.GetYear()) + "."
				+ to_string(destinationTime.GetMonth()) + "."
				+ to_string(destinationTime.GetDay())
				+ to_string(destinationTime.GetHour()) + ":"
				+ to_string(invalidTime)
				+ " предшествует времени вылета: "
				+ to_string(departureTime.GetYear()) + "."
				+ to_string(departureTime.GetMonth()) + "."
				+ to_string(departureTime.GetDay())
				+ to_string(departureTime.GetHour())
				+ to_string(departureTime.GetMinute());
			return message;
		}
	}
}
