#include "User.h"

void User::SetId(const int id)
{
	ValueValidator::AssertPositiveValue(id, "id пользователя");
	_id = id;
}
void User::SetLogin(const string& login)
{
	if (login.find("}") != -1 || login.find("{") != -1 
		|| login.find(">") != -1 || login.find("<") != -1 
		|| login.find("@") != -1 || login.find("#") != -1 
		|| login.find("$") != -1 || login.find("%") != -1 
		|| login.find("^") != -1 || login.find(":") != -1 
		|| login.find("*") != -1)
	{
		throw exception("Логин не должен содержать следующие символы:"
		"\n{, }, <, >, @, # , $, %, ^, :, *");
	}
	_login = login;
}
void User::SetPassword(const string& password)
{
	_password = password;
}

int User::GetId() 
{ 
	return _id; 
}

string User::GetLogin()
{ 
	return _login; 
}

string User::GetPassword() 
{
	return _password; 
}

User::User()
{
	SetLogin("");
	SetPassword("");
	SetId(0);
}

User::User(const int id, const string& login, const string& password)
{
	SetId(id);
	SetLogin(login);
	SetPassword(password);
}
bool User::IsCorrectPassword(const string& password)
{
	return (password == _password);
}

User* Login(User** users, const int usersCount, 
	const string& enteredLogin, const string& enteredPassword)
{
	for (int i = 0; i < usersCount; i++)
	{
		if (users[i]->GetLogin() == enteredLogin)
		{
			if (users[i]->IsCorrectPassword(enteredPassword))
			{
				return users[i];
			}
			else
			{
				throw exception("Неверный пароль");
			}
		}
	}
	return nullptr;
}