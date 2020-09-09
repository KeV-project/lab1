#include "PrintToConsole.h"

// ����� �������������� ������ ����� ���������
void PrintLine()
{
    cout << "___________________________";
    cout << "___________________________";
    cout << "__________________________" << endl << endl;
}

void PrintRectangle(Rect* rectangle)
{
	cout << "x = " << rectangle->GetCentreX() << ", y = ";
	cout << rectangle->GetCentreY() << ", ����� = ";
	cout << rectangle->GetLength() << ", ������ = ";
    cout << rectangle->GetWidth();
}

void PrintRing(Ring* ring)
{
	cout << "x = " << ring->GetCentreX() << ", y = " << ring->GetCentreY();
	cout << ", ���������� ������ = " << ring->GetInRadius();
	cout << ", ������� ������ = " << ring->GetOutRadius();
}
