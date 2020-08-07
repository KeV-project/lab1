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
    DemoFlight();
    DemoFilm();
    DemoTime();

	system("pause");
}