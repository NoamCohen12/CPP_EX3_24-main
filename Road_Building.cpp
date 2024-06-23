#include "Road_Building.hpp"

#include "Catan.hpp"
#include "DevCard.hpp"
#include "Player.hpp"

string Road_Building::type() const {
    return "Road_Building";
}

void Road_Building::play_card(Catan& catan, Player& player) {
    player.where_build_road(*(catan.get_board()));

    int idHex1, idHex2;
    int idEdge1, idEdge2;
    cout << "Choose the first Hexagon to build: " << endl;
    idHex1 = player.readValidInt();

    cout << "Choose the first Edge to build: " << endl;
    idEdge1 = player.readValidInt();

    while (idEdge1 < 0 || idEdge1 > 71 || !player.check_edge_valid_during(*(catan.get_board()), idEdge1) || idHex1 < 0 || idHex1 > 18) {    
        cout << "Invalid input:location of your Edge is not valid" << endl;
        cout << "Choose the first Hexagon to build more time: " << endl;
        idHex1 = player.readValidInt();
        cout << "Choose the first Edge to build more time: " << endl;
        idEdge1 = player.readValidInt();
    }
    Edge* temp1 = catan.get_board()->get_edge_from_board(idEdge1);
    temp1->set_color(player.get_color());
    cout << "You built a road on edge " << idEdge1 << " in hexagon " << idHex1 << endl;

    // Repeat the process for the second road
    cout << "Choose the second road to build: " << endl;
    idHex2 = player.readValidInt();

    cout << "Choose the second Edge to build: " << endl;
    idEdge2 = player.readValidInt();

    while (idEdge2 < 1 || idEdge2 > 72 || !player.check_edge_valid_during(*(catan.get_board()), idEdge2) || idHex2 <= 0 || idHex2 >= 18) {        cout << "Invalid input:location of your Edge is not valid" << endl;
        cout << "Choose the second Hexagon to build more time: " << endl;
        idHex2 = player.readValidInt();
        cout << "Choose the second Edge to build more time: " << endl;
        idEdge2 = player.readValidInt();
    }
    Edge* temp2 = catan.get_board()->get_edge_from_board(idEdge2);
    temp2->set_color(player.get_color());
    cout << "You built a road on edge " << idEdge2 << " in hexagon " << idHex2 << endl;
}