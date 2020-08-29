#pragma once
#include <string>
using namespace std;

class User
{
private:
	string _login;
	string _password;

protected:
	int _id;
	void SetId(const int id);

public:
	void SetLogin(const string& login);
	void SetPassword(const string& password);

	int GetId();
	string GetLogin();
	string GetPassword();

	User();
	User(const int id, const string& login, const string& password);

	bool IsCorrectPassword(const string& password);
};

