#include "GenreType.h"

//TODO: ��������� +
void ReadGenre(const int numGenre, GenreType& filmsGenre)
{
	//TODO: �� ���������� ������� ������ - ������ ���� � ������ 5
	
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

//TODO: ���������
string PrintGenre(const GenreType& filmsGenre)
{
	switch (filmsGenre)
	{
		//TODO: RSDN
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

