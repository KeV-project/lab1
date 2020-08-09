#include "GenreType.h"

//TODO: ��������� +
GenreType GetGenreType(const int numGenre)
{
	//TODO: �� ���������� ������� ������ - ������ ���� � ������ 5 +
	if (!IsValueInRange(numGenre, 0, 5))
	{
		throw exception("����� �� ������ � ���������� ��������");
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

//TODO: ��������� +
string PrintGenre(const GenreType& filmsGenre)
{
	switch (filmsGenre)
	{
		//TODO: RSDN +
	case Comedy:	  return "�������";
	case Drama:		  return "�����";
	case Thriller:    return "�������";
	case Action:	  return "�����";
	case Horror:	  return "����� ������";
	case Blockbuster: return "����������";
	}
}

