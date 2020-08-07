#pragma once

#include <iostream>
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
	// Ѕюджет фильма в миллионах
	float Budget;
	string Director;
	string MainRole;
};

Film* MakeFilm(string title, int duration, int year, GenreType genre,
	float rating, float budget, string director, string mainRole);
Film* CopyFilm(Film& film);
void ReadFilm(Film& film);
void PrintFilm(Film& film);
void ChangeFilm(Film* film, string title, int duration,
	int year, GenreType genre, float rating, float budget,
	string director, string mainRole);
int CountMoviesByGenre(Film** films, int filmsCount, GenreType findedGenre);
Film* FindBestGenreMovie(Film** films, int filmsCount, GenreType findGenre);
void DemoMovieWithGenre();
void DemoFilm();