#ifndef CATAN_HPP
#define CATAN_HPP
#include "player.hpp"
#include "Hexagon.hpp"
#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#define num_of_hex 19

class Catan
{

private:
    Hexagon *Hexagon[num_of_hex];
    Player *players[3];
    
public:
    Catan(Player &p1, Player &p2, Player &p3);
    void order_resources();
    void start_game();
    ~Catan();
};
#endif