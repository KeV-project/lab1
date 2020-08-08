#pragma once

#include <iostream>

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

void ReadGenre(const int numGenre, GenreType& filmsGenre);
string PrintGenre(const GenreType& filmsGenre);