#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>

#include "Board.hpp"
#include "Catan.hpp"
#include "DevCard.hpp"
#include "Hexagon.cpp"
#include "Knight.hpp"
#include "Monopoly.hpp"
#include "Player.hpp"
#include "Road_Building.hpp"
#include "Victory_Point.hpp"
#include "Year_Of_Plenty.hpp"
#include "doctest.h"
using namespace std;

TEST_CASE("set town/set path") {
    Board game_board;
    Player p1("Bar", RED);
    Player p2("Noam", BLUE);
    Player p3("Vogdan", ORANGE);
    p1.set_village_start(0, 3, game_board);
    p2.set_village_start(0, 4, game_board);
    p3.set_village_start(0, 12, game_board);
    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(3)->get_color() == RED);
    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(4)->get_color() == BLUE);
    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(12)->get_color() == ORANGE);
    p1.set_path_start(0, 0, game_board);
    p1.set_path_start(0, 1, game_board);
    CHECK(game_board.get_hexagons(0).get_edges(0)->get_color() == RED);
    CHECK(game_board.get_hexagons(0).get_edges(1)->get_color() == -1);
}
TEST_CASE("buy village/city/road") {
    Board game_board;
    Player p3("Vogdan", ORANGE);
    p3.set_village_start(1, 9, game_board);
    // check color
    CHECK(game_board.get_hexagons(1).get_vertex_by_ID(9)->get_color() == ORANGE);
    p3.set_path_start(1, 8, game_board);
    // check color
    CHECK(game_board.get_edge_from_board(8)->get_color() == ORANGE);
    p3.add_resource(WOOD);
    p3.add_resource(RED_STONE);
    CHECK(p3.get_count_resource_type(WOOD) == 1);
    CHECK(p3.get_count_resource_type(RED_STONE) == 1);
    p3.buy_road(2, 4, game_board);
    CHECK(p3.get_count_resource_type(WOOD) == 0);  // check if the resource was taken after buying road
    CHECK(p3.get_count_resource_type(RED_STONE) == 0);
    // check color
    CHECK(game_board.get_edge_from_board(4)->get_color() == ORANGE);

   
    for (size_t i = 0; i < 2; i++) {
        p3.add_resource(WOOD);
        p3.add_resource(RED_STONE);
        p3.add_resource(HAY);
        p3.add_resource(SHEEP);
    }
    CHECK(p3.get_count_resource_type(WOOD) == 2);
    CHECK(p3.get_count_resource_type(RED_STONE) == 2);
    CHECK(p3.get_count_resource_type(HAY) == 2);
    CHECK(p3.get_count_resource_type(SHEEP) == 2);

    p3.buy_village(2, 2, game_board);
    CHECK(p3.get_points() == 2);
    CHECK(p3.get_count_resource_type(WOOD) == 1);
    CHECK(p3.get_count_resource_type(RED_STONE) == 1);
    CHECK(p3.get_count_resource_type(HAY) == 1);
    CHECK(p3.get_count_resource_type(SHEEP) == 1);
    // check color after two path
    CHECK(game_board.get_hexagons(2).get_vertex_by_ID(2)->get_color() == ORANGE);
    p3.buy_village(2, 10, game_board);
    CHECK(p3.get_count_resource_type(WOOD) == 1);//vertex invalid the resource not drop.
    CHECK(p3.get_count_resource_type(RED_STONE) == 1);
    CHECK(p3.get_count_resource_type(HAY) == 1);
    CHECK(p3.get_count_resource_type(SHEEP) == 1);
    CHECK(p3.get_points() == 2);
    // check color without two path
    CHECK(game_board.get_hexagons(2).get_vertex_by_ID(10)->get_color() == -1);
}
TEST_CASE("add resource") {
    Board game_board;
    Player p1("Bar", RED);
    Player p2("Noam", BLUE);
    Player p3("Vogdan", ORANGE);
    p2.add_resource(WHITE_STONE);  // add_resource
    p2.add_resource(WHITE_STONE);
    p2.add_resource(WHITE_STONE);
    p2.add_resource(HAY);
    p2.add_resource(HAY);
    CHECK(p2.get_count_resource_type(WHITE_STONE) == 3);
    CHECK(p2.get_count_resource_type(HAY) == 2);
}
TEST_CASE("check_edge_valid/check_vertex_valid_start/check_vertex_valid_during") {
    Board game_board;
    Player p1("Bar", RED);
    Player p2("Noam", BLUE);
    Player p3("Vogdan", ORANGE);
    p1.set_village_start(0, 3, game_board);
    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(3)->get_color() == RED);

    p2.set_village_start(0, 4, game_board);
    p3.set_village_start(0, 12, game_board);

    CHECK(p1.check_edge_valid(game_board, 0) == true);
    CHECK(p1.check_edge_valid(game_board, 1) == false);              // withot my vertex
    CHECK(p1.check_vertex_valid_start(game_board, 0, 3) == false);   // vertex is taken(my town is there)
    CHECK(p1.check_vertex_valid_start(game_board, 0, 4) == false);   // vertex is taken(other town is there)
    CHECK(p3.check_vertex_valid_start(game_board, 0, 0) == false);   // next vertex is taken
    CHECK(p3.check_vertex_valid_during(game_board, 2, 6) == false);  // without 2 path to the vertex
}

