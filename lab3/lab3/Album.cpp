#include "Album.h"

void Album::SetName(const string& name)
{
	this->_name = name;
}

void Album::SetYear(const int year)
{
	//TODO: дубль +
	//TODO: Сообщение о диапазоне значений лучше формировать с помощью заданных заранее значений лимитов
	//TODO: т.е. границы вынести в константы и в сообщение подставить эти константы +
	int const minLimit = 0;
	int const maxLimit = 2020;
	if (!IsValueInRange(year, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(year, minLimit,
			maxLimit, "год издания книги").c_str());
		throw exception(message);
	}
	this->_year = year;
}

void Album::SetSongs(Song* songs, const int songsCount)
{
	int const minLimit = 0;
	int const maxLimit = 10;
	if (!IsValueInRange(songsCount, minLimit, maxLimit))
	{
		char message[255];
		strcpy_s(message, MakeMessage(songsCount, minLimit,
			maxLimit, "количество песен в альбоме").c_str());
		throw exception(message);
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

string Album::GetInformationAboutSong()
{
	return _name + " - год выпуска " + to_string(_year) 
		+ ", количество песен " + to_string(_songsCount); 
}
