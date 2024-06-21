# CPP_EX3_24 - Catan


## Author
- [Noam Cohen]
- Email: Noam12345002@gmail.com

## Catan - the game

The whole game is played through the terminal and depends on inputs(INT) from the user

In addition, a picture of the board is attached GUI

my game is similar to the original game but in a simpler version for example

The game is played between 3 players 

all the project The entire game was written in C++

# game logic

In the first round each player taking turns (determined at random)

And there are 2 villages and 2 roads

At the end of the turns, resources are distributed to the players according to the location of the villages

by `start_game(game_board)` function

in most rounds each player in turn is given choices by `during_game(p1, p2, p3, game_board)` function




# board structure
The board is made of 19 hexagons

Each hexagon is made up of 6 vertices and 6 sides

the class are at `Hexagon.cpp`:
1.`Hexagon`
2.`Edge`- a edge holds the two vertices of which it is a part
3.`Vertex` - a vertex holds the edges (2 or 3) of which it is a part

All board members are numbered with a unique number(ID)

According to my decision and the whole game is based on these decisions


there are six resources: WOOD , WHITE_STONE , RED_STONE , SHEEP , HAY and DESERT.

in start game each hexagon randomly receives a resource and a number 

randomly by `rand()` and `srand()` functions.


# Tests
My code was checked with many tests in `Test.cpp` with the `make test` command.
and `make valgrind` To check for memory leaks.

# type of gui 

there is picture of board in `board.jpj`
and during the game, emojis are used for pleasant use

# Development cards - inheritance

The father's department is `DevCard.hpp`

and there are five Development cards that represent by Inheriting classes
1.`knight`-
2.`Monopoly` -
3.
4.
5.
