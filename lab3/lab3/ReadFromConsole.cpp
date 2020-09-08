#include "ReadFromConsole.h"

Book* ReadBook()
{
	Book* book = new Book;
	cout << "������� �������� �����: ";
	cin.ignore(cin.rdbuf()->in_avail());
	string title = "";
	getline(cin, title, '\n');
	cin.clear();
	cout << endl;
	book->SetTitle(title);
	do
	{
		cout << "������� ��� ������� �����: ";
		int year = 0;
		cin >> year;
		cout << endl;
		if (IsValue())
		{
			try
			{
				book->SetYear(year);
				break;
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
			}
		}
		else
		{
			cout << "����������: ������������ ������� ������\n";
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ���������� ������� � �����: ";
		int pagesCount = 0;
		cin >> pagesCount;
		cout << endl;
		if (IsValue())
		{
			try
			{
				book->SetPagesCount(pagesCount);
				break;
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
			}
		}
		else
		{
			cout << "����������: ������������ ������� ������\n";
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ���������� ������� �����: ";
		int authorsCount = 0;
		cin >> authorsCount;
		cout << endl;
		if (IsValue())
		{
			string* authors = nullptr;
			try
			{
				book->SetAuthors(authors, authorsCount);
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
			authors = new string[authorsCount];
			for (int i = 0; i < authorsCount; i++)
			{
				cout << "������� ������ �" << i + 1 << ": ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, authors[i], '\n');
				cin.clear();
				cout << endl;
			}
			book->SetAuthors(authors, authorsCount);
			break;
		}
		else
		{
			cout << "����������: ������������ ������� ������\n";
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	return book;
}

Book** ReadBooks(const int booksCount)
{
	Book** books = new Book * [booksCount];
	for (int i = 0; i < booksCount; i++)
	{
		cout << "����� �" << i + 1 << ":" << endl << endl;
		books[i] = ReadBook();
	}
	return books;
}

Route* ReadRoute()
{
	Route* route = new Route;
	do
	{
		cout << "������� ����� �����: ";
		int number = 0;
		cin >> number;
		cout << endl;
		if (IsValue())
		{
			try
			{
				route->SetNumber(number);
				break;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl << endl;
			}
		}
		else
		{
			cout << "����������: ������������ ������� ������\n";
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ����������������� �����: ";
		int duration = 0;
		cin >> duration;
		cout << endl;
		if (IsValue())
		{
			try
			{
				route->SetDuration(duration);
				break;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl << endl;
			}
		}
		else
		{
			cout << "����������: ������������ ������� ������\n";
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ������������� �����: ";
		int periodicity = 0;
		cin >> periodicity;
		cout << endl;
		if (IsValue())
		{
			try
			{
				route->SetPeriodicity(periodicity);
				break;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl << endl;
			}
		}
		else
		{
			cout << "����������: ������������ ������� ������\n";
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ���������� ��������� �����: ";
		int stopsCount = 0;
		cin >> stopsCount;
		cout << endl;
		if (IsValue())
		{
			string* stops = nullptr;
			try
			{
				route->SetStops(stops, stopsCount);;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
			stops = new string[stopsCount];
			for (int i = 0; i < stopsCount; i++)
			{
				cout << "������� ��������� �" << i + 1 << ": ";
				cin.ignore(cin.rdbuf()->in_avail());
				getline(cin, stops[i], '\n');
				cin.clear();
				cout << endl;
			}
			route->SetStops(stops, stopsCount);
			break;
		}
		else
		{
			cout << "����������: ������������ ������� ������\n";
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	return route;
}

Route** ReadRoutes(const int routesCount)
{
	Route** routes = new Route*[routesCount];
	for (int i = 0; i < routesCount; i++)
	{
		cout << "���� �" << i + 1 << ":" << endl << endl;
		routes[i] = ReadRoute();
	}
	return routes;
}
