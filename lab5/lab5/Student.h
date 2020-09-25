#pragma once
#include "ValueValidator.h"
#include "Person.h"

class Student : public Person
{
private:
	int _gradebookNum;
	int _entranceYear;

public:
	//TODO: RSDN
	void SetGradebookNum(const int gradebookNum);
	void SetEntranceYear(const int year);

	int GetRecordBookNum();
	int GetEntranceYear();

	Student();
	Student(const string& surname, const string& name,
		 //TODO: RSDN
		const string& patronymic, const int gradebookNum,
		const int entranceYear);
};
