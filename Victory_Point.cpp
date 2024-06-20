#include "Catan.hpp"
#include "DevCard.hpp"
#include "Player.hpp"
string Victory_point::type() const {
    return "Victory_point";
}
void Victory_point::play_card(Catan& catan, Player& player) {
    player.add_points();
    cout<<"You have played a Victory Point card. You now have "<<player.get_points()<<" points."<<endl;
}