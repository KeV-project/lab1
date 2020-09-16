#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string _name;
	string _surname;
	string _patronymic;

protected:
	string field;

public:
	void SetName(const string& name);
	void SetSurname(const string& surname);
	void SetPatronymic(const string& patronymic);

	string GetName();
	string GetSurname();
	string GetPatronymic();

	Person();
	Person(const string& surname, const string& name,
		const string& patronymic);
};
