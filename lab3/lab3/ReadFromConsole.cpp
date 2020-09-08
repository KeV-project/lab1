#include "ReadFromConsole.h"

Book* ReadBook()
{
	Book* book = new Book;
	cout << "Введите название книги: ";
	cin.ignore(cin.rdbuf()->in_avail());
	string title = "";
	getline(cin, title, '\n');
	cin.clear();
	cout << endl;
	book->SetTitle(title);
	do
	{
		cout << "Введите год издания книги: ";
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
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные\n";
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите количество страниц в книге: ";
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
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные\n";
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите количество авторов книги: ";
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
				cout << "Введите автора №" << i + 1 << ": ";
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
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные\n";
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	return book;
}

Book** ReadBooks(const int booksCount)
{
	Book** books = new Book * [booksCount];
	for (int i = 0; i < booksCount; i++)
	{
		cout << "КНИГА №" << i + 1 << ":" << endl << endl;
		books[i] = ReadBook();
	}
	return books;
}

Route* ReadRoute()
{
	Route* route = new Route;
	do
	{
		cout << "Введите номер рейса: ";
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
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные\n";
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите продолжительность рейса: ";
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
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные\n";
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите периодичность рейса: ";
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
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные\n";
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите количество остановок рейса: ";
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
				cout << "Введите остановку №" << i + 1 << ": ";
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
			cout << "ИСКЛЮЧЕНИЕ: Некорректные входные данные\n";
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	return route;
}

Route** ReadRoutes(const int routesCount)
{
	Route** routes = new Route*[routesCount];
	for (int i = 0; i < routesCount; i++)
	{
		cout << "РЕЙС №" << i + 1 << ":" << endl << endl;
		routes[i] = ReadRoute();
	}
	return routes;
}
