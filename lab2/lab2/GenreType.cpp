#include "GenreType.h"

GenreType GetGenreType(const int numGenre)
{
	if (!IsValueInRange(numGenre, 0, 5))
	{
		throw exception("Число не входит в допустимый диапазон");
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

