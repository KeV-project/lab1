#include "Book.h"

void Book::SetTitle(const string& title)
{
	this->_title = title;
}

void Book::SetYear(const int year)
{
	int const minYear = -2400;
	int const maxYear = 2020;
	ValueValidator::AssertValueInRange(year, minYear,
		maxYear, NotInRange, "год издания книги");
	this->_year = year;
}

void Book::SetPagesCount(const int pagesCount)
{
	int const minPagesCount = 1;
	int const maxPagesCount = 1000000;
	ValueValidator::AssertValueInRange(pagesCount, minPagesCount,
		maxPagesCount, NotInRange, "количество страниц в книге");
	this->_pagesCount = pagesCount;
}

void Book::SetAuthors(string* authors, const int authorsCount)
{
	// В конструкторе по умолчанию книга может быть инициализирована без указания авторов
	// Автор книги может быть неизвестен
	int const minAuthorsCount = 0;
	int const maxAuthorsCount = 10;
	ValueValidator::AssertValueInRange(authorsCount, minAuthorsCount,
		maxAuthorsCount, NotInRange, "количество авторов книги");
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

string Book::GetYearForWrite()
{
	if (ValueValidator::IsValueInRange(_year, -2400, 1))
	{
		return to_string(_year * -1) + " год до н.э";
	}
	return to_string(_year) + " г";
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