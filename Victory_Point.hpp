#include "DevCard.hpp"
#ifndef VICTORY_POINT_HPP
#define VICTORY_POINT_HPP
class Victory_Point : public DevCard {
    virtual string type() const override;
    virtual void play_card(Catan& catan, Player& player ) override;
};
#endif