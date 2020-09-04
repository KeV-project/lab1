#include "Song.h"

void Song::SetTitle(const string& title)
{
	this->_title = title;
}

void Song::SetDuration(const int duration)
{
	//TODO: Дубль
	int const minLimit = 0;
	int const maxLimit = 2147483647;
	if (!IsValueInRange(duration, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(duration, NotNonNegative,
			"продолжительность песни").c_str());
		throw exception(message);
	}
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

string Song::GetInformationAboutSong()
{
	return  _title + " - продолжительность " + to_string( _duration)
		+ " минуты, жанр " + GetGenreForWrite(_genre);
}
