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

void PrintFlight(Flight& flight)
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

void ChangeFlight(Flight* flight, string flightNumber,
	int planeNumber, string departure, string destination,
	int duration, int distance, int passengers)
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
	ChangeFlight(pFirstFlight, "5K47X", 3910, "Томск", "Санкт-Петербург", 455, 4298, 133);
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
