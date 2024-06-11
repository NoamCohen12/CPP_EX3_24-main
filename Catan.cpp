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
    start_game(game_board);
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
                //   std::cout << "Hex " << count << " setting number to " << number << std::endl;
            }
            numbers[randomIndex] = -1;
            count++;
        }
    }
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
            // cout << "hexagon " << count << " resource: " << type << endl;
            resources[randomIndex] = 0;
            count++;
        }
    }
}

void Catan::start_game(board &game_board) {
    cout << "Welcome to Catan" << endl;
    srand(time(0));  // Seed the random number generator once
    int randomIndex = rand() % 3;
    players[randomIndex]->set_turn(1);
    int location_for_town = 0;
    int location_for_path = 0;
    int location_for_hex = 0;
    cout << "Hii " << players[randomIndex]->get_name() << endl;
    for (size_t i = 0; i < 2; i++) {
        // TODO: check if the vertex next to empty
        std::cout << "Which hexagon do you want? " << endl;
        std::cin >> location_for_hex;
        std::cout << "this are your options:" << endl;

        for (size_t j = 0; j < 6; j++) {
            cout << j << "." << "vertexId:" << game_board.get_hexagons(location_for_hex).get_vertexs()[j]->get_id() << endl;
        }

        std::cout << "Where vertex do you want to build town? " << endl;

        std::cin >> location_for_town;
        while ((players[randomIndex]->check_vertex_valid(game_board, location_for_hex, location_for_town) == false)) {
            std::cout << "Invalid vertex, please choose another vertex" << endl;
            std::cin >> location_for_town;
        }
        players[randomIndex]->set_town_start(game_board, location_for_hex, location_for_town);

        std::cout << "Where edge do you want to build path? choose Hexagon for the second time: " << endl;
        std::cin >> location_for_hex;
        std::cout << "this are your options:" << endl;
        // int id = game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges()[j]->get_id();
        int size = game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges().size();
        for (size_t j = 0; j < size; j++) {
            if (game_board.get_hexagons(location_for_hex).contains_edge(game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges()[j]->get_id())) {
                cout << j << "."
                             "EdgeId:"
                     << game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges()[j]->get_id() << endl;
            }
            continue;
        }

        std::cin >> location_for_path;
        while ((players[randomIndex]->check_edge_valid(game_board, location_for_hex, location_for_path) == false)) {
            std::cout << "Invalid edge, please choose another edge" << endl;
            std::cin >> location_for_path;
        }
        players[randomIndex]->set_path_start(game_board, location_for_hex, location_for_path);
    }
    players[randomIndex]->add_resource(game_board.get_board()[location_for_hex].get_resource_type());

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Hii " << players[(randomIndex + 1) % 3]->get_name() << endl;
    players[(randomIndex + 1) % 3]->set_turn(2);
    for (size_t i = 0; i < 2; i++) {
        std::cout << "Which hexagon do you want? " << endl;
        std::cin >> location_for_hex;  // Assuming you meant to ask for hex location again

        for (size_t j = 0; j < 6; j++) {
            cout << j << "." << "vertexId:" << game_board.get_hexagons(location_for_hex).get_vertexs()[j]->get_id() << endl;
        }
        std::cout << "Where vertex do you want to build town? " << endl;
        std::cin >> location_for_town;  // Corrected variable name and method of input
        while ((players[(randomIndex + 1) % 3]->check_vertex_valid(game_board, location_for_hex, location_for_town) == false)) {
            std::cout << "Invalid vertex, please choose another vertex" << endl;
            std::cin >> location_for_town;
        }
        players[(randomIndex + 1) % 3]->set_town_start(game_board, location_for_hex, location_for_town);

        std::cout << "Where edge do you want to build path? choose Hexagon for the second time: " << endl;
        std::cin >> location_for_hex;
        std::cout << "this are your options:" << endl;
        int size = game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges().size();
        for (size_t j = 0; j < size; j++) {
            if (game_board.get_hexagons(location_for_hex).contains_edge(game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges()[j]->get_id())) {
                cout << j << "."
                             "EdgeId:"
                     << game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges()[j]->get_id() << endl;
            }
            continue;
        }
        std::cin >> location_for_path;
        while ((players[(randomIndex + 1) % 3]->check_edge_valid(game_board, location_for_hex, location_for_path) == false)) {
            std::cout << "Invalid edge, please choose another edge" << endl;
            std::cin >> location_for_path;
        }

        players[(randomIndex + 1) % 3]->set_path_start(game_board, location_for_hex, location_for_path);
    }
    players[(randomIndex + 1) % 3]->add_resource(game_board.get_board()[location_for_hex].get_resource_type());
    /////////////////////////////////////////////////////////////////////////////////
    cout << "Hii " << players[(randomIndex + 2) % 3]->get_name() << endl;

    players[(randomIndex + 2) % 3]->set_turn(3);
    for (size_t i = 0; i < 2; i++) {
        std::cout << "Which hexagon do you want? " << endl;
        std::cin >> location_for_hex;

        for (size_t j = 0; j < 6; j++) {
            cout << j << "." << "vertexId:" << game_board.get_hexagons(location_for_hex).get_vertexs()[j]->get_id() << endl;
        }
        std::cout << "Where vertex do you want to build town? " << endl;
        std::cin >> location_for_town;
        while ((players[(randomIndex + 2) % 3]->check_vertex_valid(game_board, location_for_hex, location_for_town) == false)) {
            std::cout << "Invalid vertex, please choose another vertex" << endl;
            std::cin >> location_for_town;
        }
        players[(randomIndex + 2) % 3]->set_town_start(game_board, location_for_hex, location_for_town);

        std::cout << "Where edge do you want to build path? choose Hexagon for the second time: " << endl;
        std::cin >> location_for_hex;
        std::cout << "this are your options:" << endl;
        int size = game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges().size();
        for (size_t j = 0; j < size; j++) {
            if (game_board.get_hexagons(location_for_hex).contains_edge(game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges()[j]->get_id())) {
                cout << j << "."
                             "EdgeId:"
                     << game_board.get_hexagons(location_for_hex).get_vertex_hex(location_for_town)->get_edges()[j]->get_id() << endl;
            }
            continue;
        }
        std::cin >> location_for_path;
        while ((players[(randomIndex + 2) % 3]->check_edge_valid(game_board, location_for_hex, location_for_path) == false)) {
            std::cout << "Invalid edge, please choose another edge" << endl;
            std::cin >> location_for_path;
        }
    }
    players[(randomIndex + 2) % 3]->add_resource(game_board.get_board()[location_for_hex].get_resource_type());
}

void Catan::add_resources_for_all(int dice, board &game_board) {
    for (int i = 0; i < NUM_HEX; i++) {
        int resource = game_board.get_board()[i].get_resource_type();
        if (game_board.get_board()[i].get_number() == dice) {  // if the number of the hexagon is equal to the dice
            for (int j = 0; j < 6; j++) {
                Vertex *temp = game_board.get_board()[i].get_vertexs()[j];
                int color = temp->get_color();
                if (color != -1) {
                    if (temp->get_hasTown()) {
                        players[color]->add_resource(resource);
                        cout << players[color]->get_name() << color << " get 1: " << game_board.get_board()[i].get_resource_type() << endl;
                    } else if (temp->get_hasCity()) {
                        players[color]->add_resource(resource);
                        players[color]->add_resource(resource);
                        cout << players[color]->get_name() << color << " get 2: " << game_board.get_board()[i].get_resource_type() << endl;
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