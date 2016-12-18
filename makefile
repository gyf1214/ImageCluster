CXX = g++
CXXFLAGS = -O2 -Wall

all: main

rebuild: clean all

clean:
	rm -f *.o main

main: main.o vector.o util.o
	g++ -o $@ $^

main.o: main.cc vector.hpp util.hpp makefile

vector.o: vector.cc vector.hpp makefile

util.o: util.cc util.hpp makefile
