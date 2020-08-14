#include "GenreType.h"

GenreType GetGenreType(const int numGenre)
{
	if (!IsValueInRange(numGenre, 0, 5))
	{
		string message = "Число " + to_string(numGenre) + 
			" не входит в допустимый диапазон [0, 5] "
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
			return Comedy;
		}
		case 1: 
		{
			return Drama;
		}
		case 2: 
		{
			return Thriller;
		}
		case 3: 
		{
			return Action;
		}
		case 4: 
		{
			return Horror;
		}
		case 5: 
		{
			return Blockbuster;
		}
	}
}

string PrintGenre(const GenreType& filmsGenre)
{
	switch (filmsGenre)
	{
		case Comedy:	  
		{
			return "комедия";
		}
		case Drama:		  
		{
			return "драма";
		}
		case Thriller:
		{
			return "триллер";
		}
		case Action:	  
		{
			return "экшен";
		}
		case Horror:	
		{
			return "фильм ужасов";
		}
		case Blockbuster: 
		{
			return "блокбастер";
		}
	}
}

