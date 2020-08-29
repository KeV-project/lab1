#pragma once
#include "Person.h"

class Teacher : public Person
{
private:
	string _position;

public:
	void SetPosition(const string& position);

	string GetPosition();

	Teacher();
	Teacher(const string& surname, const string& name, 
		const string& patronymic, const string& position);
};

