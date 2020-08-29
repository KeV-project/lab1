#include "Student.h"

void Student::SetRecordBookNum(int recordBookNum)
{
	_gradebookNum = recordBookNum;
}

void Student::SetEntranceYear(int year)
{
	_entranceYear = year;
}

int Student::GetRecordBookNum()
{
	return _gradebookNum;
}

int Student::GetEntranceYear()
{
	return _entranceYear;
}

Student::Student()
{
	SetName("");
	SetSurname("");
	SetPatronymic("");
	SetRecordBookNum(0);
	SetEntranceYear(0);
}

Student::Student(const string& surname, const string& name,
	const string& patronymic, const int gradebookNumber,
	const int entranceYear)
{
	SetRecordBookNum(gradebookNumber);
	SetEntranceYear(entranceYear);
}
