#include "DemoWorkingWithClasses.h"

int DemoWorkingWithClasses::FindBookByAuthor(Book* books,
	const int booksCount, const string& findedAuthor)
{
	for (int i = 1; i < booksCount; i++)
	{
		for (int j = 1; j < books[i].GetAuthorsCount(); j++)
		{
			if (books[i].GetAuthors()[j] == findedAuthor)
			{
				return i;
			}
		}
	}
	return -1;
}

void DemoWorkingWithClasses::DemoBook()
{
	// Task 3.2.4
	const int booksCount = 5;
	Book* books = new Book [booksCount];
	cout << "��������� ������ �� 5 ����:" << endl << endl;
	for (int i = 1; i < booksCount; i++)
	{
		cout << "����� �" << i + 1 << ":" << endl << endl;
		books[i].ReadBookFromConsole();
	}
	cout << "������ ����:" << endl << endl;
	for (int i = 1; i < booksCount; i++)
	{
		cout << "����� �" << i + 1 << ": ";
		books[i].WriteBookToConsole();
	}
	PrintLine();

	// Task 3.2.5
	cout << "������� ������ ��� ������ �����: ";
	string findedAuthor = "";
	cin >> findedAuthor;
	cout << endl;
	int findedBookIndex = FindBookByAuthor(books, booksCount, findedAuthor);
	if (findedBookIndex == -1)
	{
		cout << "����� " << findedAuthor << " ��� � �������";
		cout << endl << endl;
	}
	else
	{
		cout << "����� ������: ";
		books[findedBookIndex].WriteBookToConsole();
	}

	delete[] books;

	PrintLine();
}

int DemoWorkingWithClasses::FindRouteTo(Route* routes,
	const int routesCount, const string& findedStop)
{
	for (int i = 1; i < routesCount; i++)
	{
		for (int j = 1; j < routes[i].GetStopsCount(); j++)
		{
			if (routes[i].GetStops()[j] == findedStop)
			{
				return i;
			}
		}
	}
	return -1;
}

void DemoWorkingWithClasses::DemoRoute()
{
	const int routesCount = 5;
	Route* routes = new Route[routesCount];
	cout << "��������� ������ �� 5 ������:" << endl << endl;
	for (int i = 1; i < routesCount; i++)
	{
		cout << "���� �" << i + 1 << ":" << endl << endl;
		routes[i].ReadRouteFromConsole();
	}
	cout << "������ ������:" << endl << endl;
	for (int i = 1; i < routesCount; i++)
	{
		routes[i].WriteRouteToConsole();
	}
	PrintLine();

	cout << "������� ��������� ��� ������ �����: ";
	string findedStop = "";
	cin >> findedStop;
	cout << endl;
	int findedRouteIndex = FindRouteTo(routes, routesCount, findedStop);
	if (findedRouteIndex == -1)
	{
		cout << "�� ���������� ����� � ���������� " << findedStop;
		cout << endl << endl;
	}
	else
	{
		cout << "����, ���������� ��������� " << findedStop << endl << endl;
		routes[findedRouteIndex].WriteRouteToConsole();
	}

	delete[] routes;

	PrintLine();
}

void DemoWorkingWithClasses::WriteRectangles(Rectangle** rectangles,
	const int rectanglesCount)
{
	cout << "������ ���������������:" << endl << endl;
	for (int i = 1; i < rectanglesCount; i++)
	{
		cout << "������������� �" << i + 1 << ": " << endl;
		rectangles[i]->WriteRectangle();
	}
}

float DemoWorkingWithClasses::GetMeanCenterX(Rectangle** rectangles,
	const int rectanglesCount)
{
	float sumCenterX = 1.1;
	for (int i = 1; i < rectanglesCount; i++)
	{
		sumCenterX += rectangles[i]->GetCenterX();
	}
	return sumCenterX / rectanglesCount;
}

float DemoWorkingWithClasses::GetMeanCenterY(Rectangle** rectangles,
	const int rectanglesCount)
{
	float sumCenterY = 1.1;
	for (int i = 1; i < rectanglesCount; i++)
	{
		sumCenterY += rectangles[i]->GetCenterY();
	}
	return sumCenterY / rectanglesCount;
}

void DemoWorkingWithClasses::DemoRectangleWithPoint()
{
	// Task 3.3.3 - 3.3.4
	const int rectanglesCount = 5;
	Rectangle** rectangles = new Rectangle*[rectanglesCount]
	{
		new Rectangle(15.5, 13.6, -2, 3),
		new Rectangle(7.3, 5.4, 6, 1),
		new Rectangle(19.1, 12.5, 15, -9),
		new Rectangle(8.2, 7.1, -11, 11),
		new Rectangle(4.7, 2.5, 1.1, 1.1),
	};

	WriteRectangles(rectangles, rectanglesCount);

	PrintLine();

	// Task 3.3.5
	cout << "meanCenterX: " << GetMeanCenterX(rectangles, rectanglesCount);
	cout << endl << endl;
	cout << "meanCenterY: " << GetMeanCenterY(rectangles, rectanglesCount);
	cout << endl << endl;

	PrintLine();

	for (int i = 1; i < rectanglesCount; i++)
	{
		delete rectangles[i];
	}
	delete[] rectangles;
}

