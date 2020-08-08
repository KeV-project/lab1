#include "Film.h"

void SetTitle(Film& film, const string& title)
{
	film.Title = title;
}

void SetDuration(Film& film, const int duration)
{
	if (duration <= 0)
	{
		throw exception("Продолжительность фильма"
			"должна быть больше 0 минут");
	}
	film.Duration = duration;
}

void SetYear(Film& film, const int year)
{
	if (year <= 0)
	{
		throw exception("Год не может быть числом меньше или равным 0");
	}
	film.Year = year;
}

void SetGenre(Film& film, const GenreType& genre)
{
	film.Genre = genre;
}

void SetRating(Film& film, const float rating)
{
	if (rating < 0.0)
	{
		throw exception("Рейтинг не может быть меньше 0");
	}
	film.Rating = rating;
}

void SetBudget(Film& film, const int budget)
{
	if (budget < 0)
	{
		throw exception("Бюдет не может быть отрицательным числом");
	}
	film.Budget = budget;
}

void SetDirector(Film& film, const string& director)
{
	film.Director = director;
}

void SetMainRole(Film& film, const string& mainRole)
{
	film.MainRole = mainRole;
}

//TODO: Сигнатура +
Film* MakeFilm(const string &title, const int duration, const int year,
	const GenreType &genre, const float rating, const int budget,
	const string &director, const string &mainRole)
{
	Film* film = new Film();
	SetTitle(*film, title);
	SetDuration(*film, duration);
	SetYear(*film, year);
	SetGenre(*film, genre);
	SetRating(*film, rating);
	SetBudget(*film, budget);
	SetDirector(*film, director);
	SetMainRole(*film, mainRole);
	return film;
}

Film* CopyFilm(const Film& film)
{
	Film* copiedFilm = new Film();
	copiedFilm->Title = film.Title;
	copiedFilm->Duration = film.Duration;
	copiedFilm->Year = film.Year;
	copiedFilm->Genre = film.Genre;
	copiedFilm->Rating = film.Rating;
	copiedFilm->Budget = film.Budget;
	copiedFilm->Director = film.Director;
	copiedFilm->MainRole = film.MainRole;
	return copiedFilm;
}

void ReadFilm(Film& film)
{
	cout << "Введите название фильма: ";
	string title = "";
	cin >> title;
	cout << endl;
	SetTitle(film, title);
	cout << "Введите продолжительность фильма(мин): ";
	int duration = 0;
	cin >> duration;
	cout << endl;
	SetDuration(film, duration);
	cout << "Введите год выпуска фильмы: ";
	int year = 0;
	cin >> year;
	cout << endl;
	SetYear(film, year);
	cout << "Введите жанр:" << endl;
	film.Genre = ReadGenre();
	cout << endl;
	cout << "Введите рейтинг фильма: ";
	float rating = 0.0;
	cin >> rating;
	cout << endl;
	SetRating(film, rating);
	cout << "Введите бюджет фильмa: ";
	int budget = 0;
	cin >> budget;
	cout << endl;
	SetBudget(film, budget);
	cout << "Введите имя режиссера: ";
	string director = "";
	cin >> director;
	cout << endl;
	SetDirector(film, director);
	cout << "Введите актера, играющего главную роль: ";
	string mainRole = "";
	cin >> mainRole;
	cout << endl;
	SetMainRole(film, mainRole);
}

void PrintFilm(const Film& film)
{
	cout << "Название: " << film.Title << endl;
	cout << "Продолжительность: " << film.Duration << endl;
	cout << "Год выпуска: " << film.Year << endl;
	cout << "Жанр: " << PrintGenre(film.Genre) << endl;
	cout << "Рейтинг: " << film.Rating << endl;
	cout << "Бюджет: " << film.Budget << endl;
	cout << "Режиссер: " << film.Director << endl;
	cout << "В главной роли: " << film.MainRole << endl << endl;
}

//TODO: Сигнатура +
void ChangeFilm(Film* film, const string& title,
	const int duration, const int year, 
	const GenreType& genre, const float rating, 
	const int budget, const string &director, 
	const string& mainRole)
{
	SetTitle(*film, title);
	SetDuration(*film, duration);
	SetYear(*film, year);
	SetGenre(*film, genre);
	SetRating(*film, rating);
	SetBudget(*film, budget);
	SetDirector(*film, director);
	SetMainRole(*film, mainRole);
}

//TODO: Сигнатура +
int CountMoviesByGenre(Film** films, const int filmsCount, const GenreType& findedGenre)
{
	int genreCount = 0;
	for (int i = 0; i < filmsCount; i++)
	{
		if (films[i]->Genre == findedGenre)
		{
			genreCount++;
		}
	}
	return genreCount;
}

Film* FindBestGenreMovie(Film** films, const int filmsCount, const GenreType& findGenre)
{
	float maxRating = 0;
	Film* maxRatingFilm = nullptr;
	for (int i = 0; i < filmsCount; i++)
	{
		if (films[i]->Genre == findGenre)
		{
			if (films[i]->Rating > maxRating)
			{
				maxRating = films[i]->Rating;
				maxRatingFilm = films[i];
			}
		}
	}
	return maxRatingFilm;
}

