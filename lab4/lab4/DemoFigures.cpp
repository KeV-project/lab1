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

void DemoFigures::DemoRect()
{
	const int rectsCount = 3;
	Rect** rects = new Rect * [rectsCount];
	try
	{
		cout << "Создание прямоугольника №1: Rect(5.5, -6.6, 13.0, 15.0) " << endl << endl;
		rects[0] = new Rect(5.5, -6.6, 13.0, 15.0);
		rects[0]->PrintRect();
		cout << endl << endl;

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	cout << "Всего прямоугольников: " << Rect::GetAllRectsCount() << endl << endl;
	try
	{
		cout << "Создание прямоугольника №2: Rect(-1.5, 2.5, -1.0, 5.5)" << endl << endl;
		rects[1] = new Rect(-1.5, 2.5, -1.0, 5.5);
		rects[1]->PrintRect();
		cout << endl << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	cout << "Всего прямоугольников: " << Rect::GetAllRectsCount() << endl << endl;
	try
	{
		cout << "Создание прямоугольника №3: Rect(3.5, -5.2, 7.5, -10.6)" << endl << endl;
		rects[2] = new Rect(3.5, -5.2, 7.5, -10.6);
		rects[2]->PrintRect();
		cout << endl << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	cout << "Всего прямоугольников: " << Rect::GetAllRectsCount() << endl << endl;

	delete rects[0];
	delete[] rects;

	PrintLine();

	// Task 4.4.6
	cout << "Количество прямоугольников до вызова конструктора: ";
	cout << Rect::GetAllRectsCount();
	cout << endl << endl;
	Rect* rect = new Rect(10.0, 5.0, 25.0, 25.5);
	cout << "Количество прямоугольников после вызова конструктора: ";
	cout << Rect::GetAllRectsCount();
	cout << endl << endl;
	delete rect;
	cout << "Количество прямоугольников после вызова деструктора: ";
	cout << Rect::GetAllRectsCount();
	cout << endl << endl;

	PrintLine();
}

void DemoFigures::DemoCollision()
{
	const int rectsCount = 8;
	Rect rects[rectsCount]
	{
		//Пересекающиеся прямоугольники
		Rect(8.0, 4.0, 5.0, 3.0),
		Rect(9.0, 5.0, 12.5, 6.5),

		Rect(7.0, 5.0, 5.5, 6.5),
		Rect(9.0, 5.0, 10.5, 2.5),

		//Непересекающиеся прямоугольники
		Rect(5.0, 3.0, 4.0, 2.5),
		Rect(6.0, 3.0, 11.0, 7.5),

		Rect(7.0, 10.0, 4.5, 6.0),
		Rect(6.0, 3.0, 12.5, 5.5)
	};

	cout << "ПРЯМОУГОЛЬНИКИ" << endl << endl;

	for (int i = 0; i < rectsCount; i += 2)
	{
		cout << "Прямоуголиник №" << i + 1 << ":" << endl;
		rects[i].PrintRect();
		cout << endl << endl;

		cout << "Прямоуголиник №" << i + 2 << ":" << endl;
		rects[i + 1].PrintRect();
		cout << endl << endl;
		if (CollisionManager::IsCollision(rects[i], rects[i + 1]))
		{
			cout << "Прямоугольники " << i + 1 << " и " << i + 2 << " пересекаются" << endl << endl;
		}
		else
		{
			cout << "Прямоугольники " << i + 1 << " и " << i + 2 << " не пересекаются" << endl << endl;
		}
	}

	const int ringsCount = 8;
	Ring rings[ringsCount]
	{
		//Пересекающиеся кольца
		Ring(4.5, 2.5, 1.0, 1.5),
		Ring(7.0, 5.0, 2.5, 3.0),

		Ring(4.0, 4.0, 2.5, 4.0),
		Ring(8.0, 7.0, 1.0, 2.0),

		//Непересекающиеся кольца
		Ring(3.5, 2.5, 1.0, 1.5),
		Ring(8.0, 7.0, 1.5, 2.0),

		Ring(5.0, 5.0, 2.0, 4.0),
		Ring(12.0, 8.0, 1.0, 2.0)
	};
	
	cout << "КОЛЬЦА" << endl << endl;

	for (int i = 0; i < ringsCount; i += 2)
	{
		cout << "Кольцо №" << i + 1 << ":" << endl;
		rings[i].PrintRing();
		cout << endl << endl;

		cout << "Кольцо №" << i + 2 << ":" << endl;
		rings[i + 1].PrintRing();
		cout << endl << endl;

		if (CollisionManager::IsCollision(rings[i], rings[i + 1]))
		{
			cout << "Кольца " << i + 1 << " и " << i + 2 << " пересекаются" << endl << endl;
		}
		else
		{
			cout << "Кольца " << i + 1 << " и " << i + 2 << " не пересекаются" << endl << endl;
		}
	}

	PrintLine();
}
