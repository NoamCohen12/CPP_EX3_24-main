#ifndef CATAN_HPP
#define CATAN_HPP
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iostream>
#include <string>
#include "Board.hpp"
#include "Hexagon.cpp"
#include "Player.hpp"
#define NUM_HEX 19
#define NUM_RESOURCES 19
class Player;
using namespace std;


class Catan {
   private:
    Player *players[3];
    Player *players_turns[3];
    Board *game_board;

   public:
    Catan(Player &p1, Player &p2, Player &p3, Board &game_board);
    Catan(Player &p1, Player &p2, Player &p3, Board &game_board ,int flag);//for testing
//functions of start the game
    void start(Player &p1, Player &p2, Player &p3, Board &game_board);//for testing
    void order_resources(Board &game_board);
    void start_game(Board &game_board);//the one round of the game
    void order_number(Board &game_board);
    void add_resources_for_all(int dice, Board &game_board);//add resources for all the players in the first round
    void seven_case();//if the dice is 7
    void which_resource();//print the resource that the player get
    void during_game(Player &p1, Player &p2, Player &p3, Board &game_board);  // TODO
    bool has_winner();//check if there is a winner
    void order_turns(Player &p1, Player &p2, Player &p3);//order the turns of the players
    void trade(Player &player);//trade between the players
    void chose_option(Player &player, Board &game_board);//the player chose the option during all the game 

    int readValidInt();//read a valid int
    bool check_location_hex(Board &game_board, int indexHex,Player &player);//check if the location of the hex is valid
    //getters
    Player**get_players() {
        return players;
    }
    Board *get_board() {
        return game_board;
    }
};
#endif