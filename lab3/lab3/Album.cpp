#include "Album.h"

void Album::SetName(const string& name)
{
	this->_name = name;
}

void Album::SetYear(const int year)
{
	if (year < 0 || year > 2020)
	{
		string message = "Число " + to_string(year) +
			" не входит в допустимый диапазон значений [0, 2020]\n"
			"и не может определять год издания книги";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_year = year;
}

void Album::SetSongs(Song* songs, const int songsCount)
{
	if (songsCount < 0)
	{
		string message = "Отрицательное число " + to_string(songsCount)
			+ " не может задавать количество песен в альбоме";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_songsCount = songsCount;
	this->_songs = songs;
}

string Album::GetName()
{
	return _name;
}

int Album::GetYear()
{
	return _year;
}

int Album::GetSongsCount()
{
	return _songsCount;
}

Song* Album::GetSongs()
{
	return _songs;
}

Album::Album()
{
	SetName("");
	SetYear(2020);
	SetSongs(nullptr, 0);
}

Album::Album(const string& name, const int year, Song* songs, const int songsCount)
{
	SetName(name);
	SetYear(year);
	SetSongs(songs, songsCount);
}

Album::~Album()
{
	delete[] _songs;
}
