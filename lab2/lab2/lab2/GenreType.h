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

void ReadGenre(int numGenre, GenreType& filmsGenre);
string PrintGenre(GenreType& filmsGenre);