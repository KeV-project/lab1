#include "Book.h"

void Book::SetTitle(const string& title)
{
	this->_title = title;
}

void Book::SetYear(const int year)
{
	//TODO: дубль +
	//TODO: Сообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы +
	int const minLimit = 0;
	int const maxLimit = 2020;
	if (!IsValueInRange(year, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(year, minLimit,
			maxLimit, "год издания книги").c_str());
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
			maxLimit, "количество страниц в книге").c_str());
		throw exception(message);
	}
	this->_pagesCount = pagesCount;
}

void Book::SetAuthors(string* authors, const int authorsCount)
{
	//TODO: дубль +
	//TODO: Сообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы +
	int const minLimit = 0;
	int const maxLimit = 10;
	if (!IsValueInRange(authorsCount, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(authorsCount, minLimit,
			maxLimit, "количество авторов книге").c_str());
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

int FindBookByAuthor(Book** books, const int booksCount, 
	const string& findedAuthor)
{
	for (int i = 0; i < booksCount; i++)
	{
		for (int j = 0; j < books[i]->GetAuthorsCount(); j++)
		{
			if (books[i]->GetAuthors()[j] == findedAuthor)
			{
				return i;
			}
		}
	}
	return -1;
}