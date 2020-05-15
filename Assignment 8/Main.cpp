#include <iostream>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

int main()
{
    Ship* ships[3] = {
        new Ship("Ship McShipFace", "2016"),
        new CruiseShip("CruiseShip McCruiseFace", "2018", 3500),
        new CargoShip("CargoShip McCargoFace", "2020", 123456)
    }; // array of ship objects

    for (int i = 0; i < 3; i++)
        ships[i]->print(); // going through array to print 

    return 0;
}
