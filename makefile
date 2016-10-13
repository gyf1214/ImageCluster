CXX = g++
CXXFLAGS = -g -Wall

all: main

rebuild: clean all

clean:
	rm -f *.o main

main: main.o vector.o util.o
	g++ -o $@ $^

main.o: main.cc vector.hpp util.hpp

vector.o: vector.cc vector.hpp

util.o: util.cc util.hpp
