#include "Book.h"

void Book::SetTitle(const string& title)
{
	this->_title = title;
}

void Book::SetYear(const int year)
{
	if (year < 0 || year > 2020)
	{
		throw exception("Год выпуска книги "
			"задается числом в диапазоне [0, 2020]");
	}
	this->_year = year;
}

void Book::SetPagesCount(const int pagesCount)
{
	if (pagesCount <= 0)
	{
		throw exception("Количество страниц в книге "
			"задается положительным числом");
	}
	this->_pagesCount = pagesCount;
}

void Book::SetAuthors(string* authors, const int authorsCount)
{
	if (authorsCount <= 0)
	{
		throw exception("Количество авторов книги "
			"задается положительным числом");
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

Book::Book(const string& title, const int year, const int pagesCount,
	const int authorsCount, string* authors)
{
	SetTitle(title);
	SetYear(year);
	SetPagesCount(pagesCount);
	SetAuthors(authors, authorsCount);
}
