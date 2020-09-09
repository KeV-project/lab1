#include "DemoFigures.h"

void DemoFigures::DemoRing()
{
	// Task 4.1.6
	//TODO: Можно было собрать в кучу сделав массив с массивом даблов. Создание колец можно было бы тогда вызывать в цикле +
	const int ringsCount = 3;
	Ring** rings = new Ring * [ringsCount];

	const int ringsParametersCount = 4;
	double** ringsParameters = new double*[ringsCount]
	{
		new double[ringsParametersCount] {10.5, 5.2, 13.5, 15.0},
		new double[ringsParametersCount] {10.5, 5.2, 16.5, 15.0},
		new double[ringsParametersCount] {10.5, 5.2, -13.5, 15.0}
	};
	
	for (int i = 0; i < ringsCount; i++)
	{
		cout << "Создание кольца №" << i + 1 << ": Ring(";
		cout << ringsParameters[i][0] << ", ";
		cout << ringsParameters[i][1] << ", ";
		cout << ringsParameters[i][2] << ", ";
		cout << ringsParameters[i][3] << ")" << endl << endl;
		try
		{
			rings[i] = new Ring(ringsParameters[i][0], ringsParameters[i][1],
				ringsParameters[i][2], ringsParameters[i][3]);
			PrintRing(rings[i]);
			cout << endl << endl;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl << endl;
		}
		cout << "Всего колец: " << Ring::GetAllRingsCount() << endl << endl;
	}
	
	for (int i = 0; i < ringsCount; i++)
	{
		delete[] ringsParameters[i];
	}
	delete [] ringsParameters;
	//TODO: Почему delete вызван только для первого элемента?
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
	//TODO: Тоже что и выше - дубли
	const int rectanglesCount = 3;
	Rect** rectangles = new Rect * [rectanglesCount];

	const int rectanglesParametersCount = 4;
	double** rectanglesParameters = new double* [rectanglesCount]
	{
		new double[rectanglesParametersCount] {5.5, -6.6, 13.0, 15.0},
		new double[rectanglesParametersCount] {-1.5, 2.5, -1.0, 5.5},
		new double[rectanglesParametersCount] {3.5, -5.2, 7.5, -10.6}
	};

	for (int i = 0; i < rectanglesCount; i++)
	{
		cout << "Создание прямоугольника №" << i + 1 << ": Ring(";
		cout << rectanglesParameters[i][0] << ", ";
		cout << rectanglesParameters[i][1] << ", ";
		cout << rectanglesParameters[i][2] << ", ";
		cout << rectanglesParameters[i][3] << ")" << endl << endl;
		try
		{
			rectangles[i] = new Rect(rectanglesParameters[i][0], 
				rectanglesParameters[i][1], rectanglesParameters[i][2], 
				rectanglesParameters[i][3]);
			PrintRectangle(rectangles[i]);
			cout << endl << endl;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl << endl;
		}
		cout << "Всего прямоугольников: " << Rect::GetAllRectsCount() << endl << endl;
	}

	for (int i = 0; i < rectanglesCount; i++)
	{
		delete[] rectanglesParameters[i];
	}
	delete[] rectanglesParameters;
	//TODO: Почему delete вызван только для первого элемента?
	delete rectangles[0];
	delete[] rectangles;

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
		Rect(5.0, 3.0, 1.0, 3.0),
		Rect(9.0, 8.0, 2.0, 1.0),

		Rect(7.0, 10.0, 4.5, 6.0),
		Rect(6.0, 3.0, 12.5, 5.5)
	};

	cout << "ПРЯМОУГОЛЬНИКИ" << endl << endl;

	for (int i = 0; i < rectsCount; i += 2)
	{
		cout << "Прямоуголиник №" << i + 1 << ":" << endl;
		PrintRectangle(&rects[i]);
		cout << endl << endl;

		cout << "Прямоуголиник №" << i + 2 << ":" << endl;
		PrintRectangle(&rects[i + 1]);
		cout << endl << endl;
		if (CollisionManager::IsCollision(rects[i], rects[i + 1]))
		{
			cout << "Прямоугольники " << i + 1 << " и " << i + 2;
			cout << " пересекаются" << endl << endl;
		}
		else
		{
			cout << "Прямоугольники " << i + 1 << " и " << i + 2;
			cout << " не пересекаются" << endl << endl;
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
		PrintRing(&rings[i]);
		cout << endl << endl;

		cout << "Кольцо №" << i + 2 << ":" << endl;
		PrintRing(&rings[i + 1]);
		cout << endl << endl;

		if (CollisionManager::IsCollision(rings[i], rings[i + 1]))
		{
			cout << "Кольца " << i + 1 << " и " << i + 2;
			cout << " пересекаются" << endl << endl;
		}
		else
		{
			cout << "Кольца " << i + 1 << " и " << i + 2;
			cout << " не пересекаются" << endl << endl;
		}
	}

	PrintLine();
}
