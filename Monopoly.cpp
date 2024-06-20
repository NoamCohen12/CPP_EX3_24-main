#include "Catan.hpp"
#include "DevCard.hpp"
#include "Player.hpp"
string Monopoly::type() const {
    return "Monopoly";
}
void Monopoly::play_card(Catan& catan, Player& player) {
      map<int, string> resourceEmojis = {
        {1, "🌲"}, // WOOD
        {4, "🐑"}, // SHEEP
        {2, "⚪"}, // WHITE_STONE
        {5, "🌾"}, // HAY
        {3, "🔴"}  // RED_STONE
    };
    cout << "Choose a resource to monopolize" << endl;
    int count;
    int resource;
    resource = catan.readValidInt();
    while (resource < 1 || resource > 5) {
        cout << "Invalid input. Please enter a number between 1 and 5." << endl;
        resource = catan.readValidInt();
    }
    Player players* = catan.get_players();
    for (int i = 0; i < 3; i++) {
        if (players[i].get_name() != player.get_name()) {
            count = players[i].get_count_resource_type(resource);
            if (count > 0) {
                cout << palyer.get_name() << " has taken all of " << players[i].get_name() << "'s " << resourceEmojis[resource] << "'s" << endl;
                for (size_t k = 0; k < count; k++) {
                    player.add_resource(resource);
                    players[i].drop_resource(resource);
                }
            }
        }
    }
}

