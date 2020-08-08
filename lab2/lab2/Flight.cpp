#include "Flight.h"

//TODO: Сигнатура +
Flight* MakeFlight(const string& flightNumber, const int planeNumber,
	const string& departure, const string& destination, const int duration,
	const int distance, const int passengers)
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

Flight* CopyFlight(const Flight& flight)
{
	Flight* copiedFlight = new Flight();
	copiedFlight->FlightNumber = flight.FlightNumber;
	copiedFlight->PlaneNumber = flight.PlaneNumber;
	copiedFlight->Departure = flight.Departure;
	copiedFlight->Destination = flight.Destination;
	copiedFlight->Duration = flight.Duration;
	copiedFlight->Distance = flight.Distance;
	copiedFlight->Passengers = flight.Passengers;
	return copiedFlight;
}

void ReadFlight(Flight& flight)
{
	cout << "Введите номер рейса: ";
	cin >> flight.FlightNumber;
	cout << endl;
	cout << "Введите номер самолета: ";
	cin >> flight.PlaneNumber;
	cout << endl;
	cout << "Введите пункт вылета самолета: ";
	cin >> flight.Departure;
	cout << endl;
	cout << "Введите пункт назначения самолета: ";
	cin >> flight.Destination;
	cout << endl;
	cout << "Введите время полета(мин): ";
	cin >> flight.Duration;
	cout << endl;
	cout << "Введите дальность полета(км): ";
	cin >> flight.Distance;
	cout << endl;
	cout << "Введите количество пассажиров на борту: ";
	cin >> flight.Passengers;
	cout << endl;
}

void PrintFlight(const Flight& flight)
{
	cout << "Рейс № " << flight.FlightNumber << ": " << endl;
	cout << "Номер самолета: " << flight.PlaneNumber << endl;
	cout << "Пункт вылета самолета: " << flight.Departure << endl;
	cout << "Пункт назначения самолета: " << flight.Destination << endl;
	cout << "Время полета: " << flight.Duration << endl;
	cout << "Дальность полета: " << flight.Distance << endl;
	cout << "Количество пассажиров на борту: ";
	cout << flight.Passengers << endl << endl;
}

//TODO: Сигнатура +
void ChangeFlight(Flight* flight, const string& flightNumber,
	const int planeNumber, const string& departure, 
	const string& destination, const int duration,
	const int distance, const int passengers)
{
	flight->FlightNumber = flightNumber;
	flight->PlaneNumber = planeNumber;
	flight->Departure = departure;
	flight->Destination = destination;
	flight->Duration = duration;
	flight->Distance = distance;
	flight->Passengers = passengers;
}

void DemoDynamicFlight()
{
	Flight* pFlight = new Flight;
	pFlight->FlightNumber = "23F14G";
	pFlight->PlaneNumber = 221;
	pFlight->Departure = "Кемерово";
	pFlight->Destination = "Улан-Удэ";
	pFlight->Duration = 150;
	pFlight->Distance = 2500;
	pFlight->Passengers = 90;

	PrintFlight(*pFlight);

	delete pFlight;
}

//TODO: Сигнатура +
void FindShortestFlight(Flight** flights, const int flightsCount)
{
	int minDuration = flights[0]->Duration;
	int minDurationIndex = 0;
	for (int i = 1; i < flightsCount; i++)
	{
		if (flights[i]->Duration < minDuration)
		{
			minDuration = flights[i]->Duration;
			minDurationIndex = i;
		}
	}
	cout << "Рейс с наименьшим временем перелета:" << endl << endl;
	cout << "Рейс " << flights[minDurationIndex]->Departure;
	cout << " - " << flights[minDurationIndex]->Destination;
	cout << " находится в полете " << flights[minDurationIndex]->Duration;
	cout << " минут" << endl;
	cout << "Номер самолета: " << flights[minDurationIndex]->PlaneNumber;
	cout << ", на борту " << flights[minDurationIndex]->Passengers;
	cout << " человек" << endl << endl;
}

void DemoDynamicFlights()
{
	//TODO: Части дублируются с методом DemoFlight
	const int flightsCount = 4;
	Flight** flights = new Flight * [flightsCount]
	{
		//TODO: RSDN
		MakeFlight("11D5N", 333, "Москва", "Фьюмичино", 180, 5600, 120),
		MakeFlight("7T5E1", 547, "Новосибирск", "Клайпеда", 110, 3585, 110),
		MakeFlight("23P08", 123, "Дубай", "Москва", 360, 5000, 80),
		MakeFlight("1ER7G", 756, "Кемерово", "Улан-Удэ", 120, 2000, 60),
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
	firstFlight.FlightNumber = "5K47X";
	firstFlight.PlaneNumber = 3910;
	firstFlight.Departure = "Томск";
	firstFlight.Destination = "Москва";
	firstFlight.Duration = 300;
	firstFlight.Distance = 2800;
	firstFlight.Passengers = 157;
	
	// Task 2.2.3.2
	Flight secondFlight;
	cout << "РЕЙС" << endl << endl;
	ReadFlight(secondFlight);
	PrintFlight(secondFlight);
	PrintLine();
	
	// Task 2.2.3.3
	const int flightsCount = 3;
	Flight** flights = new Flight * [flightsCount]
	{
		//TODO: RSDN
		MakeFlight("4G7L1", 3001, "Москва", "Италия", 250, 3040, 120),
		MakeFlight("SD147", 6413, "Новосибирск", "Литва", 120, 4339, 113),
		MakeFlight("7CC77", 5204,  "Дубай", "Москва", 270, 3600, 250),
	};
	cout << "Массив рейсов:" << endl << endl;
	for (int i = 0; i < flightsCount; i++)
	{
		cout << "Рейс №" << i + 1 << endl << endl;
		PrintFlight(*flights[i]);
	}
	PrintLine();
	for (int i = 0; i < flightsCount; i++)
	{
		delete flights[i];
	}
	delete[] flights;
	
	// Task 2.2.4.1
	cout << "Работа с указателем на структуру:" << endl << endl;
	Flight* pFirstFlight = &firstFlight;
	cout << "Рейс firstFlight: " << endl << endl;
	PrintFlight(firstFlight);
	cout << "Измененный рейс firstFlight: " << endl << endl;
	ChangeFlight(pFirstFlight, "5K47X", 3910, "Томск",
		"Санкт-Петербург", 455, 4298, 133);
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

	// Task 2.2.6.2
	cout << "Массив объектов Flight ";
	cout << "созданный в функции DemoDynamicFlights : " << endl << endl;
	DemoDynamicFlights();
	PrintLine();
}
