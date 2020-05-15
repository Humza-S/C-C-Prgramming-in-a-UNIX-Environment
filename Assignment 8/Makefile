
output : Ship.o CargoShip.o CruiseShip.o Main.o
	g++ -Wall Ship.o CargoShip.o CruiseShip.o Main.o -o output

Main.o:	Main.cpp
	g++ -Wall -c Main.cpp

Ship.o : Ship.h Ship.cpp
	g++ -Wall -c Ship.cpp

CargoShip.o: CargoShip.h CargoShip.cpp
	g++ -Wall -c CargoShip.cpp

CruiseShip.o: CruiseShip.h CruiseShip.cpp
	g++ -Wall -c CruiseShip.cpp

clean:
	rm *.o
