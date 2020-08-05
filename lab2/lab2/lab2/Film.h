#pragma once

#include <iostream>
#include "GenreType.h"

using namespace std;

struct Film
{
	string Title;
	int Duration;
	int Year;
	GenreType Genre;
	float Rating;
	// Ѕюджет фильма в миллионах
	float Budget;
	string Director;
	string MainRole;
};

void DemoFilm();