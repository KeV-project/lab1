#include "Flight.h"

void SetFlightNumber(Flight& flight, const string& flightNumber)
{
	flight.FlightNumber = flightNumber;
}

void SetPlaneNumber(Flight& flight, const int planeNumber)
{
	if (planeNumber < 0)
	{
		throw exception("����� �������� �� ����� ���� ������ 0");
	}
	flight.PlaneNumber = planeNumber;
}

void SetDeparture(Flight& flight, const string& departure)
{
	flight.Departure = departure;
}

void SetDestination(Flight& flight, const string& destination)
{
	flight.Destination = destination;
}

void SetDurationInMinutes(Flight& flight, const int durationInMinutes)
{
	if (durationInMinutes <= 0)
	{
		throw exception("����� ������ �� ����� ���� ������ ��� ����� 0");
	}
	flight.DurationInMinutes = durationInMinutes;
}

void SetDistanceInMeters(Flight& flight, const int distanceInMeters)
{
	if (distanceInMeters <= 0)
	{
		throw exception("��������� ������ �� ����� ���� ������ ��� ����� 0");
	}
	flight.DistanceInMeters = distanceInMeters;
}

void SetPassengers(Flight& flight, const int passengers)
{
	if (passengers < 0)
	{
		throw exception("���������� ���������� �� ����� ���� ������ 0");
	}
	flight.Passengers = passengers;
}

Flight* MakeFlight(const string& flightNumber, const int planeNumber,
	const string& departure, const string& destination,
	const int durationInMinutes, const int distanceInMeters,
	const int passengers)
{
	Flight* flight = new Flight();
	SetFlightNumber(*flight, flightNumber);
	SetPlaneNumber(*flight, planeNumber);
	SetDeparture(*flight, departure);
	SetDestination(*flight, destination);
	SetDurationInMinutes(*flight, durationInMinutes);
	SetDistanceInMeters(*flight, distanceInMeters);
	SetPassengers(*flight, passengers);
	return flight;
}

Flight* CopyFlight(const Flight& flight)
{
	Flight* copiedFlight = new Flight();
	copiedFlight->FlightNumber = flight.FlightNumber;
	copiedFlight->PlaneNumber = flight.PlaneNumber;
	copiedFlight->Departure = flight.Departure;
	copiedFlight->Destination = flight.Destination;
	copiedFlight->DurationInMinutes = flight.DurationInMinutes;
	copiedFlight->DistanceInMeters = flight.DistanceInMeters;
	copiedFlight->Passengers = flight.Passengers;
	return copiedFlight;
}

