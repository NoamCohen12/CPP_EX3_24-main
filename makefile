CXX = clang++ -ggdb

.PHONY: all clean

all: main 

test: Test.o Catan.o devCard.o Hexagon.o Player.o board.o
	$(CXX) -o $@ $^ 
	

main: main.o Catan.o devCard.o Hexagon.o Player.o board.o
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

board.o: board.cpp board.hpp
	$(CXX) -c -o $@ $<

Test.o: Test.cpp
	$(CXX) -c -o $@ $<	

clean:
	 rm -f main  test *.o
