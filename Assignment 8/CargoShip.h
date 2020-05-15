#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship
{
	private:
		int tonnage;

	public:
		// constructors
		CargoShip();
		CargoShip(std::string n, std::string y, int t);

		// accessors
		int getTonnage();

		// mutators
		void setTonnage(int t);

		// virtual functions
		virtual void print();

};
#endif
