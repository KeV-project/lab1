#pragma once

#include <iostream>
#include <string>
#include "Input.h"

using namespace std;

enum GenreType
{
	Comedy,
	Drama,
	Thriller,
	Action,
	Horror,
	Blockbuster
};

GenreType GetGenreType(const int numGenre);
string PrintGenre(const GenreType& filmsGenre);