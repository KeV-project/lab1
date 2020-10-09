#include "Student.h"

void Student::SetGradebookNumber(const int gradebookNumber)
{
	const int minGradebookNum = 1;
	const int maxGradebookNum = INT32_MAX;
	ValueValidator::AssertValueInRange(gradebookNumber, 
		minGradebookNum, maxGradebookNum, NotPositive,
		"номер зачетной книжки студента");
	_gradebookNumber = gradebookNumber;
}

void Student::SetEntranceYear(const int year)
{
	const int minYear = 1088;
	const int maxYear = 2020;
	ValueValidator::AssertValueInRange(year, minYear, 
		maxYear, NotInRange, "год поступления студента");
	_entranceYear = year;
}

int Student::GetRecordBookNumber()
{
	return _gradebookNumber;
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
	SetGradebookNumber(0);
	SetEntranceYear(0);
}

Student::Student(const string& surname, const string& name,
	const string& patronymic, const int gradebookNumber, 
	const int entranceYear) : Person(surname, name, patronymic)
{
	SetGradebookNumber(gradebookNumber);
	SetEntranceYear(entranceYear);
}



