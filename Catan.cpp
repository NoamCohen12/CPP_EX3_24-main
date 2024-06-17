#include "Catan.hpp"

#include "Player.hpp"
#include "board.hpp"
#define WITHOUT_NUMBER -215151

Catan::Catan(Player &p1, Player &p2, Player &p3, board &game_board) {
    players[0] = &p1;
    players[1] = &p2;
    players[2] = &p3;
    order_resources(game_board);
    cout << "****************************************" << endl;
    order_number(game_board);
    order_turns(p1, p2, p3, game_board);
    start_game(game_board);
    during_game(p1, p2, p3, game_board);
}

void Catan::order_turns(Player &p1, Player &p2, Player &p3, board &game_board) {
    int randomIndex = rand() % 3;
    players_turns[randomIndex] = &p1;
    players_turns[(randomIndex + 1) % 3] = &p2;
    players_turns[(randomIndex + 2) % 3] = &p3;
}

void Catan::order_number(board &game_board) {
    int numbers[NUM_HEX - 1] = {10, 2, 9, 12, 6, 4, 10, 9, 11, 3, 8, 8, 3, 4, 5, 5, 6, 11};
    int count = 0;

    while (count < NUM_HEX - 1) {
        int randomIndex = rand() % (NUM_HEX - 1);  // Corrected to ensure it's within the array bounds

        if (numbers[randomIndex] != -1) {
            int number = numbers[randomIndex];

            if (game_board.get_board()[count].get_resource_type() == DESERT) {
                game_board.get_board()[count].set_number(WITHOUT_NUMBER);
                //      std::cout << "Hex " << count << " is a DESERT, setting number to WITHOUT_NUMBER" << std::endl;

            } else {
                game_board.get_board()[count].set_number(number);
                std::cout << "Hex " << count << " setting number to " << number << std::endl;
            }
            numbers[randomIndex] = -1;
            count++;
        }
    }
}
void ordrer_turns() {
}
void Catan::order_resources(board &game_board) {
    int resources[NUM_HEX] = {SHEEP, SHEEP, SHEEP, SHEEP, WOOD, WOOD, WOOD, WOOD, HAY, HAY, HAY, HAY, RED_STONE, RED_STONE, RED_STONE, WHITE_STONE, WHITE_STONE, WHITE_STONE, DESERT};
    int count = 0;

    srand(time(0));  // Seed the random number generator once

    while (count < NUM_HEX) {
        int randomIndex = rand() % NUM_HEX;
        if (resources[randomIndex] != 0) {
            int type = resources[randomIndex];
            game_board.get_board()[count].set_resource_type(type);
            // Convert resource type to emoji
            string resourceEmoji;
            switch (type) {
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
            cout << "hexagon " << count << " resource: " << resourceEmoji << " (" << type << ")" << endl;
            resources[randomIndex] = 0;
            count++;
        }
    }
}
// TODO path not next town cause to seg fault
void Catan::start_game(board &game_board) {
    
    for (size_t i = 0; i < 3; i++) {  // over on all players
        cout << "Welcome to Catan" << endl;
        int location_for_town = 0;
        int location_for_path = 0;
        int location_for_hex = 0;
        cout << "Hii " << players_turns[i]->get_name() << endl;
        for (size_t j = 0; j < 2; j++) {
            // TODO: check if the vertex next to empty
            std::cout << "Which hexagon do you want(between 0-18)? " << endl;
            std::cin >> location_for_hex;
            while (check_location_hex(location_for_hex) == false) {
                std::cout << "Invalid hexagon, please choose another hexagon(between 0-18)" << endl;
                std::cin >> location_for_hex;
            }
            std::cout << "this are your options:" << endl;
            for (size_t j = 0; j < 6; j++) {
                cout << j << "." << "vertexId:" << game_board.get_hexagons(location_for_hex).get_vertexs(j)->get_id() << endl;
            }

            std::cout << "Where vertex do you want to build town? " << endl;
            std::cin >> location_for_town;

            while ((players_turns[i]->check_vertex_valid(game_board, location_for_hex, location_for_town) == false)) {
                std::cout << "Invalid vertex, please choose another vertex" << endl;
                std::cout << "this are your options:" << endl;
                for (size_t j = 0; j < 6; j++) {
                    cout << j << "." << "vertexId:" << game_board.get_hexagons(location_for_hex).get_vertexs(j)->get_id() << endl;
                }
                std::cin >> location_for_town;
            }
            players_turns[i]->set_town_start(game_board, location_for_hex, location_for_town);

            std::cout << "this are your options:" << endl;
            // int id = game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges()[j]->get_id();
            int size = game_board.get_hexagons(location_for_hex).get_vertex_by_ID(location_for_town)->get_edges().size();
            for (size_t k = 0; k < size; k++) {
                cout << k << "." << "edgeId:" << game_board.get_hexagons(location_for_hex).get_vertex_by_ID(location_for_town)->get_edges()[k]->get_id() << endl;
            }

            std::cin >> location_for_path;
            while ((players_turns[i]->check_edge_valid(game_board, location_for_path) == false)) {
                std::cout << "Invalid edge, please choose another edge" << endl;
                std::cin >> location_for_path;
            }
cout<<"in Catan0"<<endl;
            players_turns[i]->set_path_start(game_board, location_for_hex, location_for_path);
            cout<<"in Catan1 after"<<endl;
            
        }
        
    }for (size_t i = 0; i < 3; i++) {
            cout << "my name outside" << players_turns[i]->get_name() << endl;
            players_turns[i]->add_resource_start(game_board);
        }
}

void Catan::add_resources_for_all(int dice, board &game_board) {
    for (int i = 0; i < NUM_HEX; i++) {
        int resource = game_board.get_board()[i].get_resource_type();
        if (game_board.get_board()[i].get_number() == dice) {  // if the number of the hexagon is equal to the dice
            for (int j = 0; j < 6; j++) {
                Vertex *temp = game_board.get_board()[i].get_vertexs(j);
                int color = temp->get_color();
                if (color != -1) {
                      cout << "Debug: Player " << players[color]->get_name() << " (Color: " << color << ") is receiving resource from vertex " << game_board.get_board()[i].get_vertexs(j)->get_id() << " of type " << resource << endl;

                    if (temp->get_hasTown()) {
                        players[color]->add_resource(resource);
                        cout << players[color]->get_name() << "my coloris:" <<color << " get 1 resuorce : " << game_board.get_board()[i].get_resource_type() << endl;
                    } else if (temp->get_hasCity()) {
                        players[color]->add_resource(resource);
                        players[color]->add_resource(resource);
                        cout << players[color]->get_name() << "my coloris:"<<color << " get 2 resuorce: " << game_board.get_board()[i].get_resource_type() << endl;
                    }
                }
            }
        }
    }
}

void Catan::which_resource() {
    cout << "In case you forgot these are the resources" << endl;
    cout << "1 is sheep" << endl;
    cout << "2 is wood" << endl;
    cout << "3 is hay" << endl;
    cout << "4 is red stone" << endl;
    cout << "5 is white stone" << endl;
}
void Catan::seven_case() {
    for (int i = 0; i < 3; i++) {
        if (players[i]->gt_seven()) {  // Assuming gt_seven() checks if player has more than 7 resources
            int resources_drop = players[i]->how_many_resources() / 2;
            // Fixed syntax error in cout statement
            cout << "Hi " << players[i]->get_name() << ", you have more than 7 resources, you need to drop " << resources_drop << " resources." << endl;
            players[i]->print_my_resource();
            for (int j = 0; j < resources_drop; j++) {
                int resource = 0;
                cout << "Choose the resource you want to drop:" << endl;
                which_resource();  // Assuming this function displays resource options
                cin >> resource;
                while (players[i]->drop_resource(resource) == 0) {
                    cout << "Choose one more time the resource you want to drop:" << endl;
                    cin >> resource;
                }
            }
        }
    }
}

void Catan::chose_option(Player &player, board &game_board) {
    cout << "Choose one of the following options:" << endl;
    cout << "1. buy town" << endl;
    cout << "2. buy city" << endl;
    cout << "3. buy road" << endl;
    cout << "4. buy dev card" << endl;
    cout << "5. use dev card" << endl;
    cout << "6 next turn" << endl;
    cout << "7 trade" << endl;
    int option;
    cin >> option;  // Corrected: Use >> for input
    switch (option) {
        case 1: {
            if (!(player.check_ength_resource(1))) {
                cout << "You don't have enough resources to buy a town" << endl;
                break;
            }

            int idHex, idVertex;
            cout << "Enter the hexagon id and the vertex id" << endl;
            cin >> idHex;
            cout << "Enter the vertex id" << endl;
            cin >> idVertex;
            player.buy_town(idHex, idVertex, game_board);
            break;
        }

        case 2: {
            if (!(player.check_ength_resource(2))) {
                cout << "You don't have enough resources to buy a city" << endl;
                break;
            }
            int idHex, idVertex;
            cout << "Enter the hexagon id and the vertex id" << endl;
            cin >> idHex;
            cout << "Enter the vertex id" << endl;
            cin >> idVertex;                               // Corrected: Use >> for input
            player.buy_city(idHex, idVertex, game_board);  // Corrected: Removed 'board &' from the argument
            break;
        }

        case 3: {
            if (!(player.check_ength_resource(3))) {
                break;
            }
            int idHex, idVertex;
            cout << "Enter the hexagon id and the vertex id" << endl;
            cin >> idHex;
            cout << "Enter the vertex id" << endl;
            cin >> idVertex;                               // Corrected: Use >> for input
            player.buy_road(idHex, idVertex, game_board);  // Corrected: Removed 'board &' from the argument
            break;
        }

        case 4: {
            if (!(player.check_ength_resource(4))) {
                break;
            }

            player.buy_dev_card(game_board);
            break;
        }
        case 5: {
            if (player.which_dev_card()) {
                string type;
                cin >> type;
                player.use_dev_card(type);
            }
            break;
        }
        case 6: {
            break;
        }
    }
}
void Catan::during_game(Player &p1, Player &p2, Player &p3, board &game_board) {
    int i = 0;
    while (!(has_winner())) {
        cout << "Hi " << players_turns[i]->get_name() << " it's your turn" << endl;
        int dice = players_turns[i]->rolldice(game_board, *this);
        players_turns[i]->print_my_resource();
        if (dice == 7) {
            seven_case();
        }
        chose_option(*players_turns[i], game_board);
        i = (i + 1) % 3;
    }
    cout << "THE GAME IS OVER" << endl;
}

bool Catan::has_winner() {
    for (int i = 0; i < 3; i++) {
        if (players[i]->get_points() >= 10) {
            cout << players[i]->get_name() << " is the winner" << endl;
            return true;
        }
    }
    return false;
}

// //print all my board with vertex and uedges
// void print my_board(&board game_board){

// }
bool Catan::check_location_hex(int index) {
    if (index < 0 || index >= NUM_HEX) {
        return false;
    }
    return true;
}
