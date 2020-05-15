#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>

class Ship
{
	private:
		std::string name;
		std::string year_built;

	public:
		// contructors
		Ship();
		Ship(std::string n, std::string y);

		// accessors
		std::string getName();
		std::string getYearBuilt();

		// mutators
		void setName(std::string n);
		void setYearBuilt(std::string y);

		// virtual functions
		virtual void print();

};
#endif

