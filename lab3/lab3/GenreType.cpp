#include "GenreType.h"

GenreType GetGenreType(const int numGenre)
{
	int const minNumGenre = 0;
	int const maxNumGenre = 6;
	AssertValueInRange(numGenre, minNumGenre,
		maxNumGenre, NotInRange, "���� �����");
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
			return "����";
		}
		case HipHop:
		{
			return "���-���";
		}
		case Electronic:
		{
			return "����������� ������";
		}
		case Rock:
		{
			return "���";
		}
		case Disco:
		{
			return "�����";
		}
		case Fusion:
		{
			return "�����";
		}
		case Pop:
		{
			return "���";
		}
	}
}
