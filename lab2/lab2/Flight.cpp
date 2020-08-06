#include "Flight.h"

Flight* MakeFlight(int flightNumber, int planeNumber, string departure,
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
	cout << "���� " << flight.FlightNumber << " :" << endl;
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

	// Task 2.2.3.3
	
}
