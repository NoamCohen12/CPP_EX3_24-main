#include "Catan.hpp"

#include "Board.hpp"
#include "Player.hpp"
#define WITHOUT_NUMBER -215151

Catan::Catan(Player &p1, Player &p2, Player &p3, Board &game_board) {
    this->game_board = &game_board;
    players[0] = &p1;
    players[1] = &p2;
    players[2] = &p3;
    order_resources(game_board);
    cout << "****************************************" << endl;
    order_number(game_board);
    order_turns(p1, p2, p3);
    start(p1, p2, p3, game_board);
}
Catan::Catan(Player &p1, Player &p2, Player &p3, Board &game_board, int flag) {  // for testing
    this->game_board = &game_board;
    players[0] = &p1;
    players[1] = &p2;
    players[2] = &p3;
}

void Catan::start(Player &p1, Player &p2, Player &p3, Board &game_board) {
    start_game(game_board);
    during_game(p1, p2, p3, game_board);
}

void Catan::order_turns(Player &p1, Player &p2, Player &p3) {
    int randomIndex = rand() % 3;
    players_turns[randomIndex] = &p1;
    players_turns[(randomIndex + 1) % 3] = &p2;
    players_turns[(randomIndex + 2) % 3] = &p3;
}

void Catan::order_number(Board &game_board) {
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

void Catan::order_resources(Board &game_board) {
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
void Catan::start_game(Board &game_board) {
    for (size_t i = 0; i < 3; i++) {  // over on all players
        cout << "Welcome to Catan" << endl;
        int location_for_town = 0;
        int location_for_path = 0;
        int location_for_hex = 0;
        cout << "Hii " << players_turns[i]->get_name() << endl;
        for (size_t j = 0; j < 2; j++) {
            std::cout << "Which hexagon do you want(between 0-18)? " << endl;

            location_for_hex = readValidInt();
            while (check_location_hex(location_for_hex) == false || check_hwx_full(game_board, location_for_hex,*players_turns[i]) == false) {
                cout << "Invalid hexagon, please choose another hexagon(between 0-18)" << endl;
                location_for_hex = readValidInt();
            }
            std::cout << "this are your options:" << endl;
            for (size_t j = 0; j < 6; j++) {
                int id =game_board.get_hexagons(location_for_hex).get_vertexs(j)->get_id();
                if((*players_turns[i]).check_vertex_valid_start(game_board, location_for_hex, id) == false){
                    continue;
                }
                cout << "vertexId:" << game_board.get_hexagons(location_for_hex).get_vertexs(j)->get_id() << endl;
            }

            std::cout << "Where vertex do you want to build town? " << endl;
            location_for_town = readValidInt();

            while ((players_turns[i]->check_vertex_valid_start(game_board, location_for_hex, location_for_town) == false)) {
                std::cout << "Invalid vertex, please choose another vertex" << endl;
                std::cout << "this are your options:" << endl;
                for (size_t j = 0; j < 6; j++) {
                    if (game_board.get_hexagons(location_for_hex).get_vertexs(j)->get_color() != -1) {
                        continue;
                    }
                    cout << "vertexId:" << game_board.get_hexagons(location_for_hex).get_vertexs(j)->get_id() << endl;
                }
                location_for_town = readValidInt();
            }
            players_turns[i]->set_village_start(location_for_hex, location_for_town, game_board);

            std::cout << "this are your options:" << endl;
            int size = game_board.get_hexagons(location_for_hex).get_vertex_by_ID(location_for_town)->get_edges().size();
            for (size_t k = 0; k < size; k++) {
                if (game_board.get_hexagons(location_for_hex).get_vertex_by_ID(location_for_town)->get_edges()[k]->get_color() != -1) {
                    continue;
                }
                cout << "edgeId:" << game_board.get_hexagons(location_for_hex).get_vertex_by_ID(location_for_town)->get_edges()[k]->get_id() << endl;
            }

            location_for_path = readValidInt();
            while ((players_turns[i]->check_edge_valid(game_board, location_for_path) == false)) {
                std::cout << "Invalid edge, please choose another edge" << endl;
                location_for_path = readValidInt();
            }
            cout << "in Catan0" << endl;

            players_turns[i]->set_path_start(location_for_hex, location_for_path, game_board);
            cout << "in Catan1 after" << endl;
        }
    }
    for (size_t i = 0; i < 3; i++) {
        cout << "my name outside" << players_turns[i]->get_name() << endl;
        players_turns[i]->add_resource_start(game_board);
    }
}

void Catan::add_resources_for_all(int dice, Board &game_board) {
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
                        cout << players[color]->get_name() << "my coloris:" << color << " get 1 resuorce : " << game_board.get_board()[i].get_resource_type() << endl;
                    } else if (temp->get_hasCity()) {
                        players[color]->add_resource(resource);
                        players[color]->add_resource(resource);
                        cout << players[color]->get_name() << "my coloris:" << color << " get 2 resuorce: " << game_board.get_board()[i].get_resource_type() << endl;
                    }
                }
            }
        }
    }
}

