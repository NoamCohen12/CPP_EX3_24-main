#include "DevCard.hpp"
#ifndef KNIGHT_HPP
#define KNIGHT_HPP
class Knight : public DevCard {
    virtual string type() const override;
    virtual void play_card(Catan& catan, Player& player )override;
};
#endif