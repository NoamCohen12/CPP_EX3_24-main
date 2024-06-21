#include "Knight.hpp"

#include "Catan.hpp"
#include "DevCard.hpp"
#include "Player.hpp"

 string Knight::type() const {
    return "Knight";
}
 void Knight::play_card(Catan& catan, Player& player)  {
    player.add_knight();
    if(player.get_knights() == 3){
        player.add_points();
    }
}
