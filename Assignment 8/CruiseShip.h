#ifndef CRUISE_SHIP
#define CRUISE_SHIP

#include "Ship.h"

class CruiseShip : public Ship
{
	private:
		int max_passengers;

	public:
		// constructors
		CruiseShip();
		CruiseShip(std::string n, std::string y, int p);

		// accessors
		int getMaxPassengers();

		// mutators
		void setMaxPassengers(int p);

		// virtual functions
		virtual void print();

};
#endif
