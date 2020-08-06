#include "Flight.h"

Flight* MakeFlight(string flightNumber, int planeNumber, string departure,
	string destination, int duration, int distance, int passengers)
{
	Flight* flight = new Flight();
	flight->FlightNumber = flightNumber;
	flight->PlaneNumber = planeNumber;
	flight->Departure = departure;
	flight->Destination = destination;
	flight->Duration = duration;
	flight->Distance = distance;
	flight->Passengers = passengers;
	return flight;
}

void ReadFlight(Flight& flight)
{
	cout << "������� ����� �����: ";
	cin >> flight.FlightNumber;
	cout << endl;
	cout << "������� ����� ��������: ";
	cin >> flight.PlaneNumber;
	cout << endl;
	cout << "������� ����� ������ ��������: ";
	cin >> flight.Departure;
	cout << endl;
	cout << "������� ����� ���������� ��������: ";
	cin >> flight.Destination;
	cout << endl;
	cout << "������� ����� ������(���): ";
	cin >> flight.Duration;
	cout << endl;
	cout << "������� ��������� ������(��): ";
	cin >> flight.Distance;
	cout << endl;
	cout << "������� ���������� ���������� �� �����: ";
	cin >> flight.Passengers;
	cout << endl;
}

void PrintFlight(Flight& flight)
{
	cout << "���� � " << flight.FlightNumber << ": " << endl << endl;
	cout << "����� ��������: " << flight.PlaneNumber << endl;
	cout << "����� ������ ��������: " << flight.Departure << endl;
	cout << "����� ���������� ��������: " << flight.Destination << endl;
	cout << "����� ������: " << flight.Duration << endl;
	cout << "��������� ������: " << flight.Distance << endl;
	cout << "���������� ���������� �� �����: ";
	cout << flight.Passengers << endl << endl;
}

void DemoFlight()
{
	/*
	// Task 2.2.3.1
	Flight firstFlight;
	firstFlight.PlaneNumber = 391;
	firstFlight.Departure = "Tomsk";
	firstFlight.Destination = "Moscow";
	firstFlight.Duration = 300;
	firstFlight.Distance = 2800;
	firstFlight.Passengers = 157;

	// Task 2.2.3.2
	Flight secondFlight;
	cout << "����" << endl << endl;
	ReadFlight(secondFlight);
	PrintFlight(secondFlight);
	PrintLine();
	*/
	// Task 2.2.3.3
	const int flightsCount = 3;
	Flight** flights = new Flight * [flightsCount]
	{
		MakeFlight("4G7L1", 3001, "������", "������", 250, 3040, 120),
		MakeFlight("SD147", 6413, "�����������", "�����", 120, 4339, 113),
		MakeFlight("7CC77", 5204,  "�����", "������", 270, 3600, 250),
	};
	cout << "������ ������:" << endl << endl;
	for (int i = 0; i < flightsCount; i++)
	{
		PrintFlight(*flights[i]);
	}
	PrintLine();
	for (int i = 0; i < flightsCount; i++)
	{
		delete flights[i];
	}
	delete[] flights;
}
