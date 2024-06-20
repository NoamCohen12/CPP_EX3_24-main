#ifndef DEVCARD_HPP
#define DEVCARD_HPP
#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Catan;
class Player;

class DevCard {
public:
    // Pure virtual function making this class abstract
    virtual string type() const = 0;
     virtual void play_card(Catan& catan, Player& player ) = 0;
    virtual ~DevCard() = default;      // Virtual destructor
};
#endif // DEVCARD_HPP