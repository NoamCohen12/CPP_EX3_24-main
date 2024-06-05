CXX = clang++

.PHONY: all clean

all: main

main: main.o Catan.o devCard.o Hexagon.o Player.o
	$(CXX) -o $@ $^

main.o: main.cpp 
	$(CXX) -c -o $@ $^	

Catan.o: Catan.cpp 
	$(CXX) -c -o $@ $<

devCard.o: devCard.cpp 
	$(CXX) -c -o $@ $<

Hexagon.o: Hexagon.cpp 
	$(CXX) -c -o $@ $<		

Player.o: Player.cpp Player.hpp
	$(CXX) -c -o $@ $<			

clean:
	 rm -f main *.o
