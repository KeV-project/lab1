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

GenreType ReadGenre();
string PrintGenre(const GenreType& filmsGenre);