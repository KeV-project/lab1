#include "Film.h"

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
	cout << "������� ������ ������(���): ";
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

void DemoFilm()
{
	// Task 2.2.3.1
	Film firstFilm;
	firstFilm.Title = "Focus";
	firstFilm.Duration = 104;
	firstFilm.Year = 2015;
	//firstFilm.Genre = Drama;
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
}
