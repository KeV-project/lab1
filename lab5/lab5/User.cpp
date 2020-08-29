#include "User.h"

void User::SetId(const int id)
{
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
		"{, }, <, >, @, # , $, %, ^, :, *");
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

