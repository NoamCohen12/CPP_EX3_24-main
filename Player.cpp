#include "Player.hpp"

#include <iostream>

Player::Player(std::string playerName, int playerColor) {
    name = playerName;
    color = playerColor;
    points = 0;
    my_assets = {0};
    knights = 0;
    resource_cards[WOOD] = 0;
    resource_cards[WHITE_STONE] = 0;
    resource_cards[RED_STONE] = 0;
    resource_cards[SHEEP] = 0;
    resource_cards[HAY] = 0;
    resource_cards[DESERT] = -1;
    my_devCards["knight"] = 0;
    my_devCards["roadBuilding"] = 0;
    my_devCards["yearOfPlenty"] = 0;
    my_devCards["monopoly"] = 0;
    my_devCards["victoryPoint"] = 0;
}
int Player::get_points() {
    return points;
}

int Player::rolldice(board &game_board, Catan &catan) {
    srand(time(0));  // use current time as seed for random generator
    int randNum = rand() % (MAX - MIN + 1) + MIN;
    std::cout << "you get in rolldice: " << randNum << std::endl;

    if (randNum == 7) {
        return 7;
    }
    catan.add_resources_for_all(randNum, game_board);
    return randNum;
}
// TODO: check if the vertex next to empty
void Player::buy_town(int idHex, int idVertex, board &game_board) {
    cout << "im buy town" << endl;

    // check if the player have a town in the same vertex
    Vertex *temp = game_board.get_board()[idHex].get_vertex_by_ID(idVertex);
    if (temp->get_color() == -1) {
        if (check_vertex_valid(game_board, idHex, idVertex)) {
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
    }
}
void Player::buy_city(int idHex, int idVertex, board &game_board) {
    // check if the player have a town in the same vertex
    Vertex *temp = game_board.get_board()[idHex].get_vertex_by_ID(idVertex);
    if (temp->get_color() == this->color) {
        if (temp->get_hasTown()) {
            if (check_vertex_valid_City(game_board, idHex, idVertex)) {
                // build the city
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
    }
}

// TODO: check if the edge next to empty or in vertix have town or city in my color
void Player::buy_road(int idHex, int idEdge, board &game_board) {
    // check if the player have a town in the same vertex
    Edge *temp = game_board.get_board()[idHex].get_edge(idEdge);
    if (check_edge_valid(game_board, idEdge)) {
        // build the town
        temp->set_color(this->color);
        resource_cards[WOOD] -= 1;
        resource_cards[RED_STONE] -= 1;
        cout << "you build a road in edge " << idEdge << " in hexagon " << idHex << endl;
    }
}

void Player::add_resource(int resource) {
    resource_cards[resource] += 1;
}

void Player::add_resource_start(board &game_board) {
    cout << "mu name :" << name << endl;
    cout << "my color:" << color << endl;
    for (size_t i = 0; i < 19; i++) {
        for (size_t j = 0; j < 6; j++) {
            int source = game_board.get_hexagons(i).get_resource_type();
            int color_vertex = game_board.get_hexagons(i).get_vertexs(j)->get_color();
            cout << "color_vertex:" << color_vertex << endl;
            cout << game_board.get_hexagons(i).get_vertexs(j)->get_id() << endl;
            if (color_vertex == this->color) {
                // Convert resource type to emoji
                string resourceEmoji;
                switch (source) {
                    case SHEEP:
                        resourceEmoji = "🐑";
                        break;
                    case WOOD:
                        resourceEmoji = "🌲";
                        break;
                    case HAY:
                        resourceEmoji = "🌾";
                        break;
                    case RED_STONE:
                        resourceEmoji = "🔴";
                        break;
                    case WHITE_STONE:
                        resourceEmoji = "⚪";
                        break;
                    case DESERT:
                        resourceEmoji = "🏜️";
                        break;
                    default:
                        resourceEmoji = "❓";
                }
                cout << name << " you get " << resourceEmoji << " (" << resource_cards[source] << ")" << endl;
                resource_cards[source] += 1;
            }
        }
    }
}

string Player::get_name() {
    return this->name;
}

// difult destructor
Player::~Player() {
}

/**
 * in the begining of the game the player can build a town in the vertex
 * and no sould refer to path
 */

int Player::set_town_start(board &game_board, int idHex, int idVertex) {
    // check if the player have a town in the same vertex
    Vertex *temp = game_board.get_board()[idHex].get_vertex_by_ID(idVertex);
    if (!temp) {
        return 0;
    }

    if (temp->get_color() == -1) {  // if the vertex is empty

        if (check_vertex_valid(game_board, idHex, idVertex)) {
            // build the town
            temp->set_town();
            cout << "my name is " << name << "and my color is" << color << endl;
            temp->set_color(this->color);
            cout << temp->get_color() << endl;
            this->points += 1;

            std::cout << "you build a town in vertex " << idVertex << " in hexagon " << idHex << std::endl;
            return 1;
        } else {
        }
    } else {
        std::cout << "you can't build a town in this is bought" << std::endl;
    }

    return 0;
}
int Player::set_path_start(board &game_board, int idHex, int idEdge) {
    // check if the player have a town in the same vertex

    Edge *temp = game_board.get_edge_new(idEdge);
    cout<<"temp:"<<temp->get_id()<<endl;
    if (!(check_edge_valid(game_board, idEdge))) {
        cout << "edge :" << temp->get_id() << "not valid" << endl;
        return 0;
    }
    // build the town
    temp->set_road();
    temp->set_color(this->color);
    cout << "you build a path in Edge " << idEdge << " in hexagon " << idHex << endl;
    return 1;
}

bool Player::check_edge_valid(board &game_board, int idEdge) {
    if (idEdge < 0 || idEdge > 71) {
        return false;
    }

    Edge temp = game_board.get_edges()[idEdge];
    //cout<<"after temp"<<endl;
    if (temp.get_color() == -1) {
        for (int i = 0; i < 2; i++) {
           // cout << "after for" << endl;
            if (temp.get_vertexs()[i]->get_color() == this->color) {
                //cout << "i return true in check_edge_valid" << endl;
                return true;
            }
        }
    } else {
        cout << "You can't build a path here; it's already owned." << endl;
    }
    return false;
}

bool Player::check_vertex_valid(board &game_board, int idHex, int idVertex) {
    bool flag = false;
    // check if this idvertex is in the hexagon
    for (size_t i = 0; i < 6; i++) {
        // cout << "here" << endl;
        // cout << game_board.get_board()[idHex].get_vertexs(i)->get_id() << endl;
   //     cout << "flag is fff" << endl;
        if (game_board.get_board()[idHex].get_vertexs(i)->get_id() == idVertex) {
            flag = true;
           // cout<<"flag is true"<<endl;
            break;
        }
        
    }
    if(flag == false){
            return false;
        }
    if (game_board.get_board()[idHex].get_vertex_by_ID(idVertex)->get_color() != -1) {
        // cout<<"true/false:" <<(game_board.get_board()[idHex].get_vertexs(idVertex)->get_color() != -1)<<endl;

        cout << "get color:" << endl;
        cout << game_board.get_board()[idHex].get_vertex_by_ID(idVertex)->get_color() << endl;
        cout << "idHex" << idHex << endl;
        cout << "idVertex" << idVertex << endl;

        cout << "i return false in check_vertex_valid" << endl;
        return false;
    }

    Vertex *temp = game_board.get_board()[idHex].get_vertex_by_ID(idVertex);
    if (!temp) {
        return false;
    }

    int size = temp->get_edges().size();

    for (int i = 0; i < size; i++) {
        Edge *temp_edge = temp->get_edges()[i];  // edge from vertex

        for (int j = 0; j < 2; j++) {
            int adjacentVertexId = temp_edge->get_vertexs()[j]->get_id();

            if (adjacentVertexId != idVertex) {
                int adjacentVertexColor = temp_edge->get_vertexs()[j]->get_color();

                if (adjacentVertexColor != -1) {
                    flag = false;  // there is vertex with color in this edge
                }
            }
        }
    }
    return flag;
}

bool Player::check_vertex_valid_City(board &game_board, int indexHex, int indexVertex) {
    // we check if the vertex like my color and hastown
    if (game_board.get_hexagons(indexHex).get_vertex_by_ID(indexVertex)->get_color() == this->color && game_board.get_hexagons(indexHex).get_vertex_by_ID(indexVertex)->get_hasTown()) {
        return true;
    }
    return false;
}

bool Player::gt_seven() {
    int sum = resource_cards[WOOD] + resource_cards[WHITE_STONE] + resource_cards[RED_STONE] + resource_cards[SHEEP] + resource_cards[HAY];
    ;
    return sum >= 7;
}

void Player::print_my_resource() {
    cout << "📦 this is your resources:" << endl;
    cout << "🌾 your resources hay: " << resource_cards[HAY] << endl;
    cout << "🐑 your resources sheep: " << resource_cards[SHEEP] << endl;
    cout << "⚪ your resources white stone: " << resource_cards[WHITE_STONE] << endl;
    cout << "🔴 your resources red stone: " << resource_cards[RED_STONE] << endl;
    cout << "🌲 your resources wood: " << resource_cards[WOOD] << endl;
}

int Player::drop_resource(int resource) {
    if (resource_cards[resource] >= 1) {
        cout << "you drop " << resource << " resources" << endl;
        resource_cards[resource]--;
        return 1;
    }
    return 0;
}
int Player::how_many_resources() {
    int sum = resource_cards[WOOD] + resource_cards[WHITE_STONE] + resource_cards[RED_STONE] + resource_cards[SHEEP] + resource_cards[HAY];
    cout << "you have " << sum << " resources" << endl;
    return sum;
}

void Player::buy_dev_card(board &game_board) {
    resource_cards[WHITE_STONE] -= 1;
    resource_cards[HAY] -= 1;
    resource_cards[SHEEP] -= 1;
    cout << "you buy a dev card" << endl;
    string type = game_board.get_dev_card();
    if (type == " ") {
        cout << "there are no more dev cards" << endl;
        return;
    }
    my_devCards[type] += 1;
    cout << "you get a " << type << " card" << endl;
}
void Player::use_dev_card(string type) {
    if (my_devCards[type] >= 1) {
        my_devCards[type] -= 1;
        if (type == "knight") {
            knight k;
            k.use_card();
        } else if (type == "roadBuilding") {
            road_building r;
            r.use_card();
        } else if (type == "yearOfPlenty") {
            year_of_plenty y;
            y.use_card();
        } else if (type == "monopoly") {
            monopoly m;
            m.use_card();
        } else if (type == "victoryPoint") {
            victory_point v;
            v.use_card();
        }
        cout << "you use a " << type << " card" << endl;
    } else {
        cout << "you don't have this card" << endl;
    }
}
int Player::which_dev_card() {
    if (my_devCards["knight"] == 0 && my_devCards["roadBuilding"] == 0 && my_devCards["yearOfPlenty"] == 0 && my_devCards["monopoly"] == 0 && my_devCards["victoryPoint"] == 0) {
        cout << "you don't have any dev cards" << endl;
        return 0;
    }

    cout << "📦 this is your dev cards:" << endl;
    cout << "🛡️ your dev cards knight: " << my_devCards["knight"] << endl;
    cout << "🛣️ your dev cards roadBuilding: " << my_devCards["roadBuilding"] << endl;
    cout << "🌊 your dev cards yearOfPlenty: " << my_devCards["yearOfPlenty"] << endl;
    cout << "🏦 your dev cards monopoly: " << my_devCards["monopoly"] << endl;
    cout << "🏆 your dev cards victoryPoint: " << my_devCards["victoryPoint"] << endl;

    return 1;
}
bool Player::check_ength_resource(int optionts) {
    switch (optionts) {
        case 1: {  // town
            return ((resource_cards[WOOD] >= 1 && resource_cards[RED_STONE] >= 1 && resource_cards[HAY] >= 1 && resource_cards[SHEEP] >= 1));
        }

        case 2: {  // city
            return ((resource_cards[WHITE_STONE] >= 3 && resource_cards[HAY] >= 2));
        }
        case 3: {  // road
            return ((resource_cards[WOOD] >= 1 && resource_cards[RED_STONE] >= 1));
        }
        case 4: {  // dev card
            return ((resource_cards[WHITE_STONE] >= 1 && resource_cards[HAY] >= 1 && resource_cards[SHEEP] >= 1));
        }
    }
    return true;
}

int Player::get_count_resource_type(int resource) {
    return resource_cards[resource];
}

pair<map<string, int>, map<string, int>> Player::trade_player() {
    map<string, int> give;
    map<string, int> get;
    map<string, string> resourceEmojis = {
        {"WOOD", "🌲"},
        {"SHEEP", "🐑"},
        {"WHITE_STONE", "⚪"},
        {"wheat", "🌾"},
        {"RED_STONE", "🔴"}
    };

    string resource;
    int count;
    for(int i = 0; i < 5; i++) { // Five resources
        cout << "Enter the resource you want to give" << endl;
        cin >> resource;
        cout << "Enter the count of this resource you want to give" << endl;
        cin >> count;
        give[resource] = count;

        // Display resource with emoji if available
        if (resourceEmojis.find(resource) != resourceEmojis.end()) {
            cout << "You are giving " << count << " of " << resource << " " << resourceEmojis[resource] << endl;
        }

        cout << "Enter the resource you want to get" << endl;
        cin >> resource;
        cout << "Enter the count of this resource you want to get" << endl;
        cin >> count;
        get[resource] = count;

        // Display resource with emoji if available
        if (resourceEmojis.find(resource) != resourceEmojis.end()) {
            cout << "You are getting " << count << " of " << resource << " " << resourceEmojis[resource] << endl;
        }
    }

    return {give, get};
}