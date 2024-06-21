#include "Monopoly.hpp"

#include "Catan.hpp"
#include "DevCard.hpp"
#include "Player.hpp"
string Monopoly::type() const {
    return "Monopoly";
}
// void Monopoly::play_card(Catan& catan, Player& player) {
//     map<int, string> resourceEmojis = {
//         {1, "🌲"},  // WOOD
//         {2, "⚪"},  // WHITE_STONE
//         {3, "🔴"},  // RED_STONE
//         {4, "🐑"},  // SHEEP
//         {5, "🌾"}   // HAY
//     };
//     cout << "Choose a resource to monopolize" << endl;
//     for (const auto& resource : resourceEmojis) {
//         std::cout << "for: " << resource.second << "click " << resource.first << endl;
//         ;  // Print the emoji
//     }
//     int count;
//     int resource;
//     resource = catan.readValidInt();
//     while (resource < 1 || resource > 5) {
//         cout << "Invalid input. Please enter a number between 1 and 5." << endl;
//         resource = catan.readValidInt();
//     }
//     Player* players = catan.get_players();
//     for (int i = 0; i < 3; i++) {
//         if (players[i].get_name() != player.get_name()) {
//             count = players[i].get_count_resource_type(resource);
//             if (count > 0) {
//                 cout << player.get_name() << " has taken all of " << players[i].get_name() << "'s " << resourceEmojis[resource] << "'s" << endl;
//                 for (size_t k = 0; k < count; k++) {
//                     player.add_resource(resource);
//                     players[i].drop_resource(resource);
//                 }
//             }
//         }
//     }
// }
void Monopoly::play_card(Catan& catan, Player& player) {
    player.print_my_resource();
    map<int, string> resourceEmojis = {
        {1, "🌲"},  // WOOD
        {2, "⚪"},  // WHITE_STONE
        {3, "🔴"},  // RED_STONE
        {4, "🐑"},  // SHEEP
        {5, "🌾"}   // HAY
    };
    cout << "Choose a resource to monopolize" << endl;
    for (const auto& resource : resourceEmojis) {
        std::cout << "for: " << resource.second << " click " << resource.first << endl;
    }

    int count;
    int resource;
    cout << "Reading resource choice from player..." << endl; // Debug
    resource = catan.readValidInt();
    while (resource < 1 || resource > 5) {
        cout << "Invalid input. Please enter a number between 1 and 5." << endl;
        resource = catan.readValidInt();
    }
    cout << "Resource chosen: " << resourceEmojis[resource] << endl; // Debug

    Player** players = catan.get_players();
    cout << "Iterating over players to monopolize resources..." << endl; // Debug
    for (int i = 0; i < 3; i++) {
                cout<< i << "iter"<<endl;

        cout << "Checking player: " << players[i]->get_name() << endl; // Debug
        cout<<"vfrvn"<<endl;
        if (player.get_name() != players[i]->get_name()) {
            count = players[i]->get_count_resource_type(resource);
            cout << "Player " << players[i]->get_name() << " has " << count << " of resource " << resourceEmojis[resource] << endl; // Debug
            if (count > 0) {
                cout << player.get_name() << " has taken all of " << players[i]->get_name() << "'s " << resourceEmojis[resource] << endl;
                for (size_t k = 0; k < count; k++) {
                    player.add_resource(resource);
                    players[i]->drop_resource(resource);
                }
            }
            else{
                cout << "Player " << players[i]->get_name() << " has no resources of type " << resourceEmojis[resource] << endl;}
        }
    }
        player.print_my_resource();

}