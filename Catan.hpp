#ifndef CATAN_HPP
#define CATAN_HPP
#include "player.hpp"
#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
const int NUM_RESOURCES = 19;

class Catan
{

private:
    Hex *hex[NUM_RESOURCES];
    Player *players[3];

public:
    Catan( Player &p1, Player &p2, Player &p3);
    void order_resources();
}
#endif