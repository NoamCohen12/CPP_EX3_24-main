#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <vector>
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
    vector<int> resource_cards;
    string *my_assets; // town or city

public:
    Player(string name, int color);
    Player();
    string get_name();
    bool get_turn();
    void set_turn(int turn);
    int rolldice();
    ~Player();

};

#endif // PLAYER_HPP
