#include <iostream>
#include "HelicopterDirector.h"
#include "BasicHelicopterBuilder.h"
#include "Helicopter.h"
#include "AircraftConstructor.h"
#include "AircraftBuilder.h"
#include "HangGliderBuilder.h"
#include "PassengerPlane.h"
#include "Aircraft.h"


int main() {
	// Создаем фабрику строителей
	AircraftBuilderFactory builderFactory;
	// Создаем строителя вертолетов
	AircraftBuilder* helicopterBuilder = builderFactory.createHelicopterBuilder();

	// Создаем директора, который будет контролировать процесс сборки вертолета
	AircraftDirector helicopterDirector(helicopterBuilder);

	// Собираем вертолет
	Aircraft* helicopter = helicopterDirector.constructAircraft();

	// Выводим информацию о вертолете
	std::cout << "Helicopter: " << std::endl;
	helicopter->printInfo();
	std::cout << std::endl;

	delete helicopter;
	delete helicopterBuilder;

	// Создаем строителя самолетов
	AircraftBuilder* airplaneBuilder = builderFactory.createAirplaneBuilder();

	// Создаем директора, который будет контролировать процесс сборки самолета
	AircraftDirector airplaneDirector(airplaneBuilder);

	// Собираем самолет
	Aircraft* airplane = airplaneDirector.constructAircraft();

	// Выводим информацию о самолете
	std::cout << "Airplane: " << std::endl;
	airplane->printInfo();
	std::cout << std::endl;

	delete airplane;
	delete airplaneBuilder;

	// Создаем строителя нового типа летательных аппаратов - квадрокоптер
	AircraftBuilder* quadcopterBuilder = builderFactory.createQuadcopterBuilder();

	// Создаем директора, который будет контролировать процесс сборки квадрокоптера
	AircraftDirector quadcopterDirector(quadcopterBuilder);

	// Собираем квадрокоптер
	Aircraft* quadcopter = quadcopterDirector.constructAircraft();

	// Выводим информацию о квадрокоптере
	std::cout << "Quadcopter: " << std::endl;
	quadcopter->printInfo();
	std::cout << std::endl;

	delete quadcopter;
	delete quadcopterBuilder;

	return 0;
}