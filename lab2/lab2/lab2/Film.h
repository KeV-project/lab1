#pragma once

#include <iostream>

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
