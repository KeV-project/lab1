#include "Book.h"

void Book::SetTitle(const string& title)
{
	this->_title = title;
}

void Book::SetYear(const int year)
{
	if (year < 0 || year > 2020)
	{
		string message = "Число " + to_string(year) +
			" не входит в допустимый диапазон значений [0, 2020]\n"
			"и не может определять год издания книги";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_year = year;
}

void Book::SetPagesCount(const int pagesCount)
{
	if (pagesCount <= 0)
	{
		string message = "Число " + to_string(pagesCount) +
			" не является положительным\n"
			"и не может определять количество страниц в книге";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_pagesCount = pagesCount;
}

void Book::SetAuthors(string* authors, const int authorsCount)
{
	if (authorsCount < 0 || authorsCount > 10)
	{
		string message = "Число " + to_string(authorsCount) +
			" не входит\nв допустимый диапазон значений [0, 10]";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_authorsCount = authorsCount;
	this->_authors = authors;
}

string Book::GetTitle()
{
	return this->_title;
}

int Book::GetYear()
{
	return this->_year;
}

int Book::GetPagesCount()
{
	return this->_pagesCount;
}

int Book::GetAuthorsCount()
{
	return this->_authorsCount;
}

string* Book::GetAuthors()
{
	return this->_authors;
}

Book::Book()
{
	SetTitle("");
	SetYear(2020);
	SetPagesCount(1);
	SetAuthors(nullptr, 0);
}

Book::Book(const string& title, const int year, const int pagesCount,
	string* authors, const int authorsCount)
{
	SetTitle(title);
	SetYear(year);
	SetPagesCount(pagesCount);
	SetAuthors(authors, authorsCount);
}

Book::~Book()
{
	delete[] _authors;
}

void Book::ReadBookFromConsole()
{
	cout << "Введите название книги: ";
	string title = "";
	getline(cin, title, '\n');
	cout << endl;
	SetTitle(title);
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
				SetYear(year);
				break;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
		}
		else
		{
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
				SetPagesCount(pagesCount);
				break;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
		}
		else
		{
			cout << "Пожалуйста, введите целое число" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите количество авторов книги: ";
		int authorsCount = 0;
		cin >> authorsCount;
		cout << endl;
		if (IsValue() && authorsCount >= 0)
		{
			string* authors = nullptr;
			if (authorsCount > 0)
			{
				authors = new string[authorsCount];
				for (int i = 0; i < authorsCount; i++)
				{
					cout << "Введите автора №" << i + 1 << ": ";
					getline(cin, authors[i], '\n');
					cout << endl;
				}
			}
			SetAuthors(authors, authorsCount);
			break;
		}
		else
		{
			cout << "Пожалуйста, введите неотрицательное целое число";
			cout << endl << endl;
		}
	} while (true);
}

void Book::WriteBookToConsole()
{
	for (int i = 0; i < _authorsCount; i++)
	{
		cout << _authors[i];
		if (i + 1 == _authorsCount)
		{
			cout << " ";
		}
		else
		{
			cout << ", ";
		}
	}
	cout << _title << ". ";
	cout << _year << ". ";
	cout << "- " << _pagesCount << "c." << endl << endl;
}
