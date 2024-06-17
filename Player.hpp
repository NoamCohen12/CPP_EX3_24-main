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
    // int turn;
    int points;
    // map of resorces
    map<int, int> resource_cards;
    //   map<devCard, int> development_cards;
    map<string, int> my_devCards;
    string *my_assets;  // town or city
    int knights;

   public:
    Player(string playerName, int playerColor);
    string get_name();
    // bool get_turn();
    int get_points();
    // void set_turn(int turn);
    int rolldice(board &game_board, Catan &catan);
    ~Player();
    void buy_town(int idHex, int idVertex, board &game_board);
    void buy_city(int idHex, int idVertex, board &game_board);
    void buy_road(int idHex, int idEdge, board &game_board);
    void buy_dev_card(board &game_board);
    int get_color() {
        return color;
    }

    void add_resource(int resource);
    void add_resource_start(board &game_board);
    int set_town_start(board &game_board, int idHex, int idVertex);
    int set_path_start(board &game_board, int idHex, int idVertex);
    bool check_edge_valid(board &game_board, int idEdge);
    bool check_vertex_valid(board &game_board, int idHex, int idVertex);
    bool gt_seven();
    int drop_resource(int resource);
    int how_many_resources();
    void use_dev_card(string type);
    bool check_ength_resource(int optionts);
    int get_count_resource_type(int resource);
    bool check_vertex_valid_City(board &game_board,int indexHex,int indexVertex);



    // print
    int which_dev_card();

    void print_my_resource();
};

#endif  // PLAYER_HPP
