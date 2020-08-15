#include "Book.h"

void Book::SetTitle(const string& title)
{
	this->_title = title;
}

void Book::SetYear(const int year)
{
	if (year <= 0 || year > 2020)
	{
		string message = "����� " + to_string(year) +
			" �� ������ � ���������� �������� �������� [0, 2020]\n"
			"� �� ����� ���������� ��� ������� �����";
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
		string message = "����� " + to_string(pagesCount) +
			" �� �������� ������������� "
			"� �� ����� ����������\n���������� ������� � �����";
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
		string message = "����� " + to_string(authorsCount) +
			" �� ������ � ���������� �������� �������� [0, 10]";
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
	SetYear(1);
	SetPagesCount(1);
	SetAuthors(nullptr, 0);
}

Book::Book(const string& title, const int year, const int pagesCount,
	const int authorsCount, string* authors)
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
	cout << "������� �������� �����: ";
	string title = "";
	cin >> title;
	cout << endl;
	SetTitle(title);
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
			cout << "����������, ������� ����� �����" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ���������� ������� �����: ";
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
					cout << "������� ������ �" << i + 1 << ": ";
					cin >> authors[i];
					cout << endl;
				}
			}
			SetAuthors(authors, authorsCount);
			break;
		}
		else
		{
			cout << "����������, ������� ��������������� ����� �����" << endl << endl;
		}
	} while (true);
}

void Book::WriteBookToConsole()
{
	for (int i = 0; i < this->_authorsCount; i++)
	{
		cout << this->_authors[i];
		if (i + 1 == _authorsCount)
		{
			cout << " ";
		}
		else
		{
			cout << ", ";
		}
	}
	cout << this->_title << ". ";
	cout << this->_year << ". ";
	cout << "- " << this->_pagesCount << "c." << endl << endl;
}
