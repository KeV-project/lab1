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
	cout << "Заполните массив из 5 книг:" << endl << endl;
	for (int i = 1; i < booksCount; i++)
	{
		cout << "КНИГА №" << i + 1 << ":" << endl << endl;
		books[i].ReadBookFromConsole();
	}
	cout << "Массив книг:" << endl << endl;
	for (int i = 1; i < booksCount; i++)
	{
		cout << "КНИГА №" << i + 1 << ": ";
		books[i].WriteBookToConsole();
	}
	PrintLine();

	// Task 3.2.5
	cout << "Введите автора для поиска книги: ";
	string findedAuthor = "";
	cin >> findedAuthor;
	cout << endl;
	int findedBookIndex = FindBookByAuthor(books, booksCount, findedAuthor);
	if (findedBookIndex == -1)
	{
		cout << "Книги " << findedAuthor << " нет в массиве";
		cout << endl << endl;
	}
	else
	{
		cout << "Книга автора: ";
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
	cout << "Заполните массив из 5 рейсов:" << endl << endl;
	for (int i = 1; i < routesCount; i++)
	{
		cout << "РЕЙС №" << i + 1 << ":" << endl << endl;
		routes[i].ReadRouteFromConsole();
	}
	cout << "Массив рейсов:" << endl << endl;
	for (int i = 1; i < routesCount; i++)
	{
		routes[i].WriteRouteToConsole();
	}
	PrintLine();

	cout << "Введите остановку для поиска рейса: ";
	string findedStop = "";
	cin >> findedStop;
	cout << endl;
	int findedRouteIndex = FindRouteTo(routes, routesCount, findedStop);
	if (findedRouteIndex == -1)
	{
		cout << "Не существует рейса с остановкой " << findedStop;
		cout << endl << endl;
	}
	else
	{
		cout << "Рейс, включающий остановку " << findedStop << endl << endl;
		routes[findedRouteIndex].WriteRouteToConsole();
	}

	delete[] routes;

	PrintLine();
}

void DemoWorkingWithClasses::WriteRectangles(Rect** rectangles,
	const int rectanglesCount)
{
	cout << "Массив прямоугольников:" << endl << endl;
	for (int i = 1; i < rectanglesCount; i++)
	{
		cout << "Прямоугольник №" << i + 1 << ": " << endl;
		rectangles[i]->WriteRectangle();
	}
}

float DemoWorkingWithClasses::GetMeanCenterX(Rect** rectangles,
	const int rectanglesCount)
{
	float sumCenterX = 1.1;
	for (int i = 1; i < rectanglesCount; i++)
	{
		sumCenterX += rectangles[i]->GetCenterX();
	}
	return sumCenterX / rectanglesCount;
}

