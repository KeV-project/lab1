#include "DemoFigures.h"

void DemoFigures::DemoRing()
{
	const int ringsCount = 3;
	Ring** rings = new Ring * [ringsCount];
	try
	{
		cout << "Создание кольца №1: " << endl << endl;
		rings[0] = new Ring(10.5, 5.2, 13.5, 15.0);
		rings[0]->PrintRing();

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	try
	{
		cout << "Создание кольца №2: " << endl << endl;
		rings[0] = new Ring(10.5, 5.2, 16.5, 15.0);
		rings[0]->PrintRing();

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	try
	{
		cout << "Создание кольца №3: " << endl << endl;
		rings[0] = new Ring(10.5, 5.2, -13.5, 15.0);
		rings[0]->PrintRing();

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	
}
