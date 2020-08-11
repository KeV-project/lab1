#include "Flight.h"

void SetFlightNumber(Flight& flight, const string& flightNumber)
{
	flight.FlightNumber = flightNumber;
}

void SetPlaneNumber(Flight& flight, const int planeNumber)
{
	if (planeNumber < 0)
	{
		throw exception("Номер самолета не может быть меньше 0");
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
		throw exception("Время полета не может быть меньше или равно 0");
	}
	flight.DurationInMinutes = durationInMinutes;
}

void SetDistanceInMeters(Flight& flight, const int distanceInMeters)
{
	if (distanceInMeters <= 0)
	{
		throw exception("Дальность полета не может быть меньше или равна 0");
	}
	flight.DistanceInMeters = distanceInMeters;
}

void SetPassengers(Flight& flight, const int passengers)
{
	if (passengers < 0)
	{
		throw exception("Количество пассажиров не может быть меньше 0");
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
	cout << "Введите номер рейса: ";
	string flightNimber = "";
	cin >> flightNimber;
	cout << endl;
	do
	{
		cout << "Введите номер самолета: ";
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
			cout << "Введено недопустимое значение" << endl << endl;
		}
	} while (true);
	cout << "Введите пункт вылета самолета: ";
	string departure = "";
	cin >> departure;
	cout << endl;
	SetDeparture(*flight, departure);
	cout << "Введите пункт назначения самолета: ";
	string destination = "";
	cin >> destination;
	cout << endl;
	SetDestination(*flight, destination);
	do
	{
		cout << "Введите время полета(мин): ";
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
			cout << "Введено недопустимое значение" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите дальность полета(м): ";
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
			cout << "Введено недопустимое значение" << endl << endl;
		}
	} while (true);
	do
	{
		cout << "Введите количество пассажиров на борту: ";
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
			cout << "Введено недопустимое значение" << endl << endl;
		}
	} while (true);
	return flight;
}

void PrintFlight(const Flight& flight)
{
	cout << "Рейс № " << flight.FlightNumber << ": " << endl;
	cout << "Номер самолета: " << flight.PlaneNumber << endl;
	cout << "Пункт вылета самолета: " << flight.Departure << endl;
	cout << "Пункт назначения самолета: " << flight.Destination << endl;
	cout << "Время полета: " << flight.DurationInMinutes << endl;
	cout << "Дальность полета: " << flight.DistanceInMeters << endl;
	cout << "Количество пассажиров на борту: ";
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
	SetDeparture(*pFlight, "Кемерово");
	SetDestination(*pFlight, "Кемерово");
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
	cout << "Рейс с наименьшим временем перелета:" << endl << endl;
	cout << "Рейс " << flights[minDurationIndex]->Departure;
	cout << " - " << flights[minDurationIndex]->Destination;
	cout << " находится в полете ";
	cout << flights[minDurationIndex]->DurationInMinutes;
	cout << " минут" << endl;
	cout << "Номер самолета: " << flights[minDurationIndex]->PlaneNumber;
	cout << ", на борту " << flights[minDurationIndex]->Passengers;
	cout << " человек" << endl << endl;
}

void DemoDynamicFlights()
{
	const int flightsCount = 7;
	Flight** flights = new Flight * [flightsCount]
	{
		MakeFlight("11D5N", 333, "Москва",
			"Фьюмичино", 180, 5600000, 120),
		MakeFlight("7T5E1", 547, "Новосибирск",
			"Клайпеда", 110, 3585000, 110),
		MakeFlight("23P08", 123, "Дубай",
			"Москва", 360, 5000000, 80),
		MakeFlight("1ER7G", 756, "Кемерово",
			"Улан-Удэ", 120, 2000000, 60),
		MakeFlight("4G7L1", 3001, "Москва",
			"Италия", 250, 3040000, 120),
		MakeFlight("SD147", 6413, "Новосибирск",
			"Литва", 120, 4339000, 113),
		MakeFlight("7CC77", 5204, "Дубай",
			"Москва", 270, 3600000, 250),
	};
	for (int i = 0; i < flightsCount; i++)
	{
		cout << "Рейс №" << i + 1 << endl << endl;
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
	SetDeparture(firstFlight, "Томск");
	SetDestination(firstFlight, "Москва");
	SetDurationInMinutes(firstFlight, 300);
	SetDistanceInMeters(firstFlight, 2800000);
	SetPassengers(firstFlight, 157);
	
	// Task 2.2.3.2
	cout << "РЕЙС" << endl << endl;
	Flight* secondFlight = ReadFlight();
	PrintFlight(*secondFlight);
	delete secondFlight;
	PrintLine();
	
	// Task 2.2.3.3, 2.2.6.2
	cout << "Массив объектов Flight ";
	cout << "созданный в функции DemoDynamicFlights : " << endl << endl;
	DemoDynamicFlights();
	PrintLine();
	
	// Task 2.2.4.1
	cout << "Работа с указателем на структуру:" << endl << endl;
	Flight* pFirstFlight = &firstFlight;
	cout << "Рейс firstFlight: " << endl << endl;
	PrintFlight(firstFlight);
	cout << "Измененный рейс firstFlight: " << endl << endl;
	ChangeFlight(pFirstFlight, "5K47X", 3910, "Томск",
		"Санкт-Петербург", 455, 4298000, 133);
	PrintFlight(*pFirstFlight);
	PrintLine();

	// Task 2.2.4.2
	Flight* pFirstFlight2 = &firstFlight;
	cout << "Адрес переменной firstFlight: ";
	cout << &firstFlight << endl << endl;
	cout << "Адрес в указателе pFirstFlight: ";
	cout << pFirstFlight << endl << endl;
	cout << "Адрес в указателе pFirstFlight2: ";
	cout << pFirstFlight2 << endl << endl;
	PrintLine();

	// Task 2.2.6.1
	cout << "Создан динамический объект Flight";
	cout << " в функции DemoDynamicFlight : " << endl << endl;
	DemoDynamicFlight();
	PrintLine();
}
