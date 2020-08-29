#pragma once
#include "Person.h"

class Student : public Person
{
private:
	int _gradebookNum;
	int _entranceYear;

public:
	void SetGradebookNum(const int recordBookNum);
	void SetEntranceYear(const int year);

	int GetRecordBookNum();
	int GetEntranceYear();

	Student();
	Student(const string& surname, const string& name,
		const string& patronymic, const int gradebookNum,
		const int entranceYear);
};
