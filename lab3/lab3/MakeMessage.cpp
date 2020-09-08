#include "MakeMessage.h"

string MakeMessage(const int invalidNumber, const int minLimit,
	const int maxLimit, const MessageType& messageType, 
	const string& content)
{
	//TODO: Оставил бы эту часть в AssertValueInRange, т.к. этот метод усложняет понимание логики, т.е. мы передаём некоторые аргументы
	//TODO: в AssertValueInRange, а используем их только тут
	switch (messageType)
	{
		case NotInRange:
		{
			string message = "ИСКЛЮЧЕНИЕ: Число " + to_string(invalidNumber)
				+ "\nне входит в допустимый диапазон значений "
				+ "[" + to_string(minLimit) + ", " + to_string(maxLimit)
				+ "]\nи не может определять " + content;
			return message;
		}
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
		case InvalidTime:
		{
			string message = "ИСКЛЮЧЕНИЕ: " + content
				+ " вылета: "
				+ to_string(invalidNumber)
				+ " опережает(/ют)" + content + " прибытия: "
				+ to_string(maxLimit);
			return message;
		}
	}
}