void DemoMovieWithGenre()
{
	// Task 2.2.9.2
	Film film;
	SetTitle(film, "Focus");
	SetDuration(film, 104);
	SetYear(film, 2015);
	SetGenre(film, Drama);
	SetRating(film, 8.2);
	SetBudget(film, 50100000);
	SetDirector(film, "Glenn Ficarra, John Recua");
	SetMainRole(film, "Will Smith");

	// Task 2.2.9.3
	Film* film2 = MakeFilm("Джентельмены", 113, 2019, Thriller, 8.6,
		22000000, "Гай Ричи", "Мэттью Макконахи, Чарли Ханнэм");
	delete film2;

	// Task 2.2.9.4
	const int filmsCount = 10;
	Film** films = new Film * [filmsCount]
	{
		MakeFilm("Время", 109, 2011, Thriller,
			7.3, 40000000, "Эндрю Никкол","Джастин Тимберлейк"),
		MakeFilm("Я - легенда", 115, 2007, Horror,
			7.9, 150000000, "Фрэнсис Лоуренс","Уилл Смит"),
		MakeFilm("Доктор Хаус", 43, 2004, Drama,
			8.8, 4500000, "Грег Яйтанс", "Хью Лори"),
		MakeFilm("Focus", 104, 2015, Drama,
			8.2, 50100000, "Glenn Ficarra, John Recua", "Will Smith"),
		MakeFilm("Остров проклятых", 139, 2010, Thriller,
			8.5, 80000000, "Мартин Скорсезе", "Мартин Скорсезе"),
		MakeFilm("Дэдпул", 108, 2016, Comedy,
			7.5, 58000000, "Тим Миллер", "Райан Рейнольдс"),
		MakeFilm("Белый плен", 120, 2005, Drama,
			8.1, 40000000, "Фрэнк Маршалл", "Пол Уокер"),
		MakeFilm("Скорость", 116, 1994, Drama,
			7.7, 30000000, "Glenn Ficarra, John Recua", "Киану Ривз"),
		MakeFilm("О чем говорят мужчины", 92, 2010,
			Comedy, 7.7, 1950000, "Дмитрий Дьяченко", 
			"Леонид Барац, Ростислав Хаит,Камиль Ларин, Александр Демидов"),
		MakeFilm("Веном", 112, 2018, Thriller,
			6.8, 100000000, "Рубен Флейшер", "Том Харди"),
	};

	cout << "Массив фильмов:" << endl << endl;
	for (int i = 0; i < filmsCount; i++)
	{
		cout << "Фильм №" << i + 1 << ": " << endl << endl;
		PrintFilm(*films[i]);
	}
	
	GenreType findedGenre = Thriller;
	cout << "По запросу " << PrintGenre(findedGenre) << " было найдено ";
	cout << CountMoviesByGenre(films, filmsCount, Thriller);
	cout << " фильм(a/ов)" << endl << endl;

	PrintLine();
	
	// Task 2.2.9.5
	if (FindBestGenreMovie(films, filmsCount, findedGenre) != nullptr)
	{
		cout << PrintGenre(findedGenre) << " с наибольшим рейтингом: ";
		cout << FindBestGenreMovie(films, filmsCount, Thriller)->Title;
		cout << endl << endl;
	}
	else
	{
		cout << "Ничего не найдено" << endl << endl;
	}

	for (int i = 0; i < filmsCount; i++)
	{
		delete films[i];
	}
	delete[] films;
}

void DemoFilm()
{
	// Task 2.2.3.1
	Film firstFilm;
	SetTitle(firstFilm, "Focus");
	SetDuration(firstFilm, 104);
	SetYear(firstFilm, 2015);
	SetGenre(firstFilm, Drama);
	SetRating(firstFilm, 8.2);
	SetBudget(firstFilm, 50100000);
	SetDirector(firstFilm, "Glenn Ficarra, John Recua");
	SetMainRole(firstFilm, "Will Smith");

	// Task 2.2.3.2
	Film secondFilm;
	cout << "ФИЛЬМ" << endl << endl;
	ReadFilm(secondFilm);
	PrintFilm(secondFilm);
	PrintLine();
	
	// Task 2.2.3.3
	const int filmsCount = 3;
	Film** films = new Film * [filmsCount]
	{
		MakeFilm("Время", 109, 2011, Thriller, 7.3, 40000000,
			"Эндрю Никкол", "Джастин Тимберлейк"),
		MakeFilm("Я - легенда", 115, 2007, Horror, 7.9, 150000000,
			"Фрэнсис Лоуренс", "Уилл Смит"),
		MakeFilm("Доктор Хаус", 43, 2004, Drama, 8.8, 4400000,
			"Грег Яйтанс", "Хью Лори"),
	};
	cout << "Массив фильмов: " << endl << endl;
	for (int i = 0; i < filmsCount; i++)
	{
		cout << "Фильм №" << i + 1 << ":" << endl << endl;
		PrintFilm(*films[i]);
	}
	PrintLine();
	for (int i = 0; i < filmsCount; i++)
	{
		delete films[i];
	}
	delete[] films;

	// Task 2.2.4.1
	cout << "Работа с указателем на структуру:" << endl << endl;
	Film* pFirstFilm = &firstFilm;
	cout << "Фильм firstFilm: " << endl << endl;
	PrintFilm(firstFilm);
	cout << "Измененный фильм firstFilm: " << endl << endl;
	ChangeFilm(pFirstFilm, "Остров Проклятых", 139, 2010,
		Thriller, 8.5, 80000000, "Мартин Скорсезе", "Леонардо Ди Каприо");
	PrintFilm(*pFirstFilm);
	PrintLine();

	// Task 2.2.4.2
	Film* pFirstFilm2 = &firstFilm;
	cout << "Адрес переменной firstFilm: ";
	cout << &firstFilm << endl << endl;
	cout << "Адрес в указателе pFirstFilm: ";
	cout << pFirstFilm << endl << endl;
	cout << "Адрес в указателе pFirstFilm2: ";
	cout << pFirstFilm2 << endl << endl;
	PrintLine();

	cout << "Подсчет фильмов определенного жанра:" << endl << endl;
	DemoMovieWithGenre();
	PrintLine();
}