#include "Student.h"

void Student::SetGradebookNum(const int recordBookNum)
{
	ValueValidator::AssertPositiveValue(recordBookNum, 
		"номер зачетной книжки студента");
	_gradebookNum = recordBookNum;
}

void Student::SetEntranceYear(const int year)
{
	const int minYear = 0;
	const int maxYear = 2020;
	ValueValidator::AssertValueInRange(year, minYear, 
		maxYear, "год постуления студента");
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
	SetGradebookNum(0);
	SetEntranceYear(0);
}

Student::Student(const string& surname, const string& name,
	const string& patronymic, const int gradebookNum, 
	const int entranceYear) : Person(surname, name, patronymic)
{
	SetGradebookNum(gradebookNum);
	SetEntranceYear(entranceYear);
}



