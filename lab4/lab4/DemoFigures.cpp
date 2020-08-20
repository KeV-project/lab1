#include "DemoFigures.h"

void DemoFigures::DemoRing()
{
	// Task 4.1.6
	const int ringsCount = 3;
	Ring** rings = new Ring * [ringsCount];
	try
	{
		cout << "Создание кольца №1: Ring(10.5, 5.2, 13.5, 15.0) " << endl << endl;
		rings[0] = new Ring(10.5, 5.2, 13.5, 15.0);
		rings[0]->PrintRing();
		cout << endl << endl;

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	cout << "Всего колец: " << Ring::GetAllRingsCount() << endl << endl;
	try
	{
		cout << "Создание кольца №2: Ring(10.5, 5.2, 16.5, 15.0)" << endl << endl;
		rings[1] = new Ring(10.5, 5.2, 16.5, 15.0);
		rings[1]->PrintRing();
		cout << endl << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	cout << "Всего колец: " << Ring::GetAllRingsCount() << endl << endl;
	try
	{
		cout << "Создание кольца №3: Ring(10.5, 5.2, -13.5, 15.0)" << endl << endl;
		rings[2] = new Ring(10.5, 5.2, -13.5, 15.0);
		rings[2]->PrintRing();
		cout << endl << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	cout << "Всего колец: " << Ring::GetAllRingsCount() << endl << endl;

	delete rings[0];
	delete[] rings;

	PrintLine();

	// Task 4.4.6
	cout << "Количество колец до вызова конструктора: ";
	cout << Ring::GetAllRingsCount();
	cout << endl << endl;
	Ring* ring = new Ring(10.0, 5.0, 25.0, 25.5);
	cout << "Количество колец после вызова конструктора: ";
	cout << Ring::GetAllRingsCount();
	cout << endl << endl;
	delete ring;
	cout << "Количество колец после вызова деструктора: ";
	cout << Ring::GetAllRingsCount();
	cout << endl << endl;

	PrintLine();
}
