#include "PrintToColsole.h"

// ����� �������������� ������ ����� ���������
void PrintLine()
{
    cout << "___________________________";
    cout << "___________________________";
    cout << "__________________________" << endl << endl;
}

void PrintBook(Book* book)
{
    for (int i = 0; i < book->GetAuthorsCount(); i++)
    {
        cout << book->GetAuthors()[i];
        if (i + 1 == book->GetAuthorsCount())
        {
            cout << " ";
        }
        else
        {
            cout << ", ";
        }
    }
    cout << book->GetTitle() << ". ";
    cout << book->GetYear() << ". ";
    cout << "- " << book->GetPagesCount() << "c." << endl << endl;
}

void PrintBooks(Book** books, const int booksCount)
{
    for (int i = 0; i < booksCount; i++)
    {
        cout << "����� �" << i + 1 << ": ";
        PrintBook(books[i]);
    }
}

void PrintRoute(Route* route)
{
    cout << "���� �" << route->GetNumber() << " (";
    cout << route->GetStops()[0] << " - ";
    cout << route->GetStops()[route->GetStopsCount() - 1];
    cout << ") ��������� � ���� " << route->GetDuration();
    cout << " �����, " << endl;
    cout << "����������� �� ������� � �������������� � ";
    cout << route->GetPeriodicity() << " �����. " << endl;
    cout << "������� �������� " << route->GetStopsCount();
    cout << " ���������" << endl << endl;
}

void PrintRoutes(Route** routes, const int routesCount)
{
    for (int i = 0; i < routesCount; i++)
    {
        PrintRoute(routes[i]);
    }
}

void PrintRectangle(Rect* rectangle)
{
    cout << "����a: " << rectangle->GetLength() << endl;
    cout << "������: " << rectangle->GetWidth() << endl;
    cout << "x: " << rectangle->GetCenterX() << endl;
    cout << "y: " << rectangle->GetCenterY() << endl << endl;
}

void PrintRectangles(Rect** rectangles, const int rectanglesCount)
{
    for (int i = 0; i < rectanglesCount; i++)
    {
        cout << "������������� �" << i + 1 << ": " << endl;
        PrintRectangle(rectangles[i]);
    }
}

void PrintFlight(Flight* flight)
{
    cout << flight->GetNumber() << " ";
    cout << flight->GetDeparture() << " - ";
    cout << flight->GetDestination() << " ";
    cout << "�����: " << flight->GetDepartureTime().GetTime() << " ";
    cout << "�������� " << flight->GetDestinationTime().GetTime() << endl;
}

void PrintFlights(Flight** flights, const int flightsCount)
{
    for (int i = 1; i < flightsCount; i++)
    {
        cout << "���� �";
        PrintFlight(flights[i]);
    }
    cout << endl;
}

void PrintInfoAboutSong(Song& song)
{
    cout << song.GetTitle() << " - ����������������� ";
    cout << song.GetDuration() << " �����(�/�), ���� ";
    cout << GetGenreForWrite(song.GetGenre()) << endl;
}

void PrintAllSongs(Song* songs, const int songsCount)
{
    for (int i = 0; i < songsCount; i++)
    {
        PrintInfoAboutSong(songs[i]);
    }
    cout << endl;
}

void PrintInfoAboutAlbum(Album *album)
{
    cout << album->GetName() << "(" << album->GetYear() << " ���) ";
    cout << "�������� " << album->GetSongsCount() << " ���(�/��/��)";
}

void PrintInfoAboutBand(Band& band)
{
    cout << band.GetName() << ": ";
    cout << "������ - " << band.GetSolist() << ", ";
    cout << band.GetAlbumsCount() << " �������:" << endl << endl;
    for (int i = 0; i < band.GetAlbumsCount(); i++)
    {
        PrintInfoAboutAlbum(band.GetAlbums()[i]);
        cout <<  ": " << endl << endl;
        PrintAllSongs(band.GetAlbums()[i]->GetSongs(), 
            band.GetAlbums()[i]->GetSongsCount());
    }
}
