#include <iostream>

#include "Catan.hpp"
#include "Hexagon.cpp"
#include "Player.hpp"
using namespace std;

int main() {
    Board game_board;
    Player p1("Bar", RED);
    Player p2("Noam", BLUE);
    Player p3("Vogdan", ORANGE);
    Catan catan(p1, p2, p3, game_board);  // start the game
}