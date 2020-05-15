#include "CruiseShip.h"

CruiseShip::CruiseShip() : Ship()
{
	max_passengers = 0;
}

CruiseShip::CruiseShip(std::string n, std::string y, int p) : Ship(n, y)
{
	max_passengers = p;
}

int CruiseShip::getMaxPassengers()
{
	return max_passengers;
}

void CruiseShip::setMaxPassengers(int p)
{
	max_passengers = p;
}

void CruiseShip::print()
{
	std::cout << "Name: " << getName() << "\n";
	std::cout << "Maximum Number of Passengers: " << getMaxPassengers() << "\n";
	std::cout << "--------------------------------------------------\n";
}
