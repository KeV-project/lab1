#include "GenreType.h"

GenreType GetGenreType(const int numGenre)
{
	if (!IsValueInRange(numGenre, 0, 6))
	{
		//TODO: Дубль
		string message = "Число " + to_string(numGenre) +
			" не входит в допустимый диапазон [0, 6]\n"
			"и не может быть сопоставлено с соответствующим "
			"значением перечисления";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	switch (numGenre)
	{
		case 0:
		{
			return Jazz;
		}
		case 1:
		{
			return HipHop;
		}
		case 2:
		{
			return Electronic;
		}
		case 3:
		{
			return Rock;
		}
		case 4:
		{
			return Disco;
		}
		case 5:
		{
			return Fusion;
		}
		case 6:
		{
			return Pop;
		}
	}
}

string GetGenreForWrite(const GenreType& genre)
{
	switch (genre)
	{
		case Jazz:
		{
			return "джаз";
		}
		case HipHop:
		{
			return "хип-хоп";
		}
		case Electronic:
		{
			return "электронная музыка";
		}
		case Rock:
		{
			return "рок";
		}
		case Disco:
		{
			return "диско";
		}
		case Fusion:
		{
			return "фьюжн";
		}
		case Pop:
		{
			return "поп";
		}
	}
}
