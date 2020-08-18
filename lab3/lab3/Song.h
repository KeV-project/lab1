#pragma once
#include <string>
#include "GenreType.h"

using namespace std;

class Song
{
private:
	string _title;
	int _duration;
	GenreType _genre;

public:
	void SetTitle(const string& title);
	void SetDuration(const int duration);
	void SetGenre(const GenreType& genre);
	void SetSong(const string& title, const int duration, const GenreType& genre);

	string GetTitle();
	float GetDuration();
	GenreType GetGenre();

	Song();
	Song(const string& title, const int duration, const GenreType& genre);

	void WriteSong();
};