#include "DemoWorkingWithClasses.h"

int DemoWorkingWithClasses::FindBookByAuthor(Book* books, const int booksCount, const string& findedAuthor)
{
	for (int i = 0; i < booksCount; i++)
	{
		for (int j = 0; j < books[i].GetAuthorsCount(); j++)
		{
			if (books[i].GetAuthors()[j] == findedAuthor)
			{
				return i;
			}
		}
	}
	return -1;
}

void DemoWorkingWithClasses::DemoBook()
{
	// Task 3.2.4
	const int booksCount = 5;
	Book* books = new Book [booksCount];
	cout << "��������� ������ �� 5 ����:" << endl << endl;
	for (int i = 0; i < booksCount; i++)
	{
		cout << "����� �" << i + 1 << ":" << endl << endl;
		books[i].ReadBookFromConsole();
	}
	cout << "������ ����:" << endl << endl;
	for (int i = 0; i < booksCount; i++)
	{
		cout << "����� �" << i + 1 << ": ";
		books[i].WriteBookToConsole();
	}
	PrintLine();

	// Task 3.2.5
	cout << "������� ������ ��� ������ �����: ";
	string findedAuthor = "";
	cin >> findedAuthor;
	cout << endl;
	int findedBookIndex = FindBookByAuthor(books, booksCount, findedAuthor);
	if (findedBookIndex == -1)
	{
		cout << "����� " << findedAuthor << " ��� � �������" << endl << endl;
	}
	else
	{
		cout << "����� ������: ";
		books[findedBookIndex].WriteBookToConsole();
	}

	delete[] books;

	PrintLine();
}

int DemoWorkingWithClasses::FindRouteTo(Route* routes, const int routesCount, const string& findedStop)
{
	for (int i = 0; i < routesCount; i++)
	{
		for (int j = 0; j < routes[i].GetStopsCount(); j++)
		{
			if (routes[i].GetStops()[j] == findedStop)
			{
				return i;
			}
		}
	}
	return -1;
}

void DemoWorkingWithClasses::DemoRoute()
{
	const int routesCount = 5;
	Route* routes = new Route[routesCount];
	cout << "��������� ������ �� 5 ������:" << endl << endl;
	for (int i = 0; i < routesCount; i++)
	{
		cout << "���� �" << i + 1 << ":" << endl << endl;
		routes[i].ReadRouteFromConsole();
	}
	cout << "������ ������:" << endl << endl;
	for (int i = 0; i < routesCount; i++)
	{
		routes[i].WriteRouteToConsole();
	}
	PrintLine();

	cout << "������� ��������� ��� ������ �����: ";
	string findedStop = "";
	cin >> findedStop;
	cout << endl;
	int findedRouteIndex = FindRouteTo(routes, routesCount, findedStop);
	if (findedRouteIndex == -1)
	{
		cout << "�� ���������� ����� � ���������� " << findedStop << endl << endl;
	}
	else
	{
		cout << "����, ���������� ��������� " << findedStop << endl << endl;
		routes[findedRouteIndex].WriteRouteToConsole();
	}

	delete[] routes;

	PrintLine();
}

void DemoWorkingWithClasses::WriteRectangles(Rectangle** rectangles, const int rectanglesCount)
{
	cout << "������ ���������������:" << endl << endl;
	for (int i = 0; i < rectanglesCount; i++)
	{
		cout << "������������� �" << i + 1 << ": " << endl;
		rectangles[i]->WriteRectangle();
	}
}

float DemoWorkingWithClasses::GetMeanCenterX(Rectangle** rectangles, const int rectanglesCount)
{
	float sumCenterX = 0.0;
	for (int i = 0; i < rectanglesCount; i++)
	{
		sumCenterX += rectangles[i]->GetCenterX();
	}
	return sumCenterX / rectanglesCount;
}

float DemoWorkingWithClasses::GetMeanCenterY(Rectangle** rectangles, const int rectanglesCount)
{
	float sumCenterY = 0.0;
	for (int i = 0; i < rectanglesCount; i++)
	{
		sumCenterY += rectangles[i]->GetCenterY();
	}
	return sumCenterY / rectanglesCount;
}

void DemoWorkingWithClasses::DemoRectangleWithPoint()
{
	// Task 3.3.3 - 3.3.4
	const int rectanglesCount = 5;
	Rectangle** rectangles = new Rectangle*[rectanglesCount]
	{
		new Rectangle(15.5, 13.6, -2, 3),
		new Rectangle(7.3, 5.4, 6, 1),
		new Rectangle(19.0, 12.5, 15, -9),
		new Rectangle(8.2, 7.0, -10, 10),
		new Rectangle(4.7, 2.5, 0.0, 0.0),
	};

	WriteRectangles(rectangles, rectanglesCount);

	PrintLine();

	// Task 3.3.5
	cout << "meanCenterX: " << GetMeanCenterX(rectangles, rectanglesCount) << endl << endl;
	cout << "meanCenterY: " << GetMeanCenterY(rectangles, rectanglesCount) << endl << endl;

	PrintLine();

	for (int i = 0; i < rectanglesCount; i++)
	{
		delete rectangles[i];
	}
	delete[] rectangles;
}

void DemoWorkingWithClasses::WriteFlights(Flight** flights, const int flightsCount)
{
	for (int i = 0; i < flightsCount; i++)
	{
		flights[i]->WriteFlight();
	}
}

void DemoWorkingWithClasses::DemoFlightWithTime()
{
	// Task 3.3.9
	int const flightCount = 5;
	Flight** flights = new Flight * [flightCount]
	{
		new Flight(1, "������", "��������", 2020, 10, 9, 10, 40, 30, 2020, 10, 9, 13, 50, 10),
		new Flight(2, "������", "�������", 2020, 11, 11, 13, 20, 25, 2020, 11, 11, 20, 25, 5),
		new Flight(3, "�������", "�������", 2020, 11, 12, 13, 15, 40, 2020, 11, 12, 23, 20, 59),
		new Flight(4, "��������", "������", 2020, 12, 11, 0, 13, 20, 2020, 12, 12, 15, 7, 17),
		new Flight(5, "������", "������", 2020, 12, 23, 17, 10, 14, 2020, 12, 23, 23, 50, 40),
	};

	WriteFlights(flights, flightCount);

	PrintLine();

	for (int i = 0; i < flightCount; i++)
	{
		delete flights[i];
	}
	delete[] flights;
}
