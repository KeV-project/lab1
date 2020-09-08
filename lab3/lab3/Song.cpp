#include "Song.h"

void Song::SetTitle(const string& title)
{
	this->_title = title;
}

void Song::SetDuration(const int duration)
{
	//TODO: Для максимальной границы есть встроенные константы, например INT32_MAX	
	int const minDuration = 0;
	int const maxDuration = 2147483647;
	AssertValueInRange(duration, minDuration, maxDuration,
		NotNonNegative, "продолжительность песни");
	this->_duration = duration;
}

void Song::SetGenre(const GenreType& genre)
{
	this->_genre = genre;
}

void Song::SetSong(const string& title, const int duration, const GenreType& genre)
{
	SetTitle(title);
	SetDuration(duration);
	SetGenre(genre);
}

string Song::GetTitle()
{
	return this->_title;
}
float Song::GetDuration()
{
	return this->_duration;
}

GenreType Song::GetGenre()
{
	return this->_genre;
}

Song::Song()
{
	SetTitle("");
	SetDuration(0);
	SetGenre(Jazz);
}

Song::Song(const string& title, const int duration, const GenreType& genre)
{
	SetTitle(title);
	SetDuration(duration);
	SetGenre(genre);
}
