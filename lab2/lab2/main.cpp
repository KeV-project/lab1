#include <iostream>
#include "Output.h"
#include "CatchExeption.h"
#include "Rectangle.h"
#include "Flight.h"
#include "Film.h"
#include "Time.h"
#include "EducationFormType.h"
#include "ColorType.h"
#include "PhoneManufacturerType.h"
#include "SeasonType.h"
#include "WeekdaysType.h"

using namespace std;

// Task 2.2.4.4
void WrongPointers()
{
	Flight SomeFlight;
	Film SomeFilm;
	Flight* pFlight = &SomeFlight;
	Film* pFilm = &SomeFilm;
	//pFlight = &SomeFilm;
	//pFilm = &SomeFlight;
}

void DemoEnums()
{
	// Task 2.2.8.3
	ColorType color = Red;
	WeekdaysType day = Monday;
	GenreType genre = Comedy;
	EducationFormType form = FullTime;
	PhoneManufacturerType manufacturer = Samsung;
	SeasonType season = Spring;

	// Task 2.2.8.4
	const int enumsCount = 6;

	ColorType colors[enumsCount];
	colors[0] = Red;
	colors[1] = Orange;
	colors[2] = Yellow;
	colors[3] = Green;
	colors[4] = Blue;
	colors[5] = Purple;

	// Task 2.2.8.5
	cout << "������ ������������ ���� Color:" << endl << endl;
	for (int i = 0; i < enumsCount; i++)
	{
		PrintColor(colors[i]);
	}
	PrintLine();

	// Task 2.2.8.6
	ColorType color2 = ReadColor();
	cout << "�� �����:" << endl << endl;
	PrintColor(color2);
	PrintLine();

	WeekdaysType weekdays[enumsCount];
	weekdays[0] = Tuesday;
	weekdays[1] = Wednesday;
	weekdays[2] = Thursday;
	weekdays[3] = Friday;
	weekdays[4] = Saturday;
	weekdays[5] = Sunday;

	GenreType genres[enumsCount];
	genres[0] = Comedy;
	genres[1] = Drama;
	genres[2] = Thriller;
	genres[3] = Action;
	genres[4] = Horror;
	genres[5] = Blockbuster;

	EducationFormType forms[enumsCount];
	forms[0] = FullTime;
	forms[1] = PartTime;
	forms[2] = Evening;
	forms[3] = Distance;
	forms[4] = FullTime;
	forms[5] = PartTime;

	PhoneManufacturerType manufacturers[enumsCount];
	manufacturers[0] = Samsung;
	manufacturers[1] = Apple;
	manufacturers[2] = Xiaomi;
	manufacturers[3] = Nokia;
	manufacturers[4] = Motorola;

	SeasonType seasons[enumsCount];
	seasons[0] = Spring;
	seasons[1] = Summer;
	seasons[2] = Autumn;
	seasons[3] = Winter;
	seasons[4] = Spring;
	seasons[5] = Summer;
}

void main()
{
	setlocale(LC_ALL, "rus");

    // Task 2.2.1.1 - 2.2.1.2
    //DemoSort();
    //PrintLine();

    //DemoRectangle();
    //DemoFlight();
    //DemoFilm();
    //DemoTime();

	// Task 2.2.7.2, 2.2.7.3
	cout << "������������ ������ ������� �����������" << endl << endl;
	PrintLine();

	Rectangle* rectangle = MakeRectangle(16.5, 12.6, "�����");
	cout << "������������ �������������:" << endl << endl;
	PrintRectangle(*rectangle);
	Rectangle* copyRectangle = CopyRectangle(*rectangle);
	cout << "����� ��������������:" << endl << endl;
	PrintRectangle(*copyRectangle);
	delete rectangle;
	delete copyRectangle;
	PrintLine();

	Flight* flight = MakeFlight("11D5N", 333, "������", "���������", 180, 5600, 120);
	cout << "������������ ����:" << endl << endl;
	PrintFlight(*flight);
	Flight* copyFlight = CopyFlight(*flight);
	cout << "����� �����:" << endl << endl;
	PrintFlight(*copyFlight);
	delete flight;
	delete copyFlight;
	PrintLine();

	Film* film = MakeFilm("���������", 155, 2000, Drama, 8.6, 103,
		"����� �����", "������ ����");
	cout << "������������ �����:" << endl << endl;
	PrintFilm(*film);
	Film* copyFilm = CopyFilm(*film);
	cout << "����� ������:" << endl << endl;
	PrintFilm(*copyFilm);
	delete film;
	delete copyFilm;
	PrintLine();

	Time* event = MakeTime(2016, 10, 12, 15, 3, 30);
	cout << "������������ �������" << endl << endl;
	PrintTime(*event);
	Time* copyEvent = CopyTime(*event);
	cout << "����� �������:" << endl << endl;
	PrintTime(*copyEvent);
	delete event;
	delete copyEvent;
	PrintLine();

	DemoEnums();
	
	system("pause");
}