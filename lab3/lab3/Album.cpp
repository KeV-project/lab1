#include "Album.h"

void Album::SetName(const string& name)
{
	this->_name = name;
}

void Album::SetYear(const int year)
{
	if (year < 0 || year > 2020)
	{
		string message = "����� " + to_string(year) +
			" �� ������ � ���������� �������� �������� [0, 2020]\n"
			"� �� ����� ���������� ��� ������� �����";
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
		string message = "������������� ����� " + to_string(songsCount)
			+ " �� ����� �������� ���������� ����� � �������";
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
