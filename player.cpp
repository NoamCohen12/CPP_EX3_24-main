#include <iostream>
#include <string>
using namespace std;
define RED 1
define BLUE 2
define ORANGE 3
class player
{
private:
    int color;
    string name;
    bool turn;
    int points;
    int *resource_cards;
    string *my_assets; // town or city

public:
    player();
    string get_name();
    bool get_turn();
    void set_symbol(string symbol);
    string get_symbol();
};