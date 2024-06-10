#ifndef CATAN_HPP
#define CATAN_HPP
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iostream>
#include <string>

#include "Hexagon.cpp"
#include "board.hpp"
#define NUM_HEX 19
#define NUM_RESOURCES 19

class Player;  // Forward declaration of Player

class Catan {
   private:
    Player *players[3];
    board *game_board;

   public:
    Catan(Player &p1, Player &p2, Player &p3, board &game_board);
    void order_resources(board &game_board);
    void start_game(board &game_board);
    void order_number(board &game_board);
    void add_resources_for_all(int dice, board &game_board);

};
#endif