#include "Album.h"

void Album::SetName(const string& name)
{
	this->_name = name;
}

void Album::SetYear(const int year)
{
	//TODO: Может быть 0?
	int const minYear = 0;
	int const maxYear = 2020;
	AssertValueInRange(year, minYear,
		maxYear, NotInRange, "год издания книги");
	this->_year = year;
}

void Album::SetSongs(Song* songs, const int songsCount)
{
	//TODO: Может быть 0?
	int const minSongsCount = 0;
	int const maxSongsCount = 10;
	AssertValueInRange(songsCount, minSongsCount,
		maxSongsCount, NotInRange, "количество песен в альбоме");
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

Album::Album(const string& name, const int year,
	Song* songs, const int songsCount)
{
	SetName(name);
	SetYear(year);
	SetSongs(songs, songsCount);
}

Album::~Album()
{
	delete[] _songs;
}
