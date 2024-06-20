#include "DevCard.hpp"

class Monopoly : public DevCard {
    virtual string type() override;
    virtual void play_card(Catan& catan, Player& player ) = 0;
};