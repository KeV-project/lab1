#include "GenreType.h"

GenreType GetGenreType(const int numGenre)
{
	if (!IsValueInRange(numGenre, 0, 5))
	{
		string message = "����� " + to_string(numGenre) + 
			" �� ������ � ���������� �������� [0, 5] "
			"� �� ����� ���� ������������ � ��������������� "
			"��������� ������������";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
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
			return "�������";
		}
		case Drama:		  
		{
			return "�����";
		}
		case Thriller:
		{
			return "�������";
		}
		case Action:	  
		{
			return "�����";
		}
		case Horror:	
		{
			return "����� ������";
		}
		case Blockbuster: 
		{
			return "����������";
		}
	}
}

