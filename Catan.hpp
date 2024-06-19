#ifndef CATAN_HPP
#define CATAN_HPP
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iostream>
#include <string>

#include "Hexagon.cpp"
#include "Player.hpp"
#include "board.hpp"
#define NUM_HEX 19
#define NUM_RESOURCES 19
class Player;
using namespace std;

// Forward declaration of Player

class Catan {
   private:
    Player *players[3];
    Player *players_turns[3];
    board *game_board;

   public:
    Catan(Player &p1, Player &p2, Player &p3, board &game_board);
    void start(Player &p1, Player &p2, Player &p3, board &game_board);

    void order_resources(board &game_board);
    void start_game(board &game_board);
    void order_number(board &game_board);
    void add_resources_for_all(int dice, board &game_board);
    void seven_case();
    void which_resource();
    void during_game(Player &p1, Player &p2, Player &p3, board &game_board);  // TODO
    bool has_winner();
    bool check_location_hex(int index);
    void order_turns(Player &p1, Player &p2, Player &p3);
    void trade(Player &player);

    void chose_option(Player &player, board &game_board);

    int convert_int_fromstrring(string resource);
    int readValidInt();
    bool hwx_full(board &game_board , int indexHex);

};
#endif