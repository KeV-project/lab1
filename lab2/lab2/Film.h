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
	//TODO: �� ������ �����������, ����� ������������� ���������� � BudgetInMillions, ���� ������� ���� � ��������� - ��� �� ���������
	// ������ ������ � ���������
	float Budget;
	string Director;
	string MainRole;
};

Film* MakeFilm(const string& title, const int duration, const int year,
	const GenreType& genre, const float rating, const float budget,
	const string& director, const string& mainRole);
Film* CopyFilm(const Film& film);
void ReadFilm(Film& film);
void PrintFilm(const Film& film);
void ChangeFilm(Film* film, string title, int duration,
	int year, GenreType genre, float rating, float budget,
	string director, string mainRole);
int CountMoviesByGenre(Film** films, int filmsCount, GenreType findedGenre);
Film* FindBestGenreMovie(Film** films, int filmsCount, GenreType findGenre);
void DemoMovieWithGenre();
void DemoFilm();