Flight* ReadFlight()
{
	Flight* flight = new Flight;
	cout << "������� ����� �����: ";
	string flightNimber = "";
	cin >> flightNimber;
	cout << endl;
	do
	{
		cout << "������� ����� ��������: ";
		int planeNumber = 0;
		cin >> planeNumber;
		cout << endl;
		if (IsValue())
		{
			SetFlightNumber(*flight, flightNimber);
			break;
		}
		else
		{
			cout << "������� ������������ ��������" << endl << endl;
		}
	} while (true);
	cout << "������� ����� ������ ��������: ";
	string departure = "";
	cin >> departure;
	cout << endl;
	SetDeparture(*flight, departure);
	cout << "������� ����� ���������� ��������: ";
	string destination = "";
	cin >> destination;
	cout << endl;
	SetDestination(*flight, destination);
	do
	{
		cout << "������� ����� ������(���): ";
		int durationInMinutes = 0;
		cin >> durationInMinutes;
		cout << endl;
		if (IsValue())
		{
			SetDurationInMinutes(*flight, durationInMinutes);
			break;
		}
		else
		{
			cout << "������� ������������ ��������" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ��������� ������(�): ";
		int distanceInMeters = 0;
		cin >> distanceInMeters;
		cout << endl;
		if (IsValue())
		{
			SetDistanceInMeters(*flight, distanceInMeters);
			break;
		}
		else
		{
			cout << "������� ������������ ��������" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "������� ���������� ���������� �� �����: ";
		int passengers = 0;
		cin >> passengers;
		cout << endl;
		if (IsValue())
		{
			SetPassengers(*flight, passengers);
			break;
		}
		else
		{
			cout << "������� ������������ ��������" << endl << endl;
		}
	} while (true);
	return flight;
}

void PrintFlight(const Flight& flight)
{
	cout << "���� � " << flight.FlightNumber << ": " << endl;
	cout << "����� ��������: " << flight.PlaneNumber << endl;
	cout << "����� ������ ��������: " << flight.Departure << endl;
	cout << "����� ���������� ��������: " << flight.Destination << endl;
	cout << "����� ������: " << flight.DurationInMinutes << endl;
	cout << "��������� ������: " << flight.DistanceInMeters << endl;
	cout << "���������� ���������� �� �����: ";
	cout << flight.Passengers << endl << endl;
}

void ChangeFlight(Flight* flight, const string& flightNumber,
	const int planeNumber, const string& departure, 
	const string& destination, const int durationInMinutes,
	const int distanceInMeters, const int passengers)
{
	SetFlightNumber(*flight, flightNumber);
	SetPlaneNumber(*flight, planeNumber);
	SetDeparture(*flight, departure);
	SetDestination(*flight, destination);
	SetDurationInMinutes(*flight, durationInMinutes);
	SetDistanceInMeters(*flight, distanceInMeters);
	SetPassengers(*flight, passengers);
}

void DemoDynamicFlight()
{
	Flight* pFlight = new Flight;
	SetFlightNumber(*pFlight, "23F14G");
	SetPlaneNumber(*pFlight, 221);
	SetDeparture(*pFlight, "��������");
	SetDestination(*pFlight, "��������");
	SetDurationInMinutes(*pFlight, 150);
	SetDistanceInMeters(*pFlight, 2500000);
	SetPassengers(*pFlight, 90);

	PrintFlight(*pFlight);

	delete pFlight;
}

void FindShortestFlight(Flight** flights, const int flightsCount)
{
	int minDuration = flights[0]->DurationInMinutes;
	int minDurationIndex = 0;
	for (int i = 1; i < flightsCount; i++)
	{
		if (flights[i]->DurationInMinutes < minDuration)
		{
			minDuration = flights[i]->DurationInMinutes;
			minDurationIndex = i;
		}
	}
	cout << "���� � ���������� �������� ��������:" << endl << endl;
	cout << "���� " << flights[minDurationIndex]->Departure;
	cout << " - " << flights[minDurationIndex]->Destination;
	cout << " ��������� � ������ ";
	cout << flights[minDurationIndex]->DurationInMinutes;
	cout << " �����" << endl;
	cout << "����� ��������: " << flights[minDurationIndex]->PlaneNumber;
	cout << ", �� ����� " << flights[minDurationIndex]->Passengers;
	cout << " �������" << endl << endl;
}

void DemoDynamicFlights()
{
	const int flightsCount = 7;
	Flight** flights = new Flight * [flightsCount]
	{
		MakeFlight("11D5N", 333, "������",
			"���������", 180, 5600000, 120),
		MakeFlight("7T5E1", 547, "�����������",
			"��������", 110, 3585000, 110),
		MakeFlight("23P08", 123, "�����",
			"������", 360, 5000000, 80),
		MakeFlight("1ER7G", 756, "��������",
			"����-���", 120, 2000000, 60),
		MakeFlight("4G7L1", 3001, "������",
			"������", 250, 3040000, 120),
		MakeFlight("SD147", 6413, "�����������",
			"�����", 120, 4339000, 113),
		MakeFlight("7CC77", 5204, "�����",
			"������", 270, 3600000, 250),
	};
	for (int i = 0; i < flightsCount; i++)
	{
		cout << "���� �" << i + 1 << endl << endl;
		PrintFlight(*flights[i]);
	}

	// Task 2.2.6.3
	PrintLine();
	FindShortestFlight(flights, flightsCount);

	for (int i = 0; i < flightsCount; i++)
	{
		delete flights[i];
	}
	delete[] flights;
}

void DemoFlight()
{
	// Task 2.2.3.1
	Flight firstFlight;
	SetFlightNumber(firstFlight, "5K47X");
	SetPlaneNumber(firstFlight, 3910);
	SetDeparture(firstFlight, "�����");
	SetDestination(firstFlight, "������");
	SetDurationInMinutes(firstFlight, 300);
	SetDistanceInMeters(firstFlight, 2800000);
	SetPassengers(firstFlight, 157);
	
	// Task 2.2.3.2
	cout << "����" << endl << endl;
	Flight* secondFlight = ReadFlight();
	PrintFlight(*secondFlight);
	delete secondFlight;
	PrintLine();
	
	// Task 2.2.3.3, 2.2.6.2
	cout << "������ �������� Flight ";
	cout << "��������� � ������� DemoDynamicFlights : " << endl << endl;
	DemoDynamicFlights();
	PrintLine();
	
	// Task 2.2.4.1
	cout << "������ � ���������� �� ���������:" << endl << endl;
	Flight* pFirstFlight = &firstFlight;
	cout << "���� firstFlight: " << endl << endl;
	PrintFlight(firstFlight);
	cout << "���������� ���� firstFlight: " << endl << endl;
	ChangeFlight(pFirstFlight, "5K47X", 3910, "�����",
		"�����-���������", 455, 4298000, 133);
	PrintFlight(*pFirstFlight);
	PrintLine();

	// Task 2.2.4.2
	Flight* pFirstFlight2 = &firstFlight;
	cout << "����� ���������� firstFlight: ";
	cout << &firstFlight << endl << endl;
	cout << "����� � ��������� pFirstFlight: ";
	cout << pFirstFlight << endl << endl;
	cout << "����� � ��������� pFirstFlight2: ";
	cout << pFirstFlight2 << endl << endl;
	PrintLine();

	// Task 2.2.6.1
	cout << "������ ������������ ������ Flight";
	cout << " � ������� DemoDynamicFlight : " << endl << endl;
	DemoDynamicFlight();
	PrintLine();
}
