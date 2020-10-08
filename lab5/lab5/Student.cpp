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
	//TODO: Не согласен https://www.wikiwand.com/ru/%D0%A1%D0%BF%D0%B8%D1%81%D0%BE%D0%BA_%D1%81%D1%82%D0%B0%D1%80%D0%B5%D0%B9%D1%88%D0%B8%D1%85_%D1%83%D0%BD%D0%B8%D0%B2%D0%B5%D1%80%D1%81%D0%B8%D1%82%D0%B5%D1%82%D0%BE%D0%B2
	// 1755 - год создания первого университета +
	const int minYear = 1088;
	const int maxYear = 2020;
	ValueValidator::AssertValueInRange(year, minYear, 
		maxYear, NotInRange, "год поступления студента");
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



