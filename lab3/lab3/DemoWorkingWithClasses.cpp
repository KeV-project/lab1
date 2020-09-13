#include "DemoWorkingWithClasses.h"

void DemoWorkingWithClasses::DemoBook()
{
	// Task 3.2.4
	const int booksCount = 2;
	cout << "��������� ������ �� " << booksCount << " ����:";
	cout << endl << endl;
	Book** books = ReadBooks(booksCount);
	cout << "������ ����:" << endl << endl;
	PrintBooks(books, booksCount);
	PrintLine();

	// Task 3.2.5
	cout << "������� ������ ��� ������ �����: ";
	cin.ignore(cin.rdbuf()->in_avail());
	string findedAuthor = "";
	getline(cin, findedAuthor, '\n');
	cin.clear();
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
		PrintBook(books[findedBookIndex]);
	}

	for (int i = 0; i < booksCount; i++)
	{
		delete books[i];
	}
	delete[] books;

	PrintLine();
}

void DemoWorkingWithClasses::DemoRoute()
{
	const int routesCount = 2;
	cout << "��������� ������ �� " << routesCount << " ������:";
	cout << endl << endl;
	Route** routes = ReadRoutes(routesCount);
	cout << "������ ������:" << endl << endl;
	PrintRoutes(routes, routesCount);
	PrintLine();

	cout << "������� ��������� ��� ������ �����: ";
	cin.ignore(cin.rdbuf()->in_avail());
	string findedStop = "";
	getline(cin, findedStop, '\n');
	cin.clear();
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
		PrintRoute(routes[findedRouteIndex]);
	}

	for (int i = 0; i < routesCount; i++)
	{
		delete routes[i];
	}
	delete[] routes;

	PrintLine();
}

void DemoWorkingWithClasses::DemoRectangleWithPoint()
{
	// Task 3.3.3 - 3.3.4
	const int rectanglesCount = 5;
	Rect** rectangles = new Rect*[rectanglesCount]
	{
		new Rect(15.555, 13.6, -2, 3),
		new Rect(7.3, 5.4, 6, 1),
		new Rect(19.1, 12.5, 15, -9),
		new Rect(8.2, 7.1, -11, 11),
		new Rect(4.7, 2.5, 1.1, 1.1),
	};

	PrintRectangles(rectangles, rectanglesCount);
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

void DemoWorkingWithClasses::DemoFlightWithTime()
{
	// Task 3.3.9
	int const flightCount = 5;
	Flight** flights = new Flight * [flightCount]
	{
		new Flight(1, "������", "��������",
			2020, 11, 9, 13, 50, 2020, 11, 9, 13, 51),
		new Flight(2, "������", "�������",
				2020, 11, 11, 13, 31, 2020, 11, 11, 21, 25),
		new Flight(3, "�������", "�������",
				2020, 11, 12, 13, 15, 2020, 11, 12, 23, 21),
		new Flight(4, "��������", "������",
				2020, 12, 15, 1, 13, 2020, 12, 15, 7, 17),
		new Flight(5, "������", "������",
				2020, 12, 23, 17, 11, 2020, 12, 23, 23, 51),
	};
	
	PrintFlights(flights, flightCount);
	PrintLine();

	//Task 3.3.11
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
			Song ("������ ������", 3.50, Rock),
			Song ("�����", 3.55, Rock),
			Song("���� ������������ �����", 3.30, Rock)
		},
		new Song[albumsSongsCount]
		{
			Song("����������", 4.10, Rock),
			Song("�� ������� �������", 3.40, Rock),
			Song("���� 16+", 3.30, Rock),
			Song("�������", 4.05, Rock)
		},
		new Song[albumsSongsCount]
		{
			Song("���� �����", 3.25, Rock),
			Song("Ÿ �����", 4.05, Rock),
			Song("������ �� �����", 4.15, Rock),
			Song("�������", 3.10, Rock)
		}
	};

	Album** albums = new Album*[albumsCount]
	{
		new Album("�������� �������", 2017, albumsSongs[0],
			albumsSongsCount),
		new Album("16+", 2014, albumsSongs[1], albumsSongsCount),
		new Album("� ��� ������� �������", 2009, albumsSongs[2],
			albumsSongsCount)
	};
	
	Band band("��-2", "˸�� ��-2", albums, albumsCount);

	delete[] albumsSongs;

	PrintInfoAboutBand(band);
	PrintLine();

	// Task 3.4.2
	cout << "������������ ������ ������� FindSong():" << endl << endl;
	cout << "������� �������� ������� �����: ";
	string findedSongTitle = "";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, findedSongTitle, '\n');
	cin.clear();
	cout << endl;
	Song* findedSong = band.FindSong(findedSongTitle);
	if (findedSong != nullptr)
	{
		cout << "��������� ������ ������ �� ������� " << "\"";
		cout << findedSongTitle << "\"" << ":" << endl;
		PrintInfoAboutSong(*findedSong);
		cout << endl << endl;

		// Task 3.4.3
		cout << "������������ ������ ������� FindAlbum():" << endl << endl;
		Album* findedAlbum = band.FindAlbum(findedSong);
		cout << "����� " << "\"" << findedSongTitle << "\"" << " ";
		cout << "��������� � �������:" << endl;
		PrintInfoAboutAlbum(findedAlbum);
	}
	else
	{
		cout << "�� ������� " << "\"" << findedSongTitle << "\"";
		cout << " ������ �� �������";
	}
	cout << endl << endl;
	PrintLine();
	
	// Task 3.4.4
	int allSongsCount = 0;
	Song* allSongs = band.GetAllSongs(allSongsCount);
	cout << "��� ����� ������ \"" << band.GetName() << "\":" << endl << endl;
	PrintAllSongs(allSongs, allSongsCount);
	PrintLine();

	delete[] allSongs;

	// Task 3.4.6
	GenreType findedGenre = Jazz;
	do
	{
		cout << "������� ���� ������� �����\n(0 - Jazz, 1 - HipHop,";
		cout << "2 - Electronic,\n3 - Rock, 4 - Disco, 5 - Fusion, 6 - Pop ): ";
		int findedGenreNum = 0;
		cin >> findedGenreNum;
		cout << endl;
		if (ValueValidator::IsValue())
		{
			try
			{
				findedGenre = GetGenreType(findedGenreNum);
				break;
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl << endl;
				continue;
			}
		}
		else
		{
			cout << "����������, ������ ����� �����" << endl << endl;
		}
	} while (true);
	int findedGenreSongsCount = band.GetAllGenreSongsCount(findedGenre);
	Song* findedGenreSongs = 
		band.GetAllGenreSongs(findedGenre, findedGenreSongsCount);
	if (findedGenreSongs != 0)
	{
		cout << "�� ������� " << "\"" << GetGenreForWrite(findedGenre) << "\"";
		cout << " ������� " << findedGenreSongsCount << " �����:" << endl << endl;
		PrintAllSongs(findedGenreSongs, findedGenreSongsCount);
	}
	else
	{
		cout << "�� ������� " << "\"" << GetGenreForWrite(findedGenre);
		cout << "\"";
		cout << " ������ �� �������" << endl << endl;
	}
	PrintLine();
	
	delete[] findedGenreSongs;
}
