
output: main.o mode.o median.o
	g++ main.o mode.o median.o -o output

main.o: main.cpp
	g++ -Wall -c main.cpp

mode.o: mode.cpp mode.h
	g++ -Wall -c mode.cpp

median.o: median.cpp median.h
	g++ -Wall -c median.cpp

clean:
	rm *.o