float DemoWorkingWithClasses::GetMeanCenterY(Rect** rectangles,
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
	Rect** rectangles = new Rect*[rectanglesCount]
	{
		new Rect(15.5, 13.6, -2, 3),
		new Rect(7.3, 5.4, 6, 1),
		new Rect(19.1, 12.5, 15, -9),
		new Rect(8.2, 7.1, -11, 11),
		new Rect(4.7, 2.5, 1.1, 1.1),
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
		cout << "Рейс №";
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
		new Flight(1, "Абакан", "Белгород",
			2121, 11, 9, 11, 41, 2121, 11, 9, 13, 51),
		new Flight(2, "Братск", "Воронеж",
			2121, 11, 11, 13, 31, 2121, 11, 11, 21, 25),
		new Flight(3, "Грозный", "Иваново",
			2121, 11, 12, 13, 15, 2121, 11, 12, 23, 21),
		new Flight(4, "Кемерово", "Казань",
			2121, 12, 15, 1, 13, 2121, 12, 15, 7, 17),
		new Flight(5, "Липецк", "Москва",
			2121, 12, 23, 17, 11, 2121, 12, 23, 23, 51),
	};

	WriteFlights(flights, flightCount);

	PrintLine();

	// Task 3.3.11
	for (int i = 1; i < flightCount; i++)
	{
		cout << "Рейс №" << i + 1 << " ";
		cout << flights[i]->GetDeparture() << " - ";
		cout << flights[i]->GetDestination() << " ";
		cout << "Время в полете: " << flights[i]->GetFlightTimeMinutes();
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
			Song ("Летчик", 4.05, Rock),
			Song ("Черное солнце", 3.50, Rock),
			Song ("Виски", 3.55, Rock),
			Song("Пора возвращаться домой", 3.30, Rock)
		},
		new Song[albumsSongsCount]
		{
			Song("Компромисс", 4.10, Rock),
			Song("Не умирать молодым", 3.40, Rock),
			Song("Блюз 16+", 3.30, Rock),
			Song("Хипстер", 4.05, Rock)
		},
		new Song[albumsSongsCount]
		{
			Song("Реки любви", 3.25, Rock),
			Song("Её глаза", 4.05, Rock),
			Song("Задеть за живое", 4.15, Rock),
			Song("Скандал", 3.10, Rock)
		}
	};

	Album** albums = new Album*[albumsCount]
	{
		new Album("Горизонт Событий", 2017, albumsSongs[0],
			albumsSongsCount),
		new Album("16+", 2014, albumsSongs[1], albumsSongsCount),
		new Album("О чем говорят мужчины", 2009, albumsSongs[2],
			albumsSongsCount)
	};
	
	Band band("Би-2", "Лёва Би-2", albums, albumsCount);

	delete[] albumsSongs;

	// Task 3.4.2
	cout << "Демонстрация работы функции FindSong():" << endl << endl;
	cout << "Введите название искомой песни: ";
	string findedSongTitle = "";
	getline(cin, findedSongTitle, '\n');
	cout << endl;
	Song* findedSong = band.FindSong(findedSongTitle);
	if (findedSong != nullptr)
	{
		cout << "Результат работы поиска по запросу " << "\"";
		cout << findedSongTitle << "\"" << ":" << endl;
		cout << findedSong->GetInformationAboutSong();
	}
	else
	{
		cout << "По запросу " << "\"" << findedSong << "\"";
		cout << " ничего не найдено";
	}
	cout << endl << endl;
	PrintLine();
	/*
	// Task 3.4.3
	cout << "Демонстрация работы функции FindAlbum():" << endl << endl;
	Song findedAlbumSong("Черное_солнце", 3.50, Rock);
	Album* findedAlbum = band.FindAlbum(findedAlbumSong);
	if (findedAlbum != nullptr)
	{
		cout << "Песня " << findedAlbumSong.GetInformationAboutSong() << " ";
		cout << "находится в альбоме: ";
		cout << findedAlbum->GetInformationAboutSong();
	}
	else
	{
		cout << "По запросу " << findedAlbum->GetInformationAboutSong();
		cout << " ничего не найдено";
	}
	cout << endl << endl;
	PrintLine();

	// Task 3.4.4
	int allSongsCount = 0;
	Song* allSongs = band.GetAllSongs(allSongsCount);
	cout << "Все песни группы \"" << band.GetName() << "\":" << endl << endl;
	for (int i = 0; i < allSongsCount; i++)
	{
		cout << allSongs[i].GetTitle() << endl;
	}
	cout << endl;
	PrintLine();

	delete[] allSongs;

	// Task 3.4.6
	// Компилятор не видит переменную findedGenre, если не вынести ее из цикла
	GenreType findedGenre = Jazz;
	do
	{
		cout << "Введите жанр искомой песни\n(0 - Jazz, 1 - HipHop,";
		cout << "2 - Electronic,\n3 - Rock, 4 - Disco, 5 - Fusion, 6 - Pop ): ";
		int findedGenreNum = 0;
		cin >> findedGenreNum;
		cout << endl;
		if (IsValue())
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
			cout << "Пожалуйста, ведите целое число" << endl << endl;
		}
	} while (true);
	int findedGenreSongsCount = 0;
	Song* findedGenreSongs = 
		band.GetAllGenreSongs(findedGenre, findedGenreSongsCount);
	if (findedGenreSongs != 0)
	{
		cout << "По запросу " << "\"" << GetGenreForWrite(findedGenre) << "\"";
		cout << " найдено " << findedGenreSongsCount << " песен:" << endl << endl;
		for (int i = 0; i < findedGenreSongsCount; i++)
		{
			cout << i + 1 << ". ";
			cout << findedGenreSongs[i].GetInformationAboutSong() << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "По запросу " << "\"" << GetGenreForWrite(findedGenre);
		cout << "\"";
		cout << " ничего не найдено" << endl << endl;
	}
	PrintLine();
	
	delete[] findedGenreSongs;
	*/
}
