#include "Band.h"

void Band::SetName(const string& name)
{
	this->_name = name;
}

void Band::SetSolist(const string& solist)
{
	this->_solist = solist;
}

void Band::SetAlbums(Album** albums, const int albumsCount)
{
	int const minAlbumsCount = 0;
	int const maxAlbumsCount = 10;
	AssertValueInRange(albumsCount, minAlbumsCount,
		maxAlbumsCount, NotInRange, "количество альбомов группы");
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

Album** Band::GetAlbums()
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
	Album** albums, const int albumsCount)
{
	SetName(name);
	SetSolist(solist);
	SetAlbums(albums, albumsCount);
}

Band::~Band()
{
	for (int i = 0; i < _albumsCount; i++)
	{
		delete _albums[i];
	}
	delete[] _albums;
}

int Band::CountAllSongs()
{
	int allSongsCount = 0;
	for (int i = 0; i < _albumsCount; i++)
	{
		allSongsCount += _albums[i]->GetSongsCount();
	}
	return allSongsCount;
}

Song* Band::FindSong(const string& songTitle)
{
	for (int i = 0; i < _albumsCount; i++)
	{
		for (int j = 0; j < _albums[i]->GetSongsCount(); j++)
		{
			if (_albums[i]->GetSongs()[j].GetTitle() == songTitle)
			{
				return &_albums[i]->GetSongs()[j];
			}
		}
	}
	return nullptr;
}

Album* Band::FindAlbum(Song* findedSong)
{
	for (int i = 0; i < _albumsCount; i++)
	{
		for (int j = 0; j < _albums[i]->GetSongsCount(); j++)
		{
			if (_albums[i]->GetSongs()[j].GetTitle() == findedSong->GetTitle() 
				&& _albums[i]->GetSongs()[j].GetDuration() == findedSong->GetDuration()
				&& _albums[i]->GetSongs()[j].GetGenre() == findedSong->GetGenre())
			{
				return _albums[i];
			}
		}
	}
	return nullptr;
}

Song* Band::GetAllSongs(int& allSongsCount)
{
	allSongsCount = CountAllSongs();
	Song* songs = new Song[allSongsCount];
	int indexSongs = 0;
	for (int i = 0; i < _albumsCount; i++)
	{
		for (int j = 0; j < _albums[i]->GetSongsCount(); j++)
		{
			songs[indexSongs] = _albums[i]->GetSongs()[j];
			indexSongs++;
		}
	}
	return songs;
}

int Band::GetAllGenreSongsCount(const GenreType& findedGenre)
{
	int findedGenreSongsCount = 0;
	for (int i = 0; i < _albumsCount; i++)
	{
		for (int j = 0; j < _albums[i]->GetSongsCount(); j++)
		{
			if (_albums[i]->GetSongs()[j].GetGenre() == findedGenre)
			{
				findedGenreSongsCount++;
			}
		}
	}
	return findedGenreSongsCount;
}

Song* Band::GetAllGenreSongs(const GenreType& findedGenre,
	const int findedGenreSongsCount)
{
	if (findedGenreSongsCount != 0)
	{
		int genreSongsIndex = 0;
		Song* genreSongs = new Song[findedGenreSongsCount];
		for (int i = 0; i < this->_albumsCount; i++)
		{
			for (int j = 0; j < this->_albums[i]->GetSongsCount(); j++)
			{
				if (_albums[i]->GetSongs()[j].GetGenre() == findedGenre)
				{
					genreSongs[genreSongsIndex] = _albums[i]->GetSongs()[j];
					genreSongsIndex++;
				}
			}
		}
		return genreSongs;
	}
	else
	{
		return nullptr;
	}
}

