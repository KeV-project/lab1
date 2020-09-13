#pragma once
#include <string>
#include "ValueValidator.h"

using namespace std;

enum GenreType
{
	Jazz,
	HipHop,
	Electronic,
	Rock,
	Disco,
	Fusion,
	Pop
};

GenreType GetGenreType(const int numGenre);
string GetGenreForWrite(const GenreType& genre);