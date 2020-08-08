#include "GenreType.h"

//TODO: Сигнатура +
GenreType ReadGenre()
{
	//TODO: Не обработаны крайние случаи - меньше нуля и больше 5
	int numGenre = 0;
	cout << "Введите жанр фильма";
	cout << "(0 - Комедия, 1 - Драма, 2 - Триллер, " << endl;
	cout << "3 - Экшен, 4 - Фильм ужасов, 5 - Блокбастер): ";
	cin >> numGenre;
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

