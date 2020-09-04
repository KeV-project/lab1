#include "DemoWorkingWithClasses.h"

void DemoWorkingWithClasses::DemoBook()
{
	// Task 3.2.4
	const int booksCount = 2;
	Book* books = new Book [booksCount];
	cout << "Заполните массив из " << booksCount << " книг:";
	cout << endl << endl;
	for (int i = 0; i < booksCount; i++)
	{
		cout << "КНИГА №" << i + 1 << ":" << endl << endl;
		books[i].ReadFromConsole();
	}
	cout << "Массив книг:" << endl << endl;
	for (int i = 0; i < booksCount; i++)
	{
		cout << "КНИГА №" << i + 1 << ": ";
		books[i].WriteToConsole();
	}
	PrintLine();

	// Task 3.2.5
	cout << "Введите автора для поиска книги: ";
	cin.ignore(cin.rdbuf()->in_avail());
	string findedAuthor = "";
	getline(cin, findedAuthor, '\n');
	cin.clear();
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
		books[findedBookIndex].WriteToConsole();
	}

	delete[] books;

	PrintLine();
}

void DemoWorkingWithClasses::DemoRoute()
{
	const int routesCount = 2;
	Route* routes = new Route[routesCount];
	cout << "Заполните массив из " << routesCount << " рейсов:";
	cout << endl << endl;
	for (int i = 0; i < routesCount; i++)
	{
		cout << "РЕЙС №" << i + 1 << ":" << endl << endl;
		routes[i].ReadRouteFromConsole();
	}
	cout << "Массив рейсов:" << endl << endl;
	for (int i = 0; i < routesCount; i++)
	{
		routes[i].WriteRouteToConsole();
	}
	PrintLine();

	cout << "Введите остановку для поиска рейса: ";
	cin.ignore(cin.rdbuf()->in_avail());
	string findedStop = "";
	getline(cin, findedStop, '\n');
	cin.clear();
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

void DemoWorkingWithClasses::DemoFlightWithTime()
{
	// Task 3.3.9
	int const flightCount = 5;
	Flight** flights = new Flight * [flightCount]
	{
		new Flight(1, "Абакан", "Белгород",
			2020, 11, 9, 11, 41, 2020, 11, 9, 13, 51),
		new Flight(2, "Братск", "Воронеж",
			2020, 11, 11, 13, 31, 2020, 11, 11, 21, 25),
		new Flight(3, "Грозный", "Иваново",
			2020, 11, 12, 13, 15, 2020, 11, 12, 23, 21),
		new Flight(4, "Кемерово", "Казань",
			2020, 12, 15, 1, 13, 2020, 12, 15, 7, 17),
		new Flight(5, "Липецк", "Москва",
			2020, 12, 23, 17, 11, 2020, 12, 23, 23, 51),
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
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, findedSongTitle, '\n');
	cin.clear();
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
		cout << "По запросу " << "\"" << findedSongTitle << "\"";
		cout << " ничего не найдено";
	}
	cout << endl << endl;
	
	// Task 3.4.3
	cout << "Демонстрация работы функции FindAlbum():" << endl << endl;
	Album* findedAlbum = band.FindAlbum(findedSong);
	if (findedAlbum != nullptr)
	{
		cout << "Песня " << "\"" << findedSongTitle << "\"" << " ";
		cout << "находится в альбоме:" << endl;
		cout << findedAlbum->GetInformationAboutSong();
	}
	else
	{
		cout << "По запросу " << "\"" << findedSong << "\"";
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
}
