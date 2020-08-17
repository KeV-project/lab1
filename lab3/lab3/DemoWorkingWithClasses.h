#pragma once
#include <iostream>
#include "Output.h"
#include "Book.h"
#include "Route.h"
#include "Rectangle.h"

using namespace std;

static class DemoWorkingWithClasses
{
public:
	static int FindBookByAuthor(Book* books, const int booksCount,
		const string& findedAuthor);
	static void DemoBook();

	static int FindRouteTo(Route* routes, const int routesCount,
		const string& findedStop);
	static void DemoRoute();

	static void DemoRectangleWithPoint();
};

