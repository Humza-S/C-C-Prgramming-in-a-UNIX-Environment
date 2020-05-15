#include "Ship.h"

Ship::Ship()
{
	name = "";
	year_built = "";
}

Ship::Ship(std::string n, std::string y)
{
	name = n;
	year_built = y;
}

std::string Ship::getName()
{
	return name;
}

std::string Ship::getYearBuilt()
{
	return year_built;
}

void Ship::setName(std::string n)
{
	name = n;
}

void Ship::setYearBuilt(std::string y)
{
	year_built = y;
}

void Ship::print()
{
	std::cout << "Name: " << getName() << "\n";
	std::cout << "Year Built: " << getYearBuilt() << "\n";
	std::cout << "--------------------------------------------------\n";
}
