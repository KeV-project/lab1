#include "Teacher.h"

void Teacher::SetPosition(const string& position)
{
	this->_position = position;
}

string Teacher::GetPosition()
{
	return _position;
}


Teacher::Teacher()
{
	SetName("");
	SetSurname("");
	SetPatronymic("");
	SetPosition("");
}

Teacher::Teacher(const string& surname, const string& name,
	const string& patronymic, const string& position): 
	Person(surname, name, patronymic)
{
	SetPosition(position);
}
