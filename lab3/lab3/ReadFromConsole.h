#pragma once
#include <iostream>
#include "Book.h"

using namespace std;

Book* ReadBook();
Book** ReadBooks(const int booksCount);