TEST_CASE("start_game function") {
    Board game_board;
    Player p1("Bar", RED);
    Player p2("Noam", BLUE);
    Player p3("Vogdan", ORANGE);
    Catan catan(p1, p2, p3, game_board, 0);  // start order_resources and start order_turns

    // Save the original buffer of std::cin
    std::streambuf* cinBuffer = std::cin.rdbuf();
    // Create a new input stream with the input you want to test
    std::istringstream testInput("0\n0\n1\n0\n8\n12\n1\n1\n3\n1\n9\n14\n2\n2\n5\n2\n10\n16\n");  // Redirect std::cin to your input stream
    std::cin.rdbuf(testInput.rdbuf());
    catan.start_game(game_board);
    // player one
    CHECK(game_board.get_hexagons(0).get_edge_by_ID(1)->get_color() != -1);
    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(0)->get_color() != -1);

    CHECK(game_board.get_hexagons(0).get_edge_by_ID(12)->get_color() != -1);
    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(8)->get_color() != -1);

    // player two
    CHECK(game_board.get_hexagons(1).get_edge_by_ID(3)->get_color() != -1);
    CHECK(game_board.get_hexagons(1).get_vertex_by_ID(1)->get_color() != -1);

    CHECK(game_board.get_hexagons(1).get_edge_by_ID(14)->get_color() != -1);
    CHECK(game_board.get_hexagons(1).get_vertex_by_ID(9)->get_color() != -1);

    // player three
    CHECK(game_board.get_hexagons(2).get_edge_by_ID(5)->get_color() != -1);
    CHECK(game_board.get_hexagons(2).get_vertex_by_ID(2)->get_color() != -1);

    CHECK(game_board.get_hexagons(2).get_edge_by_ID(16)->get_color() != -1);
    CHECK(game_board.get_hexagons(2).get_vertex_by_ID(10)->get_color() != -1);

    std::cin.rdbuf(cinBuffer);
}

