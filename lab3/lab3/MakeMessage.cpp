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
