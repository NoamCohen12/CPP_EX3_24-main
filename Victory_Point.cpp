#include "Catan.hpp"
#include "DevCard.hpp"
#include "Player.hpp"
#include "Victory_Point.hpp" 
string Victory_Point::type() const {
    return "Victory_Point";
}
void Victory_Point::play_card(Catan& catan, Player& player) {
    player.add_points();
    cout<<"You have played a Victory Point card. You now have "<<player.get_points()<<" points."<<endl;
}