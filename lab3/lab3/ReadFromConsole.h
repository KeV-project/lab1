#pragma once
#include <iostream>
#include "Book.h"
#include "Route.h"

using namespace std;

Book* ReadBook();
Book** ReadBooks(const int booksCount);

Route* ReadRoute();
Route** ReadRoutes(const int routesCount);