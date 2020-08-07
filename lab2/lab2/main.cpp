#include <iostream>
#include "Output.h"
#include "CatchExeption.h"
#include "Rectangle.h"
#include "Flight.h"
#include "Film.h"
#include "Time.h"

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
	cout << "Демонстрация работы функции копирования" << endl << endl;
	PrintLine();

	Rectangle* rectangle = MakeRectangle(16.5, 12.6, "синий");
	cout << "Оригинальный прямоугольник:" << endl << endl;
	PrintRectangle(*rectangle);
	Rectangle* copyRectangle = CopyRectangle(*rectangle);
	cout << "Копия прямоугольника:" << endl << endl;
	PrintRectangle(*copyRectangle);
	delete rectangle;
	delete copyRectangle;
	PrintLine();

	Flight* flight = MakeFlight("11D5N", 333, "Москва", "Фьюмичино", 180, 5600, 120);
	cout << "Оригинальный рейс:" << endl << endl;
	PrintFlight(*flight);
	Flight* copyFlight = CopyFlight(*flight);
	cout << "Копия рейса:" << endl << endl;
	PrintFlight(*copyFlight);
	delete flight;
	delete copyFlight;
	PrintLine();

	Film* film = MakeFilm("Гладиатор", 155, 2000, Drama, 8.6, 103,
		"Ридли Скотт", "Рассел Кроу");
	cout << "Оригинальный фильм:" << endl << endl;
	PrintFilm(*film);
	Film* copyFilm = CopyFilm(*film);
	cout << "Копия фильма:" << endl << endl;
	PrintFilm(*copyFilm);
	delete film;
	delete copyFilm;
	PrintLine();

	Time* event = MakeTime(2016, 10, 12, 15, 3, 30);
	cout << "Оригинальное событие" << endl << endl;
	PrintTime(*event);
	Time* copyEvent = CopyTime(*event);
	cout << "Копия события:" << endl << endl;
	PrintTime(*copyEvent);
	delete event;
	delete copyEvent;
	PrintLine();
	
	system("pause");
}