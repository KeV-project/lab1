#include "Teacher.h"

void Teacher::SetPosition(string position)
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

Teacher::Teacher(string name, string surname, string patronymic, string position)
{
	SetName(name);
	SetSurname(surname);
	SetPatronymic(patronymic);
	SetPosition(position);
}
