#include <iostream>
#include "Windows.h"
#include "Output.h"
#include "Student.h"
#include "Teacher.h"
#include "User.h"
#include "PaidUser.h"

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Task 5.1.5
	Person person("Савельев", "Геннадий", "Борисович");
	ShowName(&person);

	Student student("Зубарев", "Никита", "Сергеевич", 192, 2018);
	ShowName(&student);

	Teacher teacher("Сорин", "Петр", "Константинович",
		"старший преподаватель");
	ShowName(&teacher);

	PrintLine();

	// Task 5.2.3
	const int usersCount = 4;

	User** users = new User * [usersCount]
	{
		new User(100000, "morkovka1995", "1995morkovka"),
		new User(100001, "ilon_mask", "X æ A-12"),
		new User(100002, "megazver", "password"),
		new User(100003, "yogurt", "ksTPQzSu"),
	};
	string login = "megazver";
	string password = "password";
	try
	{
		User* loginedUser = Login(users, usersCount, login, password);
		cout << loginedUser->GetLogin();
		cout << " вход в систему выполнен успешно" << endl << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		delete users[i];
	}
	delete[] users;

	User** paidUsers = new User * [usersCount]
	{
		new PaidUser(200000, "TheKnyazz", "JHPzPGFG"),
		new PaidUser(200001, "system_exe", "UgfkDGmU"),
		new PaidUser(200002, "RazorQ", "TBgRnbCP"),
		new PaidUser(200003, "schdub", "CetyQVID"),
	};
	login = "system_exe";
	password = "UgfkDGmU";
	try
	{
		User* loginedPaidUser = Login(paidUsers, 
			usersCount, login, password);
		cout << loginedPaidUser->GetLogin();
		cout << " вход в систему выполнен успешно" << endl << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		delete paidUsers[i];
	}
	delete[] paidUsers;

	PrintLine();
}