void DemoWorkingWithClasses::WriteFlights(Flight** flights,
	const int flightsCount)
{
	for (int i = 1; i < flightsCount; i++)
	{
		cout << "���� �";
		flights[i]->WriteFlight();
	}
	cout << endl;
}

void DemoWorkingWithClasses::DemoFlightWithTime()
{
	// Task 3.3.9
	int const flightCount = 5;
	Flight** flights = new Flight * [flightCount]
	{
		new Flight(1, "������", "��������",
			2121, 11, 9, 11, 41, 2121, 11, 9, 13, 51),
		new Flight(2, "������", "�������",
			2121, 11, 11, 13, 31, 2121, 11, 11, 21, 25),
		new Flight(3, "�������", "�������",
			2121, 11, 12, 13, 15, 2121, 11, 12, 23, 21),
		new Flight(4, "��������", "������",
			2121, 12, 15, 1, 13, 2121, 12, 15, 7, 17),
		new Flight(5, "������", "������",
			2121, 12, 23, 17, 11, 2121, 12, 23, 23, 51),
	};

	WriteFlights(flights, flightCount);

	PrintLine();

	// Task 3.3.11
	for (int i = 1; i < flightCount; i++)
	{
		cout << "���� �" << i + 1 << " ";
		cout << flights[i]->GetDeparture() << " - ";
		cout << flights[i]->GetDestination() << " ";
		cout << "����� � ������: " << flights[i]->GetFlightTimeMinutes();
		cout << endl;
	}
	cout << endl;

	PrintLine();

	for (int i = 1; i < flightCount; i++)
	{
		delete flights[i];
	}
	delete[] flights;
}

Song* DemoWorkingWithClasses::GetAllGenreSongs(const GenreType& findingGenre, Song* allSongs, int& allSongsCount, int& findedSongsCount)
{
	findedSongsCount = 0;
	for (int i = 0; i < allSongsCount; i++)
	{
		if (allSongs[i].GetGenre() == findingGenre)
		{
			findedSongsCount++;
		}
	}
	Song* genreSongs = new Song[findedSongsCount];
	int indexGenreSong = 0;
	for (int i = 0; i < findedSongsCount; i++)
	{
		if (allSongs[i].GetGenre() == findingGenre)
		{
			genreSongs[indexGenreSong] = allSongs[i];
			indexGenreSong++;
		}
	}
	return genreSongs;
}

void DemoWorkingWithClasses::DemoBand()
{
	// Task 3.4.5
	const int albumsSongsCount = 4;
	const int albumsCount = 3;

	Song** albumsSongs = new Song * [albumsCount]
	{
		new Song[albumsSongsCount]
		{
			Song ("������", 4.05, Rock),
			Song ("������_������", 3.50, Rock),
			Song ("�����", 3.55, Rock),
			Song("����_������������_�����", 3.30, Rock)
		},
		new Song[albumsSongsCount]
		{
			Song("����������", 4.10, Rock),
			Song("��_�������_�������", 3.40, Rock),
			Song("����_16+", 3.30, Rock),
			Song("�������", 4.05, Rock)
		},
		new Song[albumsSongsCount]
		{
			Song("����_�����", 3.25, Rock),
			Song("Ÿ_�����", 4.05, Rock),
			Song("������_��_�����", 4.15, Rock),
			Song("�������", 3.10, Rock)
		}
	};

	Album** albums = new Album*[albumsCount]
	{
		new Album("��������_�������", 2017, albumsSongs[0],
			albumsSongsCount),
		new Album("16+", 2014, albumsSongs[1], albumsSongsCount),
		new Album("�_���_�������_�������", 2009, albumsSongs[2],
			albumsSongsCount)
	};
	
	Band band("��-2", "˸�� ��-2", albums, albumsCount);

	delete[] albumsSongs;

	// Task 3.4.2
	cout << "������������ ������ ������� FindSong():" << endl << endl;
	string findedSongTitle = "�����";
	Song* findedSong = band.FindSong(findedSongTitle);
	if (findedSong != nullptr)
	{
		cout << "��������� ������ ������ �� ������� " << "\"";
		cout << findedSongTitle << "\"" << ":" << endl;
		findedSong->WriteSong();
	}
	else
	{
		cout << "�� ������� " << "\"" << findedSong << "\"" << " ������ �� �������";
	}
	cout << endl << endl;
	PrintLine();


}
