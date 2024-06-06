#include "Player.hpp"

Player::Player(std::string playerName, int playerColor) {
    name = playerName;
    color = playerColor;
    points = 0;
    my_assets = {0};
    turn = 0;
    knights = 0;
    resource_cards[WOOD] = 0;
    resource_cards[WHITE_STONE] = 0;
    resource_cards[RED_STONE] = 0;
    resource_cards[SHEEP] = 0;
    resource_cards[HAY] = 0;
    resource_cards[DESERT] = -1;
}

int Player::rolldice(board game_board, Catan catan) {
    srand(time(0));  // use current time as seed for random generator
    int randNum = rand() % (MAX - MIN + 1) + MIN;
    std::cout << "you get : " << randNum << std::endl;

    if (randNum == 7) {
        std::cout << "Change the theif's location" << std::endl;
    }
    catan.add_resources_for_all(randNum, game_board);
    return randNum;
}
// TODO: check if the vertex next to empty
void Player::buy_town(int idHex, int idVertex, board game_board) {
    // check if the player have enough resources
    if (resource_cards[WOOD] >= 1 && resource_cards[RED_STONE] >= 1 && resource_cards[HAY] >= 1 && resource_cards[SHEEP] >= 1) {
        // check if the player have a town in the same vertex
        Vertex *temp = game_board.get_board()[idHex]->get_vertex(idVertex);
        if (temp != NULL) {  // if the vertex is exist
            if (temp->get_color() == -1) {
                // build the town
                temp->set_town();
                temp->set_color(this->color);
                resource_cards[WOOD] -= 1;
                resource_cards[RED_STONE] -= 1;
                resource_cards[HAY] -= 1;
                resource_cards[SHEEP] -= 1;
                this->points += 1;
                cout << "you build a town in vertex " << idVertex << " in hexagon " << idHex << endl;
            } else {
                cout << "you can't build a town in this  is bought  " << endl;
            }
        } else {
            cout << "the vertex is not exist" << endl;
        }
    } else {
        cout << "you don't have enough resources" << endl;
    }
}
void Player::buy_city(int idHex, int idVertex, board game_board) {
    // check if the player have enough resources
    if (resource_cards[WHITE_STONE] >= 3 && resource_cards[HAY] >= 2) {
        // check if the player have a town in the same vertex
        Vertex *temp = game_board.get_board()[idHex]->get_vertex(idVertex);
        if (temp != NULL) {  // if the vertex is exist
            if (temp->get_color() == this->color) {
                if (temp->get_hasCity()) {
                    // build the town
                    temp->delete_town();
                    temp->set_city();
                    resource_cards[WHITE_STONE] -= 3;
                    resource_cards[HAY] -= 2;
                    this->points += 1;
                    cout << "you build a city in vertex " << idVertex << " in hexagon " << idHex << endl;

                } else {
                    cout << "you can't build a city in this vertex before you build town" << endl;
                }
            } else {
                cout << "you can't build a city in this vertex because The place is occupied" << endl;
            }
        } else {
            cout << "the vertex is not exist" << endl;
        }
    } else {
        cout << "you don't have enough resources" << endl;
    }
}

// TODO: check if the edge next to empty or in vertix have town or city in my color
void Player::buy_road(int idHex, int idEdge, board game_board) {
    // check if the player have enough resources
    if (resource_cards[WOOD] >= 1 && resource_cards[RED_STONE] >= 1) {
        // check if the player have a town in the same vertex
        Edge *temp = game_board.get_board()[idHex]->get_edge(idEdge);
        if (temp != NULL) {  // if the vertex is exist
            if (temp->get_color() == -1) {
                // build the town
                temp->set_color(this->color);
                resource_cards[WOOD] -= 1;
                resource_cards[RED_STONE] -= 1;
                cout << "you build a road in edge " << idEdge << " in hexagon " << idHex << endl;
            } else {
                cout << "you can't build a road in this edge because The place is occupied" << endl;
            }
        } else {
            cout << "the edge is not exist" << endl;
        }
    } else {
        cout << "you don't have enough resources" << endl;
    }
}

void Player::add_resource(int resource) {
    resource_cards[resource] += 1;
}
string Player::get_name() {
    return this->name;
}

// difult destructor
Player::~Player() {
}
void Player::set_turn(int turn) {
    this->turn = turn;
}
void Player::set_town_start(board game_board, int idHex, int idVertex) {
    // check if the player have a town in the same vertex
    Vertex *temp = game_board.get_board()[idHex]->get_vertex(idVertex);
    if (temp != NULL) {  // if the vertex is exist
        if (temp->get_color() == -1) {
            // build the town
            temp->set_town();
            temp->set_color(this->color);
            this->points += 1;
            cout << "you build a town in vertex " << idVertex << " in hexagon " << idHex << endl;
        } else {
            cout << "you can't build a town in this  is bought  " << endl;
        }
    } else {
        cout << "the vertex is not exist" << endl;
    }
}
void Player::set_path_start(board game_board, int idHex, int idVertex) {
    // check if the player have a town in the same vertex
    Vertex *temp = game_board.get_board()[idHex]->get_vertex(idVertex);
    if (temp != NULL) {  // if the vertex is exist
        if (temp->get_color() == -1) {
            // build the town
            temp->set_town();
            temp->set_color(this->color);
            cout << "you build a town in vertex " << idVertex << " in hexagon " << idHex << endl;
        } else {
            cout << "you can't build a town in this  is bought  " << endl;
        }
    } else {
        cout << "the vertex is not exist" << endl;
    }
}
//TODOOOOO finish 
boll Player::check_vertex_valid(board game_board, int idHex, int idVertex) {
    Vertex *temp = game_board.get_board()[idHex]->get_vertex(idVertex);
    int id = temp->get_id();
    int size = temp->get_edges().size();
    for (int i = 0; i < size; i++) {
        Edge *temp_edge = temp->get_edges()[i];
        for (int j = 0; j < 2; j++) {
            if (!(temp_edge->get_vertexs()[j]->get_id() != id)) {
                if (temp_edge->get_color() == this->color) {
                    return true;
                }
            }
        }
    }
}
