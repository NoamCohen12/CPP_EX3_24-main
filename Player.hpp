#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <vector>
#include "Hexagon.cpp"
#include <map>
#include "board.hpp"
#include "Catan.hpp"


using namespace std;
#define RED 0
#define BLUE 1
#define ORANGE 2
#define MAX 12
#define MIN 2

class Player
{
private:
    int color;
    string name;
    int turn;
    int points;
    //map of resorces
    map<int, int> resource_cards;
    string *my_assets; // town or city
    int knights;

public:
    Player(string playerName, int playerColor);
    string get_name();
    bool get_turn();
    void set_turn(int turn);
    int rolldice(board game_board,Catan catan);
    ~Player();
    void buy_town(int idHex,int idVertex,board game_board);
    void buy_city(int idHex,int idVertex,board game_board);
    void buy_road(int idHex,int idEdge,board game_board);
    void add_resource(int resource);


};

#endif // PLAYER_HPP
