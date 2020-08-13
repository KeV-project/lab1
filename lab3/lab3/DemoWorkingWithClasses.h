#pragma once
#include <iostream>
#include "Output.h"
#include "Book.h"

using namespace std;

static class DemoWorkingWithClasses
{
public:
	static int FindBookByAuthor(Book* books, const int booksCount,
		const string& findedAuthor);
	static void DemoBook();
};

