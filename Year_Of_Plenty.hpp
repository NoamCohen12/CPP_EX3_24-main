#ifndef YEAR_OF_PLENTY_HPP
#define YEAR_OF_PLENTY_HPP

#include "DevCard.hpp"

class Monopoly : public DevCard {
    virtual string type() override;
    virtual void play_card(Catan& catan, Player& player ) = 0;
};
#endif // YEAR_OF_PLENTY_HPP