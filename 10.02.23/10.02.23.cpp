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
	// ������� ������� ����������
	AircraftBuilderFactory builderFactory;
	// ������� ��������� ����������
	AircraftBuilder* helicopterBuilder = builderFactory.createHelicopterBuilder();

	// ������� ���������, ������� ����� �������������� ������� ������ ���������
	AircraftDirector helicopterDirector(helicopterBuilder);

	// �������� ��������
	Aircraft* helicopter = helicopterDirector.constructAircraft();

	// ������� ���������� � ���������
	std::cout << "Helicopter: " << std::endl;
	helicopter->printInfo();
	std::cout << std::endl;

	delete helicopter;
	delete helicopterBuilder;

	// ������� ��������� ���������
	AircraftBuilder* airplaneBuilder = builderFactory.createAirplaneBuilder();

	// ������� ���������, ������� ����� �������������� ������� ������ ��������
	AircraftDirector airplaneDirector(airplaneBuilder);

	// �������� �������
	Aircraft* airplane = airplaneDirector.constructAircraft();

	// ������� ���������� � ��������
	std::cout << "Airplane: " << std::endl;
	airplane->printInfo();
	std::cout << std::endl;

	delete airplane;
	delete airplaneBuilder;

	// ������� ��������� ������ ���� ����������� ��������� - ������������
	AircraftBuilder* quadcopterBuilder = builderFactory.createQuadcopterBuilder();

	// ������� ���������, ������� ����� �������������� ������� ������ �������������
	AircraftDirector quadcopterDirector(quadcopterBuilder);

	// �������� ������������
	Aircraft* quadcopter = quadcopterDirector.constructAircraft();

	// ������� ���������� � �������������
	std::cout << "Quadcopter: " << std::endl;
	quadcopter->printInfo();
	std::cout << std::endl;

	delete quadcopter;
	delete quadcopterBuilder;

	return 0;
}