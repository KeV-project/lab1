#include "DemoWorkingWithClasses.h"

void DemoWorkingWithClasses::DemoBook()
{
	// Task 3.2.4
	const int booksCount = 5;
	Book* books = new Book [booksCount];
	cout << "��������� ������ �� 5 ����:" << endl << endl;
	for (int i = 0; i < booksCount; i++)
	{
		cout << "����� �" << i + 1 << ":" << endl << endl;
		books[i].ReadBookFromConsole();
	}
	cout << "������ ����:" << endl << endl;
	for (int i = 0; i < booksCount; i++)
	{
		cout << "����� �" << i + 1 << ": ";
		books[i].WriteBookToConsole();
	}
	delete[] books;
	PrintLine();
}
