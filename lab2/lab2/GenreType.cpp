#include "GenreType.h"

GenreType GetGenreType(const int numGenre)
{
	if (!IsValueInRange(numGenre, 0, 5))
	{
		throw exception("����� �� ������ � ���������� ��������");
	}
	switch (numGenre)
	{
		//TODO: RSDN - ������ ��� Switch-case ������������ ������� ������� ������������������ + ������� �������� ��� case-��
	case 0: return Comedy;
	case 1: return Drama;
	case 2: return Thriller;
	case 3: return Action;
	case 4: return Horror;
	case 5: return Blockbuster;
	}
}

string PrintGenre(const GenreType& filmsGenre)
{
	switch (filmsGenre)
	{
		//TODO: RSDN - ������ ��� Switch-case ������������ ������� ������� ������������������ + ������� �������� ��� case-��
	case Comedy:	  return "�������";
	case Drama:		  return "�����";
	case Thriller:    return "�������";
	case Action:	  return "�����";
	case Horror:	  return "����� ������";
	case Blockbuster: return "����������";
	}
}

