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

string MakeMessage(const int departureYear, const int departureMonth,
	const int departureDay, const int departureHour,
	const int departureMinute, const int destinationYear,
	const int destinationMonth, const int destinationDay,
	const int destinationHour, const int destinationMinute,
	const MessageType& messageType)
{
	switch (messageType)
	{
		case InvalidYear:
		{
			string message = "ИСКЛЮЧЕНИЕ: Год прибытия: " 
				+ to_string(destinationYear)
				+ " предшествует году вылета: "
				+ to_string(departureYear);
			return message;
		}
		case InvalidMonth:
		{
			string message = "ИСКЛЮЧЕНИЕ: Месяц прибытия: "
				+ to_string(destinationYear) + "."
				+ to_string(destinationMonth) + "\nпредшествует месяцу вылета: "
				+ to_string(departureYear) + "."
				+ to_string(departureMonth);
			return message;
		}
		case InvalidDay:
		{
			string message = "ИСКЛЮЧЕНИЕ: Дата прибытия: "
				+ to_string(destinationHour) + "."
				+ to_string(destinationMonth) + "."
				+ to_string(destinationDay) + "\nпредшествует дате вылета: "
				+ to_string(departureYear) + "."
				+ to_string(departureMonth) + "."
				+ to_string(departureDay);
			return message;
		}
		case InvalidHour:
		{
			string message = "ИСКЛЮЧЕНИЕ: Время прибытия: "
				+ to_string(destinationYear) + "."
				+ to_string(destinationMonth) + "."
				+ to_string(destinationDay) + " "
				+ to_string(destinationHour) + " ч\n"
				+ " предшествует времени вылета: "
				+ to_string(departureYear) + "."
				+ to_string(departureMonth) + "."
				+ to_string(departureDay) + " "
				+ to_string(departureHour);
			return message;
		}
		case InvalidMinute:
		{
			string message = "ИСКЛЮЧЕНИЕ: Время прибытия: "
				+ to_string(destinationYear) + "."
				+ to_string(destinationMonth) + "."
				+ to_string(destinationDay) + " "
				+ to_string(destinationHour) + ":"
				+ to_string(destinationMinute)
				+ "\nпредшествует времени вылета: "
				+ to_string(departureYear) + "."
				+ to_string(departureMonth) + "."
				+ to_string(departureDay) + " "
				+ to_string(departureHour) + ":"
				+ to_string(departureMinute);
			return message;
		}
	}
}
