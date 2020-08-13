#pragma once

#include <iostream>
#include <string>
#include "Input.h"

using namespace std;

class Book
{
private:
	string _title;
	int _year;
	int _pagesCount;
	int _authorsCount;
	string* _authors;

public:
	void SetTitle(const string& title);
	void SetYear(const int year);
	void SetPagesCount(const int pagesCount);
	void SetAuthors(string* authors, const int authorsCount);

	string GetTitle();
	int GetYear();
	int GetPagesCount();
	int GetAuthorsCount();
	string* GetAuthors();

	Book();
	Book(const string& title, const int year, const int pagesCount,
		const int authorsCount, string* author);

	~Book();

	void ReadBookFromConsole();
};

