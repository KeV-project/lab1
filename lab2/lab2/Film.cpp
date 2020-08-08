#include "Film.h"

void SetTitle(Film& film, const string& title)
{
	film.Title = title;
}

void SetDuration(Film& film, const int duration)
{
	if (duration <= 0)
	{
		throw exception("����������������� ������"
			"������ ���� ������ 0 �����");
	}
	film.Duration = duration;
}

void SetYear(Film& film, const int year)
{
	if (year <= 0)
	{
		throw exception("��� �� ����� ���� ������ ������ ��� ������ 0");
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
		throw exception("������� �� ����� ���� ������ 0");
	}
	film.Rating = rating;
}

void SetBudget(Film& film, const int budget)
{
	if (budget < 0)
	{
		throw exception("����� �� ����� ���� ������������� ������");
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

//TODO: ��������� +
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
	cout << "������� �������� ������: ";
	string title = "";
	cin >> title;
	cout << endl;
	SetTitle(film, title);
	cout << "������� ����������������� ������(���): ";
	int duration = 0;
	cin >> duration;
	cout << endl;
	SetDuration(film, duration);
	cout << "������� ��� ������� ������: ";
	int year = 0;
	cin >> year;
	cout << endl;
	SetYear(film, year);
	cout << "������� ����:" << endl;
	film.Genre = ReadGenre();
	cout << endl;
	cout << "������� ������� ������: ";
	float rating = 0.0;
	cin >> rating;
	cout << endl;
	SetRating(film, rating);
	cout << "������� ������ �����a: ";
	int budget = 0;
	cin >> budget;
	cout << endl;
	SetBudget(film, budget);
	cout << "������� ��� ���������: ";
	string director = "";
	cin >> director;
	cout << endl;
	SetDirector(film, director);
	cout << "������� ������, ��������� ������� ����: ";
	string mainRole = "";
	cin >> mainRole;
	cout << endl;
	SetMainRole(film, mainRole);
}

void PrintFilm(const Film& film)
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

//TODO: ��������� +
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

//TODO: ��������� +
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
	Film* film2 = MakeFilm("������������", 113, 2019, Thriller, 8.6,
		22000000, "��� ����", "������ ���������, ����� ������");
	delete film2;

	// Task 2.2.9.4
	const int filmsCount = 10;
	Film** films = new Film * [filmsCount]
	{
		MakeFilm("�����", 109, 2011, Thriller,
			7.3, 40000000, "����� ������","������� ����������"),
		MakeFilm("� - �������", 115, 2007, Horror,
			7.9, 150000000, "������� �������","���� ����"),
		MakeFilm("������ ����", 43, 2004, Drama,
			8.8, 4500000, "���� ������", "��� ����"),
		MakeFilm("Focus", 104, 2015, Drama,
			8.2, 50100000, "Glenn Ficarra, John Recua", "Will Smith"),
		MakeFilm("������ ���������", 139, 2010, Thriller,
			8.5, 80000000, "������ ��������", "������ ��������"),
		MakeFilm("������", 108, 2016, Comedy,
			7.5, 58000000, "��� ������", "����� ���������"),
		MakeFilm("����� ����", 120, 2005, Drama,
			8.1, 40000000, "����� �������", "��� �����"),
		MakeFilm("��������", 116, 1994, Drama,
			7.7, 30000000, "Glenn Ficarra, John Recua", "����� ����"),
		MakeFilm("� ��� ������� �������", 92, 2010,
			Comedy, 7.7, 1950000, "������� ��������", 
			"������ �����, ��������� ����,������ �����, ��������� �������"),
		MakeFilm("�����", 112, 2018, Thriller,
			6.8, 100000000, "����� �������", "��� �����"),
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
		cout << PrintGenre(findedGenre) << " � ���������� ���������: ";
		cout << FindBestGenreMovie(films, filmsCount, Thriller)->Title;
		cout << endl << endl;
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
	cout << "�����" << endl << endl;
	ReadFilm(secondFilm);
	PrintFilm(secondFilm);
	PrintLine();
	
	// Task 2.2.3.3
	const int filmsCount = 3;
	Film** films = new Film * [filmsCount]
	{
		MakeFilm("�����", 109, 2011, Thriller, 7.3, 40000000,
			"����� ������", "������� ����������"),
		MakeFilm("� - �������", 115, 2007, Horror, 7.9, 150000000,
			"������� �������", "���� ����"),
		MakeFilm("������ ����", 43, 2004, Drama, 8.8, 4400000,
			"���� ������", "��� ����"),
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
		Thriller, 8.5, 80000000, "������ ��������", "�������� �� ������");
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