#pragma once

#include <iostream>
#include "Input.h"
#include "Output.h"
#include "GenreType.h"

using namespace std;

struct Film
{
	string Title;
	int Duration;
	int Year;
	GenreType Genre;
	float Rating;
	int Budget;
	string Director;
	string MainRole;
};

void SetTitle(Film& film, const string& title);
void SetDuration(Film& film, const int duration);
void SetYear(Film& film, const int year);
void SetGenre(Film& film, const GenreType& genre);
void SetRating(Film& film, const float rating);
void SetBudget(Film& film, const int budget);
void SetDirector(Film& film, const string& director);
void SetMainRole(Film& film, const string& mainRole);

Film* MakeFilm(const string& title, const int duration, const int year,
	const GenreType& genre, const float rating, const int budget,
	const string& director, const string& mainRole);
Film* CopyFilm(const Film& film);
void ReadFilm(Film& film);
void PrintFilm(const Film& film);
void ChangeFilm(Film* film, const string& title,
	const int duration, const int year,
	const GenreType& genre, const float rating,
	const int budget, const string& director,
	const string& mainRole);
int CountMoviesByGenre(Film** films, const int filmsCount,
	const GenreType& findedGenre);
Film* FindBestGenreMovie(Film** films, const int filmsCount,
	const GenreType& findGenre);
void DemoMovieWithGenre();
void DemoFilm();