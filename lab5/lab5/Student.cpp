#include "Student.h"

void Student::SetGradebookNum(const int gradebookNum)
{
	const int minGradebookNum = 1;
	const int maxGradebookNum = INT32_MAX;
	ValueValidator::AssertValueInRange(gradebookNum, 
		minGradebookNum, maxGradebookNum, NotPositive,
		"номер зачетной книжки студента");
	_gradebookNum = gradebookNum;
}

void Student::SetEntranceYear(const int year)
{
	// 1755 - год создания первого университета 
	const int minYear = 1755;
	const int maxYear = 2020;
	ValueValidator::AssertValueInRange(year, minYear, 
		maxYear, NotInRange, "год постуления студента");
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



