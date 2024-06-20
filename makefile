CXX = clang++ -ggdb

.PHONY: all clean

all: main 

test: Test.o Catan.o devCard.o Hexagon.o Player.o Board.o Knight.o Monopoly.o Year_Of_Plenty.o Road_Building.o Victory_Point.o
	$(CXX) -o $@ $^ 
	

main: main.o Catan.o Hexagon.o Player.o Board.o Knight.o Monopoly.o Year_Of_Plenty.o Road_Building.o Victory_Point.o
	$(CXX) -o $@ $^

main.o: main.cpp 
	$(CXX) -c -o $@ $^	

Catan.o: Catan.cpp 
	$(CXX) -c -o $@ $<

Knight.o: Knight.cpp DevCard.hpp  Knight.hpp 
	$(CXX) -c -o $@ $<

Monopoly.o:Monopoly.cpp DevCard.hpp  Monopoly.hpp
	$(CXX) -c -o $@ $<


Year_Of_Plenty.o: Year_Of_Plenty.cpp DevCard.hpp Year_Of_Plenty.cpp Year_Of_Plenty.hpp
	$(CXX) -c -o $@ $<


Road_Building.o:Road_Building.cpp DevCard.hpp Road_Building.cpp Road_Building.hpp
	$(CXX) -c -o $@ $<


Victory_Point.o: Victory_Point.cpp DevCard.hpp Victory_Point.cpp Victory_Point.hpp
	$(CXX) -c -o $@ $<

Hexagon.o: Hexagon.cpp 
	$(CXX) -c -o $@ $<		

Player.o: Player.cpp Player.hpp
	$(CXX) -c -o $@ $<			

Board.o: Board.cpp Board.hpp
	$(CXX) -c -o $@ $<

Test.o: Test.cpp
	$(CXX) -c -o $@ $<	

clean:
	 rm -f main  test *.o
