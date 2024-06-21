#ifndef YEAR_OF_PLENTY_HPP
#define YEAR_OF_PLENTY_HPP

#include "DevCard.hpp"

class Year_Of_Plenty : public DevCard {
    virtual string type() const override;
    virtual void play_card(Catan& catan, Player& player ) override;
};
#endif // YEAR_OF_PLENTY_HPP