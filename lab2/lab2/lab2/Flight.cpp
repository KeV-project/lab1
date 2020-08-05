#include "Flight.h"

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
	cout << "Рейс " << flight.FlightNumber << " :" << endl;
	cout << "Номер самолета: " << flight.PlaneNumber << endl;
	cout << "Пункт вылета самолета: " << flight.Departure << endl;
	cout << "Пункт назначения самолета: " << flight.Destination << endl;
	cout << "Время полета: " << flight.Duration << endl;
	cout << "Дальность полета: " << flight.Distance << endl;
	cout << "Количество пассажиров на борту: " << flight.Passengers << endl << endl;
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
	ReadFlight(secondFlight);
	PrintFlight(secondFlight);
	PrintLine();
}
