#include "DemoWorkingWithClasses.h"

void DemoWorkingWithClasses::DemoBook()
{
	// Task 3.2.2
	const int authorsCount = 1;
	string* authors = new string[authorsCount]
	{
		"������ ���������",
	};
	Book firstBook("����������� � �������", 2013, 287, 1, authors);

	// Task 3.2.3
	Book secondBook;
	secondBook.ReadBookFromConsole();
	PrintLine();
}

