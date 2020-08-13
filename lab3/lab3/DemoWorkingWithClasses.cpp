#include "DemoWorkingWithClasses.h"

void DemoWorkingWithClasses::DemoBook()
{
	// Task 3.2.2
	const int authorsCount = 1;
	string* authors = new string[authorsCount]
	{
		"Карлос Кастанеда",
	};
	Book book("Путешествие в Икстлан", 2013, 287, 1, authors);
	delete[] authors;
}

