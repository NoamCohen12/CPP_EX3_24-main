#include "Player.hpp"


Player::Player(std::string playerName, int playerColor) {
    name = playerName;
    color = playerColor;
    points = 0;
    my_assets = {0};
    turn = 0;
    resource_cards[WOOD] = 0;
    resource_cards[WHITE_STONE] = 0;
    resource_cards[RED_STONE] = 0;
    resource_cards[SHEEP] = 0;
    resource_cards[HAY] = 0;
    resource_cards[DESERT] = -1;
}

int Player::rolldice() {
    srand(time(0));  // use current time as seed for random generator
    int randNum = rand() % (MAX - MIN + 1) + MIN;
    std::cout << "you get : " << randNum << std::endl;

    if (randNum == 7) {
        std::cout << "Change the theif's location" << std::endl;
    }

    return randNum;
}
// check if vertex next to empty
void Player::buy_town(int idHex, int idVertex, board game_board) {
    // check if the player have enough resources
    if (resource_cards[WOOD] >= 1 && resource_cards[WHITE_STONE] >= 1 && resource_cards[HAY] >= 1 && resource_cards[SHEEP] >= 1) {
        // check if the player have a town in the same vertex
        Vertex *temp = game_board.get_board()[idHex]->get_vertex(idVertex);
        if (temp != NULL) {  // if the vertex is exist
            if (temp->get_color() == -1 || temp->get_color() == this->color) {
                // build the town
                temp->set_town();
                temp->set_color(this->color);
                resource_cards[WOOD] -= 1;
                resource_cards[WHITE_STONE] -= 1;
                resource_cards[HAY] -= 1;
                resource_cards[SHEEP] -= 1;
                this->points += 1;
                cout << "you build a town in vertex " << idVertex << " in hexagon " << idHex << endl;
            } else {
                cout << "you can't build a town in this vertex or the vertex is bought or you alrady buy " << endl;
            }
        } else {
            cout << "the vertex is not exist" << endl;
        }
    } else {
        cout << "you don't have enough resources" << endl;
    }
}

// difult destructor
Player::~Player() {
}
void Player::set_turn(int turn) {
    this->turn = turn;
}
