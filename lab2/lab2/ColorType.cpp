#include "ColorType.h"

void PrintColor(ColorType color)
{
	switch (color)
	{
	case Red:
		cout << "������� ����" << endl;
		break;
	case Orange:
		cout << "��������� ����" << endl;
		break;
	case Yellow:
		cout << "������ ����" << endl;
		break;
	case Green:
		cout << "������� ����" << endl;
		break;
	case Blue:
		cout << "������� ����" << endl;
		break;
	case DarkBlue:
		cout << "����� ����" << endl;
		break;
	case Purple:
		cout << "��������� ����" << endl;
		break;
	}
}