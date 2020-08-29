#include <iostream>
#include "Windows.h"
#include "Output.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Task 5.1.5
	Person person("Савельев", "Геннадий", "Борисович");
	ShowName(&person);

	Student student("Зубарев", "Никита", "Сергеевич", 192, 2018);
	ShowName(&student);

	Teacher teacher("Сорин", "Петр", "Константинович",
		"старший преподаватель");
	ShowName(&teacher);

	PrintLine();
}