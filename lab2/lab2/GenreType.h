#pragma once

#include <iostream>
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

GenreType ReadGenre(const int numGenre);
string PrintGenre(const GenreType& filmsGenre);