CXX = clang++

.PHONY: all clean

all: main

main: main.o Catan.o cube.o devCard.o hex.o player.o
	$(CXX) -o $@ $^

main.o: main.cpp 
	$(CXX) -o $@ $^	

Catan.o: Catan.cpp 
	$(CXX) -c -o $@ $<

cube.o: cube.cpp 
	$(CXX) -c -o $@ $<

devCard.o: devCard.cpp 
	$(CXX) -c -o $@ $<

hex.o: hex.cpp 
	$(CXX) -c -o $@ $<		

player.o: player.cpp player.hpp
	$(CXX) -c -o $@ $<			

clean:
	 rm -f main *.o
