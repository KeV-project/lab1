#include "GenreType.h"

//TODO: ��������� +
GenreType ReadGenre()
{
	//TODO: �� ���������� ������� ������ - ������ ���� � ������ 5
	int numGenre = 0;
	cout << "������� ���� ������";
	cout << "(0 - �������, 1 - �����, 2 - �������, " << endl;
	cout << "3 - �����, 4 - ����� ������, 5 - ����������): ";
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

