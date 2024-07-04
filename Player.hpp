#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <time.h>

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Board.hpp"
#include "Hexagon.cpp"
using namespace std;
#define RED 0
#define BLUE 1
#define ORANGE 2
#define MAX 12
#define MIN 2
class Board;  // Forward declaration

class Catan;
class Player {
   private:
    string name;
    int color;
    int points;
    int knights;

    // map of resorces
    map<int, int> resource_cards;
    map<string, int> devCards_count;
    // vector of dev cards
    vector<unique_ptr<DevCard>> devCards;

   public:
    // Constructor/Destructor
    Player(string playerName, int playerColor);
    ~Player();
    // buy functions
    void buy_village(int idHex, int idVertex, Board &game_board);
    void buy_city(int idHex, int idVertex, Board &game_board);
    void buy_road(int idHex, int idEdge, Board &game_board);
    void buy_dev_card(Board &game_board);

    // start functions
    int rolldice(Board &game_board, Catan &catan);
    void add_resource(int resource);
    void add_resource_start(Board &game_board);
    int set_village_start(int idHex, int idVertex, Board &game_board);
    int set_path_start(int idHex, int idEdge, Board &game_board);
    // check functions
    bool check_vertex_valid_start(Board &game_board, int idHex, int idVertex);
    bool check_vertex_valid_City(Board &game_board, int indexHex, int indexVertex);
    bool check_vertex_valid_during(Board &game_board, int indexHex, int indexVertex);
    bool check_edge_valid_start(Board &game_board, int idEdge);
    bool check_edge_valid_during(Board &game_board, int indexEdge);
    bool check_vertex_for_choose(Board &game_board, int idHex, int idVertex);
    bool check_enough_resource(int optionts);
    int readValidInt();
    bool gt_seven();

    // dev card functions
    int how_many_devCards();
    void use_dev_card(Catan &catan, int flag);
    pair<map<string, int>, map<string, int>> trade_DevCards_player();
    void add_dev_card_ptr(std::unique_ptr<DevCard> devCard);
    void add_devCard(string devCard);
    void drop_devCard(string devCard);
    int which_dev_card();

    // resource functions
    int drop_resource(int resource);
    int how_many_resources();
    pair<map<int, int>, map<int, int>> trade_resource_player();

    // setters
    void add_knight() {
        knights++;
    }
    void add_points() {
        points += 1;
    }

    // getters
    int get_knights() {
        return knights;
    }
    int get_points() {
        return points;
    }
    string get_name() {
        return name;
    }
    int get_color() {
        return color;
    }
    int get_count_resource_type(int resource) {
        return resource_cards[resource];
    }
    int get_count_devcard_type(string devCard) {
        cout << devCard << " " << devCards_count[devCard] << endl;
        return devCards_count[devCard];
    }

    // print functions
    void print_my_resource();
    void print_my_devCards();
    bool where_build_village(Board &game_board);
    void where_build_city(Board &game_board);
    void where_build_road(Board &game_board);
};

#endif  // PLAYER_HPP
