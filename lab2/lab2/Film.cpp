#include "Film.h"

Film* MakeFilm(string title, int duration, int year, GenreType genre,
	float rating, float budget, string director, string mainRole)
{
	Film* film = new Film();
	film->Title = title;
	film->Duration = duration;
	film->Year = year;
	film->Genre = genre;
	film->Rating = rating;
	film->Budget = budget;
	film->Director = director;
	film->MainRole = mainRole;
	return film;
}

Film* CopyFilm(Film& film)
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
	cout << "Введите название фильмы: ";
	cin >> film.Title;
	cout << endl;
	cout << "Введите продолжительность фильма(мин): ";
	cin >> film.Duration;
	cout << endl;
	cout << "Введите год выпуска фильмы: ";
	cin >> film.Year;
	cout << endl;
	int numGenre;
	cout << "Введите жанр фильма";
	cout << "(0 - Комедия, 1 - Драма, 2 - Триллер, " << endl;
	cout << "3 - Экшен, 4 - Фильм ужасов, 5 - Блокбастер): ";
	cin >> numGenre;
	ReadGenre(numGenre, film.Genre);
	cout << endl;
	cout << "Введите рейтинг фильма(вещ. ч): ";
	cin >> film.Rating;
	cout << endl;
	cout << "Введите бюджет фильмa(млн): ";
	cin >> film.Budget;
	cout << endl;
	cout << "Введите имя режиссера: ";
	cin >> film.Director;
	cout << endl;
	cout << "Введите актера, играющего главную роль: ";
	cin >> film.MainRole;
	cout << endl;
}

void PrintFilm(Film& film)
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

void ChangeFilm(Film* film, string title, int duration,
	int year, GenreType genre, float rating, float budget,
	string director, string mainRole)
{
	film->Title = title;
	film->Duration = duration;
	film->Year = year;
	film->Genre = genre;
	film->Rating = rating;
	film->Budget = budget;
	film->Director = director;
	film->MainRole = mainRole;
}

void DemoFilm()
{
	// Task 2.2.3.1
	Film firstFilm;
	firstFilm.Title = "Focus";
	firstFilm.Duration = 104;
	firstFilm.Year = 2015;
	firstFilm.Genre = Drama;
	firstFilm.Rating = 8.2;
	firstFilm.Budget = 50.1;
	firstFilm.Director = "Glenn Ficarra, John Recua";
	firstFilm.MainRole = "Will Smith";

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
		MakeFilm("Время", 109, 2011, Thriller, 7.3, 40, "Эндрю Никкол", "Джастин Тимберлейк"),
		MakeFilm("Я - легенда", 115, 2007, Horror, 7.9, 150, "Фрэнсис Лоуренс", "Уилл Смит"),
		MakeFilm("Доктор Хаус", 43, 2004, Drama, 8.8, 4.4, "Грег Яйтанс", "Хью Лори"),
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
		Thriller, 8.5, 80, "Мартин Скорсезе", "Леонардо Ди Каприо");
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
}
