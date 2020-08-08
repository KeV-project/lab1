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

GenreType ReadGenre();
string PrintGenre(const GenreType& filmsGenre);