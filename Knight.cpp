#include "Knight.hpp"

#include "Catan.hpp"
#include "DevCard.hpp"
#include "Player.hpp"

 string Knight::type() const {
    return "Knight";
}
 void Knight::play_card(Catan& catan, Player& player)  {
    player.add_knight();
}
