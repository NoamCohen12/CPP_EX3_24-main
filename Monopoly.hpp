#include "DevCard.hpp"
#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP
class Monopoly : public DevCard {
    virtual string type() const override;
    virtual void play_card(Catan& catan, Player& player )override;
};
#endif