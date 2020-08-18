#pragma once
#include <string>
#include "Input.h"

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