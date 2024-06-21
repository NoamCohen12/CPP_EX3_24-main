#include "Player.hpp"

#include <iostream>

#include "Board.hpp"
#include "Catan.hpp"  // Include Catan's full definition here
using namespace std;

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
    devCards_count["Knight"] = 0;
    devCards_count["Road_Building"] = 0;
    devCards_count["Year_Of_Plenty"] = 0;
    devCards_count["Monopoly"] = 0;
    devCards_count["Victory_Point"] = 0;
}
int Player::get_points() {
    return points;
}

int Player::rolldice(Board &game_board, Catan &catan) {
    srand(time(0));  // use current time as seed for random generator
    int randNum = rand() % (MAX - MIN + 1) + MIN;
    std::cout << "you get in rolldice: " << randNum << std::endl;

    if (randNum == 7) {
        return 7;
    }
    catan.add_resources_for_all(randNum, game_board);
    return randNum;
}

void Player::where_build_village(Board &game_board) {
    for (size_t i = 0; i < 19; i++) {
        for (size_t j = 0; j < 6; j++) {
            if (check_vertex_valid_during(game_board, i, j)) {
                cout << "you can build a town in hexagon " << i << " in vertex " << j << endl;
            }
        }
    }
}

// TODO: check if the vertex next to empty
void Player::buy_village(int idHex, int idVertex, Board &game_board) {
    cout << "im buy town" << endl;
    // check if the player have a town in the same vertex
    Vertex *temp = game_board.get_board()[idHex].get_vertex_by_ID(idVertex);
    if (temp->get_color() == -1) {
        if (check_vertex_valid_during(game_board, idHex, idVertex)) {
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
void Player::buy_city(int idHex, int idVertex, Board &game_board) {
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
void Player::where_build_road(Board &game_board) {
    for (size_t i = 0; i < 19; ++i) {
        for (size_t j = 0; j < 6; ++j) {
            int id = game_board.get_board()[i].get_edges(j)->get_id();
            if (check_edge_valid_during(game_board,id)) { // Assuming check_edge_valid_during now also accepts hexagon index
                cout << "You can build a road in hexagon " << i << " on edge " << id << "." << endl;
            }
        }
    }
}

// TODO: check if the edge next to empty or in vertix have town or city in my color
void Player::buy_road(int idHex, int idEdge, Board &game_board) {
    // check if the player have a town in the same vertex
    Edge *temp = game_board.get_board()[idHex].get_edge(idEdge);
    if (check_edge_valid_during(game_board, idEdge)) {
        // build the town
        cout << "you can buy" << endl;
        temp->set_color(this->color);
        resource_cards[WOOD] -= 1;
        resource_cards[RED_STONE] -= 1;
        cout << "you build a road in edge " << idEdge << " in hexagon " << idHex << endl;
    }
}

void Player::add_resource(int resource) {
    resource_cards[resource] += 1;
}

void Player::add_resource_start(Board &game_board) {
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

//(int idHex ,int idVertex,Board &game_board )
int Player::set_village_start(int idHex, int idVertex, Board &game_board) {
    // check if the player have a town in the same vertex
    Vertex *temp = game_board.get_board()[idHex].get_vertex_by_ID(idVertex);
    if (!temp) {
        cout << "temp is null" << endl;
        return 0;
    }

    if (temp->get_color() == -1) {  // if the vertex is empty
        cout << "temp color is -1" << endl;
        if (check_vertex_valid_start(game_board, idHex, idVertex)) {
            cout << "check_vertex_valid_start is true" << endl;
            // build the town
            temp->set_town();
            cout << "my name is " << name << "and my color is" << color << endl;
            temp->set_color(this->color);
            cout << temp->get_color() << endl;
            this->points += 1;

            std::cout << "you build a town in vertex " << idVertex << " in hexagon " << idHex << std::endl;
            return 1;
        } else {
            std::cout << "you can't build a town in this is not valid" << std::endl;
        }
    } else {
        std::cout << "you can't build a town in this is bought" << std::endl;
    }
    // cout << "return 0" << endl;
    return 0;
}
int Player::set_path_start(int idHex, int idEdge, Board &game_board) {
    // check if the player have a town in the same vertex
    cout << "*********************************" << endl;
    Edge *temp = game_board.get_edge_new(idEdge);
    cout << "temp:" << temp->get_id() << endl;
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

bool Player::check_edge_valid(Board &game_board, int idEdge) {
    if (idEdge < 0 || idEdge > 71) {
        return false;
    }
    Edge temp = game_board.get_edges()[idEdge];
    // cout<<"after temp"<<endl;
    if (temp.get_color() == -1) {
        for (int i = 0; i < 2; i++) {
            //   cout << "after for" << endl;
            if (temp.get_vertexs()[i]->get_color() == this->color) {
                //     cout << "i return true in check_edge_valid" << endl;
                return true;
            }
        }
    } else {
        cout << "You can't build a path here; it's already owned." << endl;
    }
    return false;
}

#include <iostream>  // Ensure this is included for cout

bool Player::check_vertex_valid_start(Board &game_board, int idHex, int idVertex) {
    bool flag = false;
    // std::cout << "Checking if vertex is valid..." << std::endl;

    // Check if this idVertex is in the hexagon
    for (size_t i = 0; i < 6; i++) {
        // std::cout << "Checking hexagon vertex: " << game_board.get_board()[idHex].get_vertexs(i)->get_id() << std::endl;
        if (game_board.get_board()[idHex].get_vertexs(i)->get_id() == idVertex) {
            flag = true;
            // std::cout << "Vertex found in hexagon." << std::endl;
            break;
        }
    }
    if (!flag) {
        std::cout << "Vertex not found in hexagon, returning false." << std::endl;
        return false;
    }

    // Check if the vertex is already occupied
    if (game_board.get_board()[idHex].get_vertex_by_ID(idVertex)->get_color() != -1) {
        std::cout << "Vertex is already occupied, returning false." << std::endl;
        return false;
    }

    Vertex *temp = game_board.get_board()[idHex].get_vertex_by_ID(idVertex);
    if (!temp) {
        std::cout << "Vertex pointer is null, returning false." << std::endl;
        return false;
    }

    // std::cout << "Checking edges connected to vertex..." << std::endl;
    int size = temp->get_edges().size();
    for (int i = 0; i < size; i++) {
        Edge *temp_edge = temp->get_edges()[i];  // Edge from vertex
                                                 // std::cout << "Checking edge " << temp_edge->get_id() << std::endl;

        for (int j = 0; j < 2; j++) {
            int adjacentVertexId = temp_edge->get_vertexs()[j]->get_id();
            // std::cout << "Checking adjacent vertex ID: " << adjacentVertexId << std::endl;

            if (adjacentVertexId != idVertex) {
                int adjacentVertexColor = temp_edge->get_vertexs()[j]->get_color();
                // std::cout << "Adjacent vertex color: " << adjacentVertexColor << std::endl;

                if (adjacentVertexColor != -1) {
                    flag = false;  // There is a vertex with color in this edge
                                   // std::cout << "Found colored adjacent vertex, setting flag to false." << std::endl;
                }
            }
        }
    }
    // std::cout << "Returning " << (flag ? "true" : "false") << std::endl;
    return flag;
}
bool Player::check_vertex_valid_during(Board &game_board, int indexHex, int indexVertex) {
    bool condition_one = false;
    bool condition_two = false;
    Vertex *vertex_first = game_board.get_board()[indexHex].get_vertex_by_ID(indexVertex);
    if (vertex_first == nullptr) {
        cout << "vertex is null" << endl;
        return false;
    }
    condition_one = check_vertex_valid_start(game_board, indexHex, indexVertex);

    if (condition_one == false) {
        cout << "vertex is not valid" << endl;
        return false;
    }
    condition_one = true;

    // check if there is path in my color
    for (size_t i = 0; i < vertex_first->get_edges().size(); i++) {
        if (vertex_first->get_edges()[i]->get_color() == this->color) {
            condition_two = true;
        }
    }
    if (condition_two == false) {
        // cout << "there is no path in my color" << endl;
    }
    return condition_one && condition_two;
}
// TODO NOT WORKING GOOD
bool Player::check_edge_valid_during(Board &game_board, int indexEdge) {
    // std::cout << "Checking edge validity for edge index: " << indexEdge << std::endl;

    bool first_condition = false;
    bool second_condition = false;

    Edge *edge = game_board.get_edge_new(indexEdge);
    if (edge == nullptr) {
        std::cout << "Edge is nullptr, returning false." << std::endl;
        return false;
    }
    // std::cout << "Edge color: " << edge->get_color() << std::endl;

    // check if the edge with vertex with my color
    if (edge->get_color() == -1) {
        for (size_t i = 0; i < 2; i++) {
            // std::cout << "Checking vertex " << i << " color: " << edge->get_vertexs()[i]->get_color() << std::endl;
            if (edge->get_vertexs()[i]->get_color() == this->color) {
                first_condition = true;
                //  std::cout << "First condition met at vertex " << i << std::endl;
            }
        }
    }

    // check if the edge is countinue of edge with same color
    for (size_t i = 0; i < 2; i++) {
        Vertex *vertex = edge->get_vertexs()[i];
        //  std::cout << "Checking edges connected to vertex " << i << std::endl;
        for (size_t j = 0; j < vertex->get_edges().size(); j++) {
            ///   std::cout << "Edge " << j << " color: " << vertex->get_edges()[j]->get_color() << std::endl;
            if (vertex->get_edges()[j]->get_color() == this->color) {
                second_condition = true;
                //   std::cout << "Second condition met at edge " << j << " connected to vertex " << i << std::endl;
            }
        }
    }

    // std::cout << "First condition: " << first_condition << ", Second condition: " << second_condition << std::endl;
    return first_condition || second_condition;
}
bool Player::check_vertex_valid_City(Board &game_board, int indexHex, int indexVertex) {
    // we check if the vertex like my color and hastown
    if (game_board.get_hexagons(indexHex).get_vertex_by_ID(indexVertex)->get_color() == this->color && game_board.get_hexagons(indexHex).get_vertex_by_ID(indexVertex)->get_hasTown()) {
        return true;
    }
    return false;
}
void Player::where_build_city(Board &game_board) {
    for (size_t i = 0; i < 19; i++) {
        for (size_t j = 0; j < 6; j++) {
            if (check_vertex_valid_City(game_board, i, j)) {
                cout << "you can build a city in hexagon " << i << " in vertex " << j << endl;
            }
        }
    }
}

bool Player::gt_seven() {
    int sum = resource_cards[WOOD] + resource_cards[WHITE_STONE] + resource_cards[RED_STONE] + resource_cards[SHEEP] + resource_cards[HAY];
    ;
    return sum >= 7;
}

void Player::print_my_resource() {
    cout << "📦 this is your resources:" << endl;
    cout << "1 " << "🌲 your resources wood: " << resource_cards[WOOD] << endl;
    cout << "2 " << "⚪ your resources white stone: " << resource_cards[WHITE_STONE] << endl;
    cout << "3 " << "🔴 your resources red stone: " << resource_cards[RED_STONE] << endl;
    cout << "4 " << "🐑 your resources sheep: " << resource_cards[SHEEP] << endl;
    cout << "5 " << "🌾 your resources hay: " << resource_cards[HAY] << endl;
}

int Player::drop_resource(int resource) {
    if (resource_cards[resource] >= 1) {
        cout << "taken from you " << resource << " resources" << endl;
        resource_cards[resource]--;
        return 1;
    }
    return 0;
}
int Player::how_many_devCards() {
    int sum = devCards_count["Knight"] + devCards_count["Road_Building"] + devCards_count["Year_Of_Plenty"] + devCards_count["Monopoly"] + devCards_count["Victory_Point"];
    cout << "you have " << sum << " dev cards" << endl;
    return sum;
}
int Player::how_many_resources() {
    int sum = resource_cards[WOOD] + resource_cards[WHITE_STONE] + resource_cards[RED_STONE] + resource_cards[SHEEP] + resource_cards[HAY];
    cout << "you have " << sum << " resources" << endl;
    return sum;
}

void Player::buy_dev_card(Board &game_board) {
    resource_cards[WHITE_STONE] -= 1;
    resource_cards[HAY] -= 1;
    resource_cards[SHEEP] -= 1;
    unique_ptr<DevCard> card = game_board.get_dev_card();
    if (!card) {
        cout << "Failed to get a development card. the deck is empty." << endl;
        return;
    }
    devCards.push_back(move(card));
    string type = card->type();
    devCards_count[type]++;
    cout << "you buy a " << type << "card" << endl;
}
// void Player::buy_dev_card(Board &game_board) {
//     cout << "Attempting to buy a development card..." << endl;

//     cout << "Current resources - White Stone: " << resource_cards[WHITE_STONE]
//          << ", Hay: " << resource_cards[HAY]
//          << ", Sheep: " << resource_cards[SHEEP] << endl;

//     resource_cards[WHITE_STONE] -= 1;
//     resource_cards[HAY] -= 1;
//     resource_cards[SHEEP] -= 1;

//     cout << "Resources after deduction - White Stone: " << resource_cards[WHITE_STONE]
//          << ", Hay: " << resource_cards[HAY]
//          << ", Sheep: " << resource_cards[SHEEP] << endl;

//     unique_ptr<DevCard> card = game_board.get_dev_card();
//     if (!card) {
//         cout << "Failed to get a development card. Check if the deck is empty." << endl;
//         return;
//     }

//     string type = card->type();
//     cout << "Received a " << type << " card." << endl;

//     devCards.push_back(move(card));
//     devCards_count[type]++;





//     cout << "Development card of type " << type << " successfully purchased." << endl;
//     cout << "Total " << type << " cards owned: " << devCards_count[type] << endl;
// }
void Player::use_dev_card(Catan &catan, int flag) {
    string type;
    switch (flag) {
        case 1:
            type = "Knight";
            break;
        case 2:
            type = "Road_Building";
            break;
        case 3:
            type = "Year_Of_Plenty";
            break;
        case 4:
            type = "Monopoly";
            break;
        case 5:
            type = "Victory_Point";
            break;
    }

    for (size_t i = 0; i < devCards.size(); i++) {
        if (devCards[i]->type() == type) {
            devCards[i]->play_card(catan, *this);
            cout << "you uesed at " << type << endl;
            devCards.erase(devCards.begin() + i);
            devCards_count[type]--;
        }
    }
}

int Player::which_dev_card() {
    cout << "📦 this is your dev cards:" << endl;
    if (devCards_count["Knight"] > 0) {
        cout<<"click 1 for " << "🛡️ your dev cards knight: " << devCards_count["Knight"] << endl;
    }
    if (devCards_count["Road_Building"] > 0) {
        cout << "click 2 for " << "🛣️ your dev cards roadBuilding: " << devCards_count["Road_Building"] << endl;
    }
    if (devCards_count["Year_Of_Plenty"] > 0) {
        cout << "click 3 for " << "🌊 your dev cards yearOfPlenty: " << devCards_count["Year_Of_Plenty"] << endl;
    }
    if (devCards_count["Monopoly"] > 0) {
        cout << "click 4 for " << "🏦 your dev cards monopoly: " << devCards_count["Monopoly"] << endl;
    }
    if (devCards_count["Victory_Point"] > 0) {
        cout << "click 5 for " << "🏆 your dev cards victoryPoint: " << devCards_count["Victory_Point"] << endl;
    }
    cout << "enter the number of the card you want to use or enter 6 for return" << endl;
    int num = readValidInt();
    
    if (num < 1 || num > 6) {
        cout << "invalid number" << endl;
        return 0;
    }

    switch (num) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;    
    }

    return 0;
}
bool Player::check_enough_resource(int optionts) {
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

pair<map<int, int>, map<int, int>> Player::trade_player() {
    map<int, int> give;
    map<int, int> get;
    map<int, string> resourceEmojis = {
        {1, "🌲"},  // WOOD
        {4, "🐑"},  // SHEEP
        {2, "⚪"},  // WHITE_STONE
        {5, "🌾"},  // HAY
        {3, "🔴"}   // RED_STONE
    };

    // Loop for resources to give
    for (auto it = resourceEmojis.begin(); it != resourceEmojis.end(); ++it) {
        int resource = it->first;
        string emoji = it->second;
        print_my_resource();
        cout << "For " << emoji << ", enter the count you want to give:" << endl;
        int count = readValidInt();
        give[resource] = count;
        cout << "You are giving " << count << " of " << emoji << endl;
    }

    // Loop for resources to get
    for (auto it = resourceEmojis.begin(); it != resourceEmojis.end(); ++it) {
        int resource = it->first;
        string emoji = it->second;
        print_my_resource();
        cout << "For " << emoji << ", enter the count you want to get:" << endl;
        int count = readValidInt();
        get[resource] = count;
        cout << "You are getting " << count << " of " << emoji << endl;
    }
    // print what i give and what i get
    cout << "You are giving:" << endl;
    for (auto it = give.begin(); it != give.end(); ++it) {
        cout << it->second << " of " << resourceEmojis[it->first] << endl;
    }

    cout << "You are getting:" << endl;
    for (auto it = get.begin(); it != get.end(); ++it) {
        cout << it->second << " of " << resourceEmojis[it->first] << endl;
    }
    return {give, get};
}

int Player::readValidInt() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please try again enter INT" << endl;
        } else {
            break;
        }
    }
    return input;
}