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
	Person person("��������", "��������", "���������");
	ShowName(&person);

	Student student("�������", "������", "���������", 192, 2018);
	ShowName(&student);

	Teacher teacher("�����", "����", "��������������",
		"������� �������������");
	ShowName(&teacher);

	PrintLine();
}