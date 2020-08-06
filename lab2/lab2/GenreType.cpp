#include "GenreType.h"

void ReadGenre(int numGenre, GenreType& filmsGenre)
{
	switch (numGenre)
	{
	case 0:
		filmsGenre = Comedy;
		break;
	case 1:
		filmsGenre = Drama;
		break;
	case 2:
		filmsGenre = Thriller;
		break;
	case 3:
		filmsGenre = Action;
		break;
	case 4:
		filmsGenre = Horror;
		break;
	case 5:
		filmsGenre = Blockbuster;
		break;
	}
}

string PrintGenre(GenreType& filmsGenre)
{
	switch (filmsGenre)
	{
	case Comedy:
		return "�������";
	case Drama:
		return "�����";
	case Thriller:
		return "�������";
	case Action:
		return "�����";
	case Horror:
		return "����� ������";
	case Blockbuster:
		return "����������";
	}
}

