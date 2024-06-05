#include "player.hpp"
//difult constructor
Player::Player ()
{
    this->name = " ";
    this->color = 0;
    this->point = 0;
    this->resource_cards = new int[5];
    this->my_assets = new string[15];
    this->turn = 0;
}

Player::Player(string name, int color)
{
    this->name = name;
    this->color = color;
    this->point = 0;
    this->resource_cards = new int[5];
    this->my_assets = new string[15];
    this->turn = 0;
}

int rolldice()
{
    srand(time(0)); // use current time as seed for random generator
    int randNum = rand() % (MAX - MIN + 1) + MIN;
    std::cout << "you get : " << randNum << std::endl;

    if (randNum == 7)
    {
    std::cout << "Change the theif's location" << std::endl;

    }

    return randNum;
}