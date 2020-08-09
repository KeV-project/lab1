#include "GenreType.h"

//TODO: Сигнатура +
GenreType GetGenreType(const int numGenre)
{
	//TODO: Не обработаны крайние случаи - меньше нуля и больше 5 +
	if (!IsValueInRange(numGenre, 0, 5))
	{
		throw exception("Число не входит в допустимый диапазон");
	}
	switch (numGenre)
	{
		//TODO: RSDN +
	case 0: return Comedy;
	case 1: return Drama;
	case 2: return Thriller;
	case 3: return Action;
	case 4: return Horror;
	case 5: return Blockbuster;
	}
}

//TODO: Сигнатура +
string PrintGenre(const GenreType& filmsGenre)
{
	switch (filmsGenre)
	{
		//TODO: RSDN +
	case Comedy:	  return "комедия";
	case Drama:		  return "драма";
	case Thriller:    return "триллер";
	case Action:	  return "экшен";
	case Horror:	  return "фильм ужасов";
	case Blockbuster: return "блокбастер";
	}
}

