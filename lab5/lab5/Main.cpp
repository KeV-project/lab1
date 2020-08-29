#include <iostream>
#include "Student.h"

using namespace std;

void main()
{
	Student student("Иванов", "Иван", "Иванович", 145, 2018);
	cout << student.GetName() << endl;
	cout << student.GetEntranceYear() << endl;
}