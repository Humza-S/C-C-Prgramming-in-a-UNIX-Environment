#include "CargoShip.h"

CargoShip::CargoShip() : Ship()
{
	tonnage = 0;
}

CargoShip::CargoShip(std::string n, std::string y, int t) : Ship(n, y)
{
	tonnage = t;
}

int CargoShip::getTonnage()
{
	return tonnage;
}

void CargoShip::setTonnage(int t)
{
	tonnage = t;
}

void CargoShip::print()
{
	std::cout << "Name: " << getName() << "\n";
	std::cout << "Cargo Capacity: " << getTonnage() << " tons\n";
	std::cout << "--------------------------------------------------\n";
}
