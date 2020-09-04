#include "Book.h"

void Book::SetTitle(const string& title)
{
	this->_title = title;
}

void Book::SetYear(const int year)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minLimit = 0;
	int const maxLimit = 2020;
	if (!IsValueInRange(year, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(year, minLimit,
			maxLimit, "��� ������� �����").c_str());
		throw exception(message);
	}
	this->_year = year;
}

void Book::SetPagesCount(const int pagesCount)
{
	int const minLimit = 1;
	int const maxLimit = 1000000;
	if (!IsValueInRange(pagesCount, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(pagesCount, minLimit,
			maxLimit, "���������� ������� � �����").c_str());
		throw exception(message);
	}
	this->_pagesCount = pagesCount;
}

void Book::SetAuthors(string* authors, const int authorsCount)
{
	//TODO: ����� +
	//TODO: ��������� � ��������� �������� ����� ����������� � ������� �������� ������� �������� �������
	//TODO: �.�. ������� ������� � ��������� � � ��������� ���������� ��� ��������� +
	int const minLimit = 0;
	int const maxLimit = 10;
	if (!IsValueInRange(authorsCount, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(authorsCount, minLimit,
			maxLimit, "���������� ������� �����").c_str());
		throw exception(message);
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

void Book::ReadFromConsole()
{
	//TODO: ����� ������
	//TODO: ���� ����� �� ������ ��� ����������, �.�. ����� ������� �� �������������� ��� � �������, ���������� ���� ����� ������� 
	cout << "������� �������� �����: ";
	cin.ignore(cin.rdbuf()->in_avail());
	string title = "";
	getline(cin, title, '\n');
	cin.clear();
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
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
			}
		}
		else
		{
			cout << "����������: ������������ ������� ������" << endl;
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
			catch (exception &ex)
			{
				cout << ex.what() << endl << endl;
			}
		}
		else
		{
			cout << "����������: ������������ ������� ������" << endl;
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
					cin.ignore(cin.rdbuf()->in_avail());
					getline(cin, authors[i], '\n');
					cin.clear();
					cout << endl;
				}
			}
			SetAuthors(authors, authorsCount);
			break;
		}
		else
		{
			cout << "����������: ������������ ������� ������" << endl;
			cout << "����������, ������� ��������������� ����� �����";
			cout << endl << endl;
		}
	} while (true);
}

void Book::WriteToConsole()
{
	//TODO: ���� ��� � ����. ���������� ���������� ������, � � ��� �������� � �������
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

int FindBookByAuthor(Book* books, const int booksCount, 
	const string& findedAuthor)
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