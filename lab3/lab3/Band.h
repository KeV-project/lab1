#pragma once
#include <iostream>
#include <string>
#include "GenreType.h"
#include "Song.h"
#include "Album.h"
using namespace std;

class Band
{
private:
	string _name;
	string _solist;
	int _albumsCount;
	Album** _albums;

public:
	void SetName(const string& name);
	void SetSolist(const string& solist);
	void SetAlbums(Album** albums, const int albumsCount);

	string GetName();
	string GetSolist();
	int GetAlbumsCount();
	Album** GetAlbums();

	Band();
	Band(const string& name, const string& solist, 
		Album** albums, const int albumsCount);

	~Band();
	
	Song* FindSong(const string& songTitle);
	Album* FindAlbum(Song& findedSong);
	Song* GetAllSongs(int& allSongsCount);
};