TEST_CASE("trade") {
    SUBCASE("trade of resources") {
        Board game_board;
        Player p1("Bar", RED);
        Player p2("Noam", BLUE);
        Player p3("Vogdan", ORANGE);
        Catan catan(p1, p2, p3, game_board, 0);  // start order_resources and start order_turns
        for (size_t i = 0; i < 2; i++) {
            p1.add_resource(WHITE_STONE);
        }
        for (size_t i = 0; i < 2; i++) {
            p1.add_resource(HAY);
        }
        for (size_t i = 0; i < 2; i++) {
            p2.add_resource(SHEEP);
        }
        for (size_t i = 0; i < 2; i++) {
            p2.add_resource(WOOD);
        }
        CHECK(p2.get_count_resource_type(WOOD) == 2);
        CHECK(p2.get_count_resource_type(SHEEP) == 2);
        CHECK(p1.get_count_resource_type(WHITE_STONE) == 2);
        CHECK(p1.get_count_resource_type(HAY) == 2);

        // Save the original buffer of std::cin
        std::streambuf* cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("1\n2\n0\n0\n2\n0\n0\n2\n0\n0\n2\n0\n");  // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        catan.trade(p1);
        CHECK(p1.get_count_resource_type(WOOD) == 2);
        CHECK(p1.get_count_resource_type(SHEEP) == 2);
        CHECK(p2.get_count_resource_type(WHITE_STONE) == 2);
        CHECK(p2.get_count_resource_type(HAY) == 2);

        std::cin.rdbuf(cinBuffer);
    }
    //     //          {1, "🌲"}, // WOOD
    //     //         {4, "🐑"}, // SHEEP
    //     //         {2, "⚪"}, // WHITE_STONE
    //     //         {5, "🌾"}, // HAY
    //     //         {3, "🔴"}  // RED_STONE
    SUBCASE("trade of devCards") {
        Board game_board;
        Player p1("Bar", RED);
        Player p2("Noam", BLUE);
        Player p3("Vogdan", ORANGE);
        Catan catan(p1, p2, p3, game_board, 0);  // start order_resources and start order_turns
        std::unique_ptr<Knight> knight = std::make_unique<Knight>();
        std::unique_ptr<Knight> knight2 = std::make_unique<Knight>();
        std::unique_ptr<Knight> knight3 = std::make_unique<Knight>();
        p1.add_dev_card_ptr(std::move(knight));
        p2.add_dev_card_ptr(std::move(knight2));
        CHECK(p1.how_many_devCards() == 1);
        CHECK(p2.how_many_devCards() == 1);

        // Save the original buffer of std::cin
        std::streambuf* cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n");  // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        catan.trade(p1);
        CHECK(p1.how_many_devCards() == 2);
        CHECK(p2.how_many_devCards() == 0);

        std::cin.rdbuf(cinBuffer);
    }
}
TEST_CASE("use devcard") {
    SUBCASE("monopoly") {
        Board game_board;
        Player p1("Bar", RED);
        Player p2("Noam", BLUE);
        Player p3("Vogdan", ORANGE);
        Catan catan(p1, p2, p3, game_board, 0);  // start order_resources and start order_turns
        CHECK(p1.get_count_resource_type(WHITE_STONE) == 0);
        p2.add_resource(WHITE_STONE);
        p3.add_resource(WHITE_STONE);
        std::unique_ptr<Monopoly> monopoly = std::make_unique<Monopoly>();
        p1.add_dev_card_ptr(std::move(monopoly));  // Adding the Monopoly card to p1's development cards

        // Save the original buffer of std::cin
        std::streambuf* cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("2\n");  // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        p1.use_dev_card(catan, 4);  // Using the Monopoly card

        CHECK(p1.get_count_resource_type(WHITE_STONE) == 2);

        std::cin.rdbuf(cinBuffer);
    }
    SUBCASE("Victory_Point") {
        Board game_board;
        Player p1("Bar", RED);
        Player p2("Noam", BLUE);
        Player p3("Vogdan", ORANGE);
        Catan catan(p1, p2, p3, game_board, 0);  // start order_resources and start order_turns
        CHECK(p1.get_count_resource_type(WHITE_STONE) == 0);
        std::unique_ptr<Victory_Point> victory_Point = std::make_unique<Victory_Point>();
        p1.add_dev_card_ptr(std::move(victory_Point));  // Adding the Monopoly card to p1's development cards

        // Save the original buffer of std::cin
        std::streambuf* cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("5\n");  // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        p1.use_dev_card(catan, 5);  // Using the Monopoly card

        CHECK(p1.get_points() == 1);

        std::cin.rdbuf(cinBuffer);
    }
    SUBCASE("Road_Building") {
        Board game_board;
        Player p1("Bar", RED);
        Player p2("Noam", BLUE);
        Player p3("Vogdan", ORANGE);
        Catan catan(p1, p2, p3, game_board, 0);  // start order_resources and start order_turns
        std::unique_ptr<Road_Building> road_Building = std::make_unique<Road_Building>();
        p1.add_dev_card_ptr(std::move(road_Building));  // Adding the Monopoly card to p1's development cards
        p1.set_village_start(0, 0, game_board);
        p1.set_village_start(1, 1, game_board);

        // Save the original buffer of std::cin
        std::streambuf* cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("0\n0\n1\n2\n");  // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        p1.use_dev_card(catan, 2);  // Using the Monopoly card

        CHECK(game_board.get_hexagons(0).get_edge_by_ID(0)->get_color() == RED);
        CHECK(game_board.get_hexagons(1).get_edge_by_ID(2)->get_color() == RED);

        std::cin.rdbuf(cinBuffer);
    }
    SUBCASE("Year_Of_Plenty") {
        Board game_board;
        Player p1("Bar", RED);
        Player p2("Noam", BLUE);
        Player p3("Vogdan", ORANGE);
        Catan catan(p1, p2, p3, game_board, 0);  // start order_resources and start order_turns
        std::unique_ptr<Year_Of_Plenty> year_Of_Plenty = std::make_unique<Year_Of_Plenty>();
        p1.add_dev_card_ptr(std::move(year_Of_Plenty));  // Adding the Monopoly card to p1's development cards

        // Save the original buffer of std::cin
        std::streambuf* cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("1\n1\n");  // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        p1.use_dev_card(catan, 3);  // Using the Monopoly card

        CHECK(p1.get_count_resource_type(WOOD) == 2);
        std::cin.rdbuf(cinBuffer);
    }
    SUBCASE("Knight") {
        Board game_board;
        Player p1("Bar", RED);
        Player p2("Noam", BLUE);
        Player p3("Vogdan", ORANGE);
        Catan catan(p1, p2, p3, game_board, 0);  // start order_resources and start order_turns
        std::unique_ptr<Knight> knight = std::make_unique<Knight>();
        CHECK(p1.get_points() == 0);
        p1.add_dev_card_ptr(std::move(knight));

        // Save the original buffer of std::cin
        std::streambuf* cinBuffer = std::cin.rdbuf();
        // Create a new input stream with the input you want to test
        std::istringstream testInput("1\n");  // Redirect std::cin to your input stream
        std::cin.rdbuf(testInput.rdbuf());
        p1.use_dev_card(catan, 1);  // Using the Monopoly card
        CHECK(p1.get_knights() == 1);

        std::cin.rdbuf(cinBuffer);
    }
}

//////output
// 📦 this is your resources:
// 🌾 your resources hay: 0
// 🐑 your resources sheep: 1
// ⚪ your resources white stone: 1
// 🔴 your resources red stone: 0
// 🌲 your resources wood: 2
// Baryou have 2 resources
// 2
// 📦 this is your resources:
// 🌾 your resources hay: 0
// 🐑 your resources sheep: 2
// ⚪ your resources white stone: 0
// 🔴 your resources red stone: 0
// 🌲 your resources wood: 0
// Vogdanyou have 4 resources
// 4
// 📦 this is your resources:
// 🌾 your resources hay: 0
// 🐑 your resources sheep: 2
// ⚪ your resources white stone: 0
// 🔴 your resources red stone: 2
// 🌲 your resources wood: 0
