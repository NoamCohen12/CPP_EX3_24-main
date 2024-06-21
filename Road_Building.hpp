#ifndef ROAD_BUILDING_HPP
#define ROAD_BUILDING_HPP
#include "DevCard.hpp"

class Road_Building : public DevCard {
    virtual string type() const override;;
    virtual void play_card(Catan& catan, Player& player ) override;
};
#endif 