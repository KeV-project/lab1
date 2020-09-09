#include "DemoFigures.h"

void DemoFigures::DemoRing()
{
	// Task 4.1.6
	//TODO: ����� ���� ������� � ���� ������ ������ � �������� ������. �������� ����� ����� ���� �� ����� �������� � ����� +
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
		cout << "�������� ������ �" << i + 1 << ": Ring(";
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
		cout << "����� �����: " << Ring::GetAllRingsCount() << endl << endl;
	}
	
	for (int i = 0; i < ringsCount; i++)
	{
		delete[] ringsParameters[i];
	}
	delete [] ringsParameters;
	//TODO: ������ delete ������ ������ ��� ������� ��������?
	delete rings[0];
	delete[] rings;

	PrintLine();

	// Task 4.4.6
	cout << "���������� ����� �� ������ ������������: ";
	cout << Ring::GetAllRingsCount();
	cout << endl << endl;
	Ring* ring = new Ring(10.0, 5.0, 25.0, 25.5);
	cout << "���������� ����� ����� ������ ������������: ";
	cout << Ring::GetAllRingsCount();
	cout << endl << endl;
	delete ring;
	cout << "���������� ����� ����� ������ �����������: ";
	cout << Ring::GetAllRingsCount();
	cout << endl << endl;

	PrintLine();
}

void DemoFigures::DemoRect()
{
	//TODO: ���� ��� � ���� - �����
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
		cout << "�������� �������������� �" << i + 1 << ": Ring(";
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
		cout << "����� ���������������: " << Rect::GetAllRectsCount() << endl << endl;
	}

	for (int i = 0; i < rectanglesCount; i++)
	{
		delete[] rectanglesParameters[i];
	}
	delete[] rectanglesParameters;
	//TODO: ������ delete ������ ������ ��� ������� ��������?
	delete rectangles[0];
	delete[] rectangles;

	PrintLine();

	// Task 4.4.6
	cout << "���������� ��������������� �� ������ ������������: ";
	cout << Rect::GetAllRectsCount();
	cout << endl << endl;
	Rect* rect = new Rect(10.0, 5.0, 25.0, 25.5);
	cout << "���������� ��������������� ����� ������ ������������: ";
	cout << Rect::GetAllRectsCount();
	cout << endl << endl;
	delete rect;
	cout << "���������� ��������������� ����� ������ �����������: ";
	cout << Rect::GetAllRectsCount();
	cout << endl << endl;

	PrintLine();
}

void DemoFigures::DemoCollision()
{
	const int rectsCount = 8;
	Rect rects[rectsCount]
	{
		//�������������� ��������������
		Rect(8.0, 4.0, 5.0, 3.0),
		Rect(9.0, 5.0, 12.5, 6.5),

		Rect(7.0, 5.0, 5.5, 6.5),
		Rect(9.0, 5.0, 10.5, 2.5),

		//���������������� ��������������
		Rect(5.0, 3.0, 1.0, 3.0),
		Rect(9.0, 8.0, 2.0, 1.0),

		Rect(7.0, 10.0, 4.5, 6.0),
		Rect(6.0, 3.0, 12.5, 5.5)
	};

	cout << "��������������" << endl << endl;

	for (int i = 0; i < rectsCount; i += 2)
	{
		cout << "������������� �" << i + 1 << ":" << endl;
		PrintRectangle(&rects[i]);
		cout << endl << endl;

		cout << "������������� �" << i + 2 << ":" << endl;
		PrintRectangle(&rects[i + 1]);
		cout << endl << endl;
		if (CollisionManager::IsCollision(rects[i], rects[i + 1]))
		{
			cout << "�������������� " << i + 1 << " � " << i + 2;
			cout << " ������������" << endl << endl;
		}
		else
		{
			cout << "�������������� " << i + 1 << " � " << i + 2;
			cout << " �� ������������" << endl << endl;
		}
	}

	const int ringsCount = 8;
	Ring rings[ringsCount]
	{
		//�������������� ������
		Ring(4.5, 2.5, 1.0, 1.5),
		Ring(7.0, 5.0, 2.5, 3.0),

		Ring(4.0, 4.0, 2.5, 4.0),
		Ring(8.0, 7.0, 1.0, 2.0),

		//���������������� ������
		Ring(3.5, 2.5, 1.0, 1.5),
		Ring(8.0, 7.0, 1.5, 2.0),

		Ring(5.0, 5.0, 2.0, 4.0),
		Ring(12.0, 8.0, 1.0, 2.0)
	};
	
	cout << "������" << endl << endl;

	for (int i = 0; i < ringsCount; i += 2)
	{
		cout << "������ �" << i + 1 << ":" << endl;
		PrintRing(&rings[i]);
		cout << endl << endl;

		cout << "������ �" << i + 2 << ":" << endl;
		PrintRing(&rings[i + 1]);
		cout << endl << endl;

		if (CollisionManager::IsCollision(rings[i], rings[i + 1]))
		{
			cout << "������ " << i + 1 << " � " << i + 2;
			cout << " ������������" << endl << endl;
		}
		else
		{
			cout << "������ " << i + 1 << " � " << i + 2;
			cout << " �� ������������" << endl << endl;
		}
	}

	PrintLine();
}
