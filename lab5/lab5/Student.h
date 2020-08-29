#pragma once
#include "Person.h"

class Student : public Person
{
private:
	int _gradebookNum;
	int _entranceYear;

public:
	void SetRecordBookNum(int recordBookNum);
	void SetEntranceYear(int year);

	int GetRecordBookNum();
	int GetEntranceYear();

	Student();
	Student(const string& surname, const string& name,
		const string& patronymic, const int gradebookNumber,
		const int year) : Person(name, surname, patronymic){}
};
