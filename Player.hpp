#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <time.h>

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Hexagon.cpp"
#include "Board.hpp"
using namespace std;
#define RED 0
#define BLUE 1
#define ORANGE 2
#define MAX 12
#define MIN 2
class Board; // Forward declaration

class Catan;
class Player {
   private:
    int color;
    string name;
    int points;
    // map of resorces
    map<int, int> resource_cards;
    //   map<DevCard, int> development_cards;
    map<string, int> my_devCards;
    string *my_assets;  // town or city
    int knights;

   public:
    Player(string playerName, int playerColor);
    string get_name();
    int get_points();
    int rolldice(Board &game_board, Catan &catan);
    ~Player();
    void buy_town(int idHex, int idVertex, Board &game_board);
    void buy_city(int idHex, int idVertex, Board &game_board);
    void buy_road(int idHex, int idEdge, Board &game_board);
    void buy_dev_card(Board &game_board);
    int get_color() {
        return color;
    }

    void add_resource(int resource);
    void add_resource_start(Board &game_board);
    int set_town_start(int idHex ,int idVertex,Board &game_board );
    int set_path_start(int idHex, int idEdge,Board &game_board);
    bool check_vertex_valid_start(Board &game_board, int idHex, int idVertex);
    bool check_vertex_valid_City(Board &game_board, int indexHex, int indexVertex);
bool check_vertex_valid_during (Board &game_board, int indexHex, int indexVertex);

    bool check_edge_valid(Board &game_board, int idEdge);//check the diffrent between the two
bool check_edge_valid_during(Board &game_board, int indexEdge);

    bool gt_seven();
    int drop_resource(int resource);
    int how_many_resources();
    //void use_dev_card(string type);
    bool check_ength_resource(int optionts);
    int get_count_resource_type(int resource);
    int readValidInt();


pair<map<int, int>, map<int, int>> trade_player();
    void add_knight() {
        knights++;
    }
    void add_points() {
        points +=1;
    }

    // print
    int which_dev_card();
    void print_my_resource();
};

#endif  // PLAYER_HPP
