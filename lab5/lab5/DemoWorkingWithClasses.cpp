#include "DemoWorkingWithClasses.h"

void DemoWorkingWithClasses::DemoPerson()
{
	// Task 5.1.5
	Person person("Савельев", "Геннадий", "Борисович");
	PrintInitials(&person);

	Student student("Зубарев", "Никита", "Сергеевич", 192, 2015);
	PrintInitials(&student);

	Teacher teacher("Сорин", "Петр", "Константинович",
		"старший преподаватель");
	PrintInitials(&teacher);

	PrintLine();
}

void DemoWorkingWithClasses::DemoUser()
{
	// Task 5.2.3
	const int usersCount = 4;

	User** users = new User * [usersCount]
	{
		new User(100000, "morkovka1995", "1995morkovka"),
		new User(100001, "ilon_mask", "X æ A-12"),
		new User(100002, "megazver", "password"),
		new User(100003, "yogurt", "ksTPQzSu"),
	};

	const string usersLogin = "megazver";
	const string usersPassword = "password";
	try
	{
		User* loginedUser = Login(users, usersCount, usersLogin, usersPassword);
		PrintMessageAboutEntering(loginedUser);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}

	for (int i = 0; i < usersCount; i++)
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

	const string paidUsersLogin = "system_exe";
	const string paidUsersPassword = "UgfkDGmU";
	try
	{
		User* loginedPaidUser = Login(paidUsers,
			usersCount, paidUsersLogin, paidUsersPassword);
		PrintMessageAboutEntering(loginedPaidUser);
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}

	for (int i = 0; i < usersCount; i++)
	{
		delete paidUsers[i];
	}
	delete[] paidUsers;

	PrintLine();
}

void DemoWorkingWithClasses::DemoDiscount()
{
	// Task 5.3.6
	const int productsCount = 5;
	Product* products = new Product[productsCount]
	{
		Product("samsung galaxy s8", Smartphones, 20000.00),
		Product("xiaomi mi tv 4s 43", TV, 40000.99),
		Product("polaris pmc 0517ad", Appliances, 4000.55),
		Product("honor 10 lite", Smartphones, 15000.00),
		Product("microlab m-106 black", Acoustics, 25000.05),
	};

	PercentDiscount percentDiscount1(20, TV);
	ShowCheckWithDiscount(&percentDiscount1, products, productsCount);

	PercentDiscount percentDiscount2(10, Appliances);
	ShowCheckWithDiscount(&percentDiscount2, products, productsCount);

	CertificateDiscount certificateDiscount1(30000, Smartphones);
	ShowCheckWithDiscount(&certificateDiscount1, products, productsCount);

	CertificateDiscount certificateDiscount2(3000, Appliances);
	ShowCheckWithDiscount(&certificateDiscount2, products, productsCount);

	delete[] products;

	PrintLine();
}
