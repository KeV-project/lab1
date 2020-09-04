#include "Song.h"

void Song::SetTitle(const string& title)
{
	this->_title = title;
}

void Song::SetDuration(const int duration)
{
	//TODO: Дубль
	if (duration < 0)
	{
		string message = "ИСКЛЮЧЕНИЕ: Отрицательное число " 
			+ to_string(duration) + "\nне может определять "
			+"продолжительность песни";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
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
