#pragma once
#include "ValueValidator.h"
#include "Person.h"

class Student : public Person
{
private:
	int _gradebookNumber;
	int _entranceYear;

public:
	//TODO: RSDN+
	void SetGradebookNumber(const int gradebookNumber);
	void SetEntranceYear(const int year);

	int GetRecordBookNumber();
	int GetEntranceYear();

	Student();
	Student(const string& surname, const string& name,
		 //TODO: RSDN +
		const string& patronymic, const int gradebookNumber,
		const int entranceYear);
};
