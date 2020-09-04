#include "ReadFromConsole.h"

Book* ReadBook()
{
	//TODO: ����� ������ +
	//TODO: ���� ����� �� ������ ��� ����������, �.�. ����� ������� �� �������������� ��� � �������, ���������� ���� ����� ������� +
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
			cout << MakeMessage(year) << endl << endl;
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
			cout << MakeMessage(pagesCount) << endl << endl;
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
			cout << MakeMessage(authorsCount) << endl << endl;
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
