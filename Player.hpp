#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <time.h>

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Catan.hpp"
#include "Hexagon.cpp"
#include "board.hpp"

using namespace std;
#define RED 0
#define BLUE 1
#define ORANGE 2
#define MAX 12
#define MIN 2

class Player {
   private:
    int color;
    string name;
    int turn;
    int points;
    // map of resorces
    map<int, int> resource_cards;
    string *my_assets;  // town or city
    int knights;

   public:
    Player(string playerName, int playerColor);
    string get_name();
    bool get_turn();
    void set_turn(int turn);
    int rolldice(board& game_board, Catan&catan);
    ~Player();
    void buy_town(int idHex, int idVertex, board &game_board);
    void buy_city(int idHex, int idVertex, board &game_board);
    void buy_road(int idHex, int idEdge, board &game_board);
    void add_resource(int resource);
    int set_town_start(board &game_board, int idHex, int idVertex);
    int set_path_start(board &game_board, int idHex, int idVertex);
    int check_edge_valid(board &game_board, int idHex, int idEdge);
    int check_vertex_valid(board &game_board, int idHex, int idVertex);
    bool gt_seven();
    int drop_resource(int resource);
int how_many_resources();





    //print
    void print_my_resource();

};

#endif  // PLAYER_HPP
