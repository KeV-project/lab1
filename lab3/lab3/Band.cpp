#include "Band.h"

void Band::SetName(const string& name)
{
	this->_name = name;
}

void Band::SetSolist(const string& solist)
{
	this->_solist = solist;
}

void Band::SetAlbums(Album* albums, const int albumsCount)
{
	if (albumsCount < 0)
	{
		string message = "Отрицательное число " + to_string(albumsCount)
			+ " не может задавать количество альбомов группы";
		char buf[255];
		strcpy_s(buf, message.c_str());
		throw exception(buf);
	}
	this->_albumsCount = albumsCount;
	this->_albums = albums;
}

string Band::GetName()
{
	return _name;
}

string Band::GetSolist()
{
	return _solist;
}

int Band::GetAlbumsCount()
{
	return _albumsCount;
}

Album* Band::GetAlbums()
{
	return _albums;
}

Band::Band()
{
	SetName("");
	SetSolist("");
	SetAlbums(nullptr, 0);
}

Band::Band(const string& name, const string& solist,
	Album* albums, const int albumsCount)
{
	SetName(name);
	SetSolist(solist);
	SetAlbums(albums, albumsCount);
}
