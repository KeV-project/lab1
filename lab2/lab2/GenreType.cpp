#include "GenreType.h"

//TODO: Сигнатура +
void ReadGenre(const int numGenre, GenreType& filmsGenre)
{
	//TODO: Не обработаны крайние случаи - меньше нуля и больше 5
	
	switch (numGenre)
	{
		//TODO: RSDN +
	case 0: filmsGenre = Comedy;      break;
	case 1: filmsGenre = Drama;       break;
	case 2: filmsGenre = Thriller;    break;
	case 3: filmsGenre = Action;      break;
	case 4: filmsGenre = Horror;      break;
	case 5: filmsGenre = Blockbuster; break;
	}
}

//TODO: Сигнатура
string PrintGenre(const GenreType& filmsGenre)
{
	switch (filmsGenre)
	{
		//TODO: RSDN
	case Comedy:
		return "комедия";
	case Drama:
		return "драма";
	case Thriller:
		return "триллер";
	case Action:
		return "экшен";
	case Horror:
		return "фильм ужасов";
	case Blockbuster:
		return "блокбастер";
	}
}

