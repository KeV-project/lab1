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
	cout << "������� �������� ������: ";
	cin >> film.Title;
	cout << endl;
	cout << "������� ����������������� ������(���): ";
	cin >> film.Duration;
	cout << endl;
	cout << "������� ��� ������� ������: ";
	cin >> film.Year;
	cout << endl;
	int numGenre;
	cout << "������� ���� ������";
	cout << "(0 - �������, 1 - �����, 2 - �������, " << endl;
	cout << "3 - �����, 4 - ����� ������, 5 - ����������): ";
	cin >> numGenre;
	ReadGenre(numGenre, film.Genre);
	cout << endl;
	cout << "������� ������� ������(���. �): ";
	cin >> film.Rating;
	cout << endl;
	cout << "������� ������ �����a(���): ";
	cin >> film.Budget;
	cout << endl;
	cout << "������� ��� ���������: ";
	cin >> film.Director;
	cout << endl;
	cout << "������� ������, ��������� ������� ����: ";
	cin >> film.MainRole;
	cout << endl;
}

void PrintFilm(Film& film)
{
	cout << "��������: " << film.Title << endl;
	cout << "�����������������: " << film.Duration << endl;
	cout << "��� �������: " << film.Year << endl;
	cout << "����: " << PrintGenre(film.Genre) << endl;
	cout << "�������: " << film.Rating << endl;
	cout << "������: " << film.Budget << endl;
	cout << "��������: " << film.Director << endl;
	cout << "� ������� ����: " << film.MainRole << endl << endl;
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

int CountMoviesByGenre(Film** films, int filmsCount, GenreType findedGenre)
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

Film* FindBestGenreMovie(Film** films, int filmsCount, GenreType findGenre)
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
	film.Title = "Focus";
	film.Duration = 104;
	film.Year = 2015;
	film.Genre = Drama;
	film.Rating = 8.2;
	film.Budget = 50.1;
	film.Director = "Glenn Ficarra, John Recua";
	film.MainRole = "Will Smith";

	// Task 2.2.9.3
	Film* film2 = MakeFilm("������������", 113, 2019, Thriller, 8.6, 22,
		"��� ����", "������ ���������, ����� ������");
	delete film2;

	// Task 2.2.9.4
	const int filmsCount = 10;
	Film** films = new Film * [filmsCount]
	{
		MakeFilm("�����", 109, 2011, Thriller,
			7.3, 40, "����� ������","������� ����������"),
		MakeFilm("� - �������", 115, 2007, Horror,
			7.9, 150, "������� �������","���� ����"),
		MakeFilm("������ ����", 43, 2004, Drama,
			8.8, 4.5, "���� ������", "��� ����"),
		MakeFilm("Focus", 104, 2015, Drama,
			8.2, 50.1, "Glenn Ficarra, John Recua", "Will Smith"),
		MakeFilm("������ ���������", 139, 2010, Thriller,
			8.5, 80, "������ ��������", "������ ��������"),
		MakeFilm("������", 108, 2016, Comedy,
			7.5, 58, "��� ������", "����� ���������"),
		MakeFilm("����� ����", 120, 2005, Drama,
			8.1, 40, "����� �������", "��� �����"),
		MakeFilm("��������", 116, 1994, Drama,
			7.7, 30, "Glenn Ficarra, John Recua", "����� ����"),
		MakeFilm("� ��� ������� �������", 92, 2010,
			Comedy, 7.7, 1.95, "������� ��������", 
			"������ �����, ��������� ����, ������ �����, ��������� �������"),
		MakeFilm("�����", 112, 2018, Thriller,
			6.8, 100, "����� �������", "��� �����"),
	};

	cout << "������ �������:" << endl << endl;
	for (int i = 0; i < filmsCount; i++)
	{
		cout << "����� �" << i + 1 << ": " << endl << endl;
		PrintFilm(*films[i]);
	}
	
	GenreType findedGenre = Thriller;
	cout << "�� ������� " << PrintGenre(findedGenre) << " ���� ������� ";
	cout << CountMoviesByGenre(films, filmsCount, Thriller);
	cout << " �����(a/��)" << endl << endl;

	PrintLine();
	
	// Task 2.2.9.5
	if (FindBestGenreMovie(films, filmsCount, findedGenre) != nullptr)
	{
		cout << PrintGenre(findedGenre) << " � ���������� ���������: "
			<< FindBestGenreMovie(films, filmsCount, Thriller)->Title << endl << endl;
	}
	else
	{
		cout << "������ �� �������" << endl << endl;
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
	cout << "�����" << endl << endl;
	ReadFilm(secondFilm);
	PrintFilm(secondFilm);
	PrintLine();
	
	// Task 2.2.3.3
	const int filmsCount = 3;
	Film** films = new Film * [filmsCount]
	{
		MakeFilm("�����", 109, 2011, Thriller, 7.3, 40, "����� ������", "������� ����������"),
		MakeFilm("� - �������", 115, 2007, Horror, 7.9, 150, "������� �������", "���� ����"),
		MakeFilm("������ ����", 43, 2004, Drama, 8.8, 4.4, "���� ������", "��� ����"),
	};
	cout << "������ �������: " << endl << endl;
	for (int i = 0; i < filmsCount; i++)
	{
		cout << "����� �" << i + 1 << ":" << endl << endl;
		PrintFilm(*films[i]);
	}
	PrintLine();
	for (int i = 0; i < filmsCount; i++)
	{
		delete films[i];
	}
	delete[] films;

	// Task 2.2.4.1
	cout << "������ � ���������� �� ���������:" << endl << endl;
	Film* pFirstFilm = &firstFilm;
	cout << "����� firstFilm: " << endl << endl;
	PrintFilm(firstFilm);
	cout << "���������� ����� firstFilm: " << endl << endl;
	ChangeFilm(pFirstFilm, "������ ���������", 139, 2010,
		Thriller, 8.5, 80, "������ ��������", "�������� �� ������");
	PrintFilm(*pFirstFilm);
	PrintLine();

	// Task 2.2.4.2
	Film* pFirstFilm2 = &firstFilm;
	cout << "����� ���������� firstFilm: ";
	cout << &firstFilm << endl << endl;
	cout << "����� � ��������� pFirstFilm: ";
	cout << pFirstFilm << endl << endl;
	cout << "����� � ��������� pFirstFilm2: ";
	cout << pFirstFilm2 << endl << endl;
	PrintLine();

	cout << "������� ������� ������������� �����:" << endl << endl;
	DemoMovieWithGenre();
	PrintLine();
}
