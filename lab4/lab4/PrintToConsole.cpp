#include "PrintToConsole.h"

// Вывод разделительной полосы между заданиями
void PrintLine()
{
    cout << "___________________________";
    cout << "___________________________";
    cout << "__________________________" << endl << endl;
}

void PrintRectangle(Rect* rectangle)
{
	cout << "x = " << rectangle->GetCentreX() << ", y = ";
	cout << rectangle->GetCentreY() << ", длина = ";
	cout << rectangle->GetLength() << ", ширина = ";
    cout << rectangle->GetWidth();
}

void PrintRing(Ring* ring)
{
	cout << "x = " << ring->GetCentreX() << ", y = " << ring->GetCentreY();
	cout << ", внутренний радиус = " << ring->GetInRadius();
	cout << ", внешний радиус = " << ring->GetOutRadius();
}
