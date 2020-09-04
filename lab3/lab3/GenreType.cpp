#include "GenreType.h"

GenreType GetGenreType(const int numGenre)
{
	if (!IsValueInRange(numGenre, 0, 6))
	{
		//TODO: �����
		string message = "����� " + to_string(numGenre) +
			" �� ������ � ���������� �������� [0, 6]\n"
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
