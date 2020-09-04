#pragma once
#include <iostream>
#include "Book.h"
#include "Route.h"
#include "Song.h"
#include "Album.h"
#include "Band.h"

using namespace std;

void PrintLine();

void PrintBook(Book* book);
void PrintBooks(Book** books, const int booksCount);

void PrintRoute(Route* route);
void PrintRoutes(Route** routes, const int routesCount);

void PrintInfoAboutSong(Song& song);
void PrintAllSongs(Song* songs, const int songsCount);
void PrintInfoAboutAlbum(Album *album);
void PrintInfoAboutBand(Band &band);