void Catan::which_resource() {
    cout << "In case you forgot, these are the resources 📜" << endl;
    cout << "1 is WOOD 🌲" << endl;
    cout << "2 is WHITE_STONE ⚪" << endl;
    cout << "3 is RED_STONE 🔴" << endl;
    cout << "4 is SHEEP 🐑" << endl;
    cout << "5 is HAY 🌾" << endl;
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
                players[i]->print_my_resource();
                which_resource();  // Assuming this function displays resource options
                resource = readValidInt();
                while (players[i]->drop_resource(resource) == 0) {
                    cout << "Choose one more time the resource you want to drop:" << endl;
                    players[i]->print_my_resource();
                    which_resource();  // Assuming this function displays resource options
                    resource = readValidInt();
                }
            }
        }
    }
}

void Catan::chose_option(Player &player, Board &game_board) {
    bool flag = true;
    while (flag) {
        cout << "Choose one of the following options:" << endl;
        cout << "1. buy town" << endl;
        cout << "2. buy city" << endl;
        cout << "3. buy road" << endl;
        cout << "4. buy dev card" << endl;
        cout << "5 trade" << endl;
        cout << "6 next turn" << endl;

        int option;
        option = readValidInt();
        if (option < 1 || option > 7) {
            cout << "Invalid option, please try again" << endl;
            continue;
        }
        switch (option) {
            case 1: {
                if (!(player.check_enough_resource(1))) {
                    cout << "You don't have enough resources to buy a town" << endl;
                    break;
                }
                player.where_build_village(game_board);
                int idHex, idVertex;
                cout << "Enter the hexagon id and the vertex id" << endl;
                idHex = readValidInt();
                cout << "Enter the vertex id" << endl;
                idVertex = readValidInt();
                player.buy_village(idHex, idVertex, game_board);
                player.print_my_resource();

                break;
            }

            case 2: {
                if (!(player.check_enough_resource(2))) {
                    cout << "You don't have enough resources to buy a city" << endl;
                    break;
                }
                player.where_build_city(game_board);
                int idHex, idVertex;
                cout << "Enter the hexagon id and the vertex id" << endl;
                idHex = readValidInt();
                cout << "Enter the vertex id" << endl;
                idVertex = readValidInt();                     // Corrected: Use >> for input
                player.buy_city(idHex, idVertex, game_board);  // Corrected: Removed 'Board &' from the argument
                player.print_my_resource();

                break;
            }

            case 3: {
                if (!(player.check_enough_resource(3))) {
                    cout << "You don't have enough resources to buy a road" << endl;
                    break;
                }
                player.where_build_road(game_board);
                int idHex, idVertex;
                cout << "Enter the hexagon id and the vertex id" << endl;
                idHex = readValidInt();
                cout << "Enter the vertex id" << endl;
                idVertex = readValidInt();                     // Corrected: Use >> for input
                player.buy_road(idHex, idVertex, game_board);  // Corrected: Removed 'Board &' from the argument
                player.print_my_resource();

                break;
            }

            case 4: {
                if (!(player.check_enough_resource(4))) {
                    cout << "You don't have enough resources to buy a development card" << endl;
                    break;
                }
                player.buy_dev_card(game_board);
                player.print_my_resource();

                break;
            }
            case 5: {
                trade(player);
                player.print_my_resource();

                break;
            }
            case 6: {
                flag = false;
                break;
            }
        }
    }
}
void Catan::during_game(Player &p1, Player &p2, Player &p3, Board &game_board) {
    int choice;
    int flag = 0;
    int i = 0;
    while (!(has_winner())) {
        cout << "Hi " << players_turns[i]->get_name() << " it's your turn" << endl;
        if (players_turns[i]->how_many_devCards() > 0) {
            cout << "you want use dev_card?\n1 for yes!\n0 for no!\nRemember if you use the development card the turn will pass" << endl;
            choice = readValidInt();
            while (choice < 0 || choice > 1) {
                cout << "invalid input please enter again (0 or 1)" << endl;
                choice = readValidInt();
            }
            if (choice == 1) {
                do {
                    flag = players_turns[i]->which_dev_card();
                    if (flag == -1) {  // if the player dont want use
                        break;
                    }
                } while (flag == 0);
                players_turns[i]->use_dev_card(*this, flag);
                i = (i + 1) % 3;
                continue;
            }
        }

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

bool Catan::check_location_hex(int index) {
    bool inRange = index >= 0 && index < NUM_HEX;
    // i check if

    return inRange;
}

void Catan::trade(Player &player) {
    cout << "Hi " << player.get_name() << ", choose a player to trade with:" << endl;
    int index = 0;
    for (int i = 0; i < 3; i++) {
        if (players[i]->get_name() == player.get_name()) {
            index++;
            continue;  // Skip the current player
        }
        cout << "Click " << index << " for " << players[i]->get_name() << endl;
        index++;
    }

    int choose;
    choose = readValidInt();
    while (choose < 0 || choose > 2) {
        cout << "Invalid player, please choose another player" << endl;
        choose = readValidInt();
    }

    if (players[choose]->get_name() == player.get_name()) {
        cout << "You can't trade with yourself." << endl;
        return;
    }

    // Execute trade if both players have enough resources

    pair<map<int, int>, map<int, int>> trade = player.trade_resource_player();

    bool hasAllResources = true;

    for (auto it = trade.first.begin(); it != trade.first.end(); ++it) {
        int resource = it->first;
        int count = it->second;
        if (players[choose]->get_count_resource_type(resource) < count) {
            cout << "Player does not have enough of resource " << resource << endl;
            hasAllResources = false;
            break;
        }
    }

    bool currentPlayerHasResources = true;
    for (auto it = trade.second.begin(); it != trade.second.end(); ++it) {
        int resource = it->first;
        int count = it->second;
        if (player.get_count_resource_type(resource) < count) {
            cout << "Current player does not have enough of resource " << resource << endl;
            currentPlayerHasResources = false;
            break;
        }
    }

    if (hasAllResources && currentPlayerHasResources) {
        cout << "Trade successful." << endl;
        for (auto it = trade.first.begin(); it != trade.first.end(); ++it) {
            int resource = it->first;
            int count = it->second;
            for (int i = 0; i < count; ++i) {
                player.add_resource(resource);
                players[choose]->drop_resource(resource);
            }
        }
        for (auto it = trade.second.begin(); it != trade.second.end(); ++it) {
            int resource = it->first;
            int count = it->second;
            for (int i = 0; i < count; ++i) {
                player.drop_resource(resource);
                players[choose]->add_resource(resource);
            }
        }
    } else {
        cout << "Trade cannot proceed due to insufficient resources." << endl;
    }

    cout << "you want to trade DevCard?\n1 for yes!\n0 for no!" << endl;
    int choice;
    choice = readValidInt();
    while (choice < 0 || choice > 1) {
        cout << "invalid input please enter again (0 or 1)" << endl;
        choice = readValidInt();
    }
    if (choice == 1) {
        pair<map<string, int>, map<string, int>> trade = player.trade_DevCards_player();

        bool hasAllDevCards = true;
        for (auto it = trade.first.begin(); it != trade.first.end(); ++it) {
            string type_card = it->first;
            int count = it->second;
            if (players[choose]->get_count_devcard_type(type_card) < count) {
                cout << "Player does not have enough of devCard " << type_card << endl;
                hasAllDevCards = false;
                break;
            }
        }
        bool currentPlayerHasDevCards = true;
        for (auto it = trade.second.begin(); it != trade.second.end(); ++it) {
            string type_card = it->first;
            int count = it->second;
            if (player.get_count_devcard_type(type_card) < count) {
                cout << "Current player does not have enough of devCard " << type_card << endl;
                currentPlayerHasDevCards = false;
                break;
            }
        }

        if (hasAllDevCards && currentPlayerHasDevCards) {
            cout << "Trade successful." << endl;
            for (auto it = trade.first.begin(); it != trade.first.end(); ++it) {
                string resource = it->first;
                int count = it->second;
                for (int i = 0; i < count; ++i) {
                    player.add_devCard(resource);
                    players[choose]->drop_devCard(resource);
                }
            }
            for (auto it = trade.second.begin(); it != trade.second.end(); ++it) {
                string resource = it->first;
                int count = it->second;
                for (int i = 0; i < count; ++i) {
                    player.drop_devCard(resource);
                    players[choose]->add_devCard(resource);
                }
            }
        } else {
            cout << "Trade cannot proceed due to insufficient devCards." << endl;
        }
    }
}
int Catan::convert_int_fromstrring(string resource) {
    if (resource == "SHEEP") {
        return SHEEP;
    } else if (resource == "WOOD") {
        return WOOD;
    } else if (resource == "HAY") {
        return HAY;
    } else if (resource == "RED_STONE") {
        return RED_STONE;
    } else if (resource == "WHITE_STONE") {
        return WHITE_STONE;
    }
    return -1;
}

int Catan::readValidInt() {
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

bool Catan::check_hwx_full(Board &game_board, int indexHex, Player &player) {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        auto vertex = game_board.get_hexagons(indexHex).get_vertexs(i);
        // Ensure vertex is valid and check additional criteria from check_vertex_valid_start
        if (vertex == nullptr || player.check_vertex_valid_start(game_board, indexHex,vertex->get_id())==false) {
            count++;
        }
    }
    if (count == 6) {
        cout << "hexagon:" << indexHex << " is full" << endl;
        return false;
    }
    return true;
}