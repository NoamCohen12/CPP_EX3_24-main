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


using namespace std;
#define RED 1
#define BLUE 2
#define ORANGE 3
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

public:
    Player(string playerName, int playerColor);
    string get_name();
    bool get_turn();
    void set_turn(int turn);
    int rolldice();
    ~Player();
    void buy_town(int idHex,int idVertex,board game_board);

};

#endif // PLAYER_HPP
