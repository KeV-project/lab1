#include "Person.h"

void Person::SetName(const string& name)
{
	this->_name = name;
}

void Person::SetSurname(const string& surname)
{
	this->_surname = surname;
}

void Person::SetPatronymic(const string& patronymic)
{
	this->_patronymic = patronymic;
}

string Person::GetName()
{
	return _name;
}

string Person::GetSurname()
{
	return _surname;
}

string Person::GetPatronymic()
{
	return _patronymic;
}

Person::Person()
{
	SetName("");
	SetSurname("");
	SetPatronymic("");
}

Person::Person(const string& surname, const string& name,
	const string& patronymic)
{
	SetName(name);
	SetSurname(surname);
	SetPatronymic(patronymic);
}
