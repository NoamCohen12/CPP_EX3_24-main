#include "Catan.hpp"
#include "DevCard.hpp"
#include "Player.hpp

string Road_Building::type() {
    return "Road_Building";
}
void Road_Building::play_card(Catan& catan, Player& player) {
    int road1, road2;
    cout << "Choose the first road to build: " << endl;
   // catan.which_road();
    road1 = player.readValidInt();
    while (road1 < 1 || road1 > 72) {
       // catan.which_road();
        cout << "Invalid input. Please enter a number between 1 and 72." << endl;
        road1 = player.readValidInt();
    }
    
}