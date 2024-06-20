#include "Catan.hpp"
#include "DevCard.hpp"
#include "Player.hpp"
string Year_Of_Plenty::type() const {
    return "Year_Of_Plenty";
}
void Year_Of_Plenty::play_card(Catan& catan, Player& player) {
    map<int, string> resourceEmojis = {
        {1, "🌲"},  // WOOD
        {4, "🐑"},  // SHEEP
        {2, "⚪"},  // WHITE_STONE
        {5, "🌾"},  // HAY
        {3, "🔴"}   // RED_STONE
    };
    int resource;
    for (size_t i = 0; i < 2; i++) {
        cout << "Choose a resource to monopolize: " << endl;
        catan.which_resource();
        resource = player.readValidInt();
        while (resource < 1 || resource > 5) {
            catan.which_resource();
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            resource = player.readValidInt();
        }
        player.add_resource(resource);
        cout << "You taken one of: " << resourceEmojis[resource] << endl;
    }
}
