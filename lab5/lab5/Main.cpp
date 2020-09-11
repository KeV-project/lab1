﻿#include <iostream>
#include "Windows.h"
#include "PrintToConsole.h"
#include "Student.h"
#include "Teacher.h"
#include "User.h"
#include "PaidUser.h"
#include "DiscountBase.h"
#include "PercentDiscount.h"
#include "CertificateDiscount.h"

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Task 5.1.5
	Person person("Савельев", "Геннадий", "Борисович");
	PrintInitials(&person);

	try
	{
		Student student("Зубарев", "Никита", "Сергеевич", 192, 1000);
		PrintInitials(&student);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	

	Teacher teacher("Сорин", "Петр", "Константинович",
		"старший преподаватель");
	PrintInitials(&teacher);

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

	// Task 5.3.6
	try
	{
		const int productsCount = 5;
		Product* products = new Product[productsCount]
		{
			Product("samsung galaxy s8", Smartphones, -20000.55),
			Product("xiaomi mi tv 4s 43", TV, 40000),
			Product("polaris pmc 0517ad", Appliances, 4000),
			Product("honor 10 lite", Smartphones, 15000),
			Product("microlab m-106 black", Acoustics, 25000),
		};

		PercentDiscount percentDiscount1(20, TV);
		ShowCheckWithDiscount(&percentDiscount1, products, productsCount);

		PercentDiscount percentDiscount2(10, Appliances);
		ShowCheckWithDiscount(&percentDiscount2, products, productsCount);

		CertificateDiscount certificateDiscount1(2000, Smartphones);
		ShowCheckWithDiscount(&certificateDiscount1, products, productsCount);

		CertificateDiscount certificateDiscount2(3000, Appliances);
		ShowCheckWithDiscount(&certificateDiscount2, products, productsCount);

		delete[] products;

		PrintLine();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	
}