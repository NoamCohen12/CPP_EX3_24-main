#include "Player.hpp"
using namespace std;
//difult constructor
Player::Player ()
{
    this->name = " ";
    this->color = 0;
    this->points = 0;
    this->resource_cards = new int[5];
    this->my_assets = new string[15];
    this->turn = 0;
}

Player::Player(std::string name, int color)
{
    this->name = name;
    this->color = color;
    this->points = 0;
    this->resource_cards = new int[5];
    this->my_assets = new string[15];
    this->turn = 0;
}

int Player::rolldice()
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
 //difult destructor
Player::~Player(){
    delete[] resource_cards;
    delete[] my_assets;
}
void Player::set_turn(int turn)
{
    this->turn = turn;
}