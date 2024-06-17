#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>

#include "Catan.hpp"
#include "Hexagon.cpp"
#include "Player.hpp"
#include "board.hpp"
#include "doctest.h"
using namespace std;

TEST_CASE("set town") {
    SUBCASE("set town") {
        board game_board;
        Player p1("Bar", RED);
        Player p2("Noam", BLUE);
        Player p3("Vogdan", ORANGE);
        p1.set_town_start(game_board, 0, 3);
        p2.set_town_start(game_board, 0, 4);
        p3.set_town_start(game_board, 0, 12);
        p3.set_town_start(game_board, 1, 5);
        CHECK(game_board.get_hexagons(0).get_vertex_by_ID(3)->get_color() == RED);
        CHECK(game_board.get_hexagons(0).get_vertex_by_ID(4)->get_color() == BLUE);
        CHECK(game_board.get_hexagons(0).get_vertex_by_ID(12)->get_color() == ORANGE);
    }
    SUBCASE("buy town/city/add_resource/get_resource_type") {
        board game_board;
        Player p1("Bar", RED);
        Player p2("Noam", BLUE);
        Player p3("Vogdan", ORANGE);
        p1.buy_town(0, 3, game_board);
        p3.buy_town(0, 12, game_board);
        CHECK(game_board.get_hexagons(0).get_vertex_by_ID(3)->get_color() == RED);
        CHECK(game_board.get_hexagons(0).get_vertex_by_ID(12)->get_color() == ORANGE);

        p2.buy_city(0, 4, game_board);//without resources
        p2.add_resource(WHITE_STONE);
        p2.add_resource(WHITE_STONE);
        p2.add_resource(WHITE_STONE);
        p2.add_resource(HAY);
        p2.add_resource(HAY);
    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(4)->get_hasCity() == false);
    CHECK(p2.get_count_resource_type(WHITE_STONE) == 3);
    CHECK(p2.get_count_resource_type(HAY) == 2);

    p2.add_resource(WOOD);
    p2.add_resource(RED_STONE);
    p2.add_resource(SHEEP);
    p2.add_resource(SHEEP);

    p2.buy_town(0, 4, game_board);
        CHECK(game_board.get_hexagons(0).get_vertex_by_ID(4)->get_color() == BLUE);

    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(4)->get_hasTown() == true);
    p2.buy_city(0, 4, game_board);
    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(4)->get_hasCity() == true);
    CHECK(game_board.get_hexagons(0).get_vertex_by_ID(4)->get_color() == BLUE);


   

       
    }
}
// cout<<game_board.get_hexagons(0).get_vertex_by_ID(3)->get_color()<<endl;
// cout<<game_board.get_hexagons(0).get_vertex_by_ID(4)->get_color()<<endl;
// cout<<game_board.get_hexagons(0).get_vertex_by_ID(12)->get_color()<<endl;
// p1.set_town_start(game_board, 0, 3);
// cout<<game_board.get_hexagons(0).get_vertex_by_ID(3)->get_color()<<endl;

// p2.set_town_start(game_board, 0, 4);
// cout<<game_board.get_hexagons(0).get_vertex_by_ID(4)->get_color()<<endl;

// p3.set_town_start(game_board, 0, 12);
// p3.set_town_start(game_board, 1, 5);
// cout<<game_board.get_hexagons(0).get_vertex_by_ID(12)->get_color()<<endl;

// game_board.get_hexagons(0).set_resource_type(RED_STONE);
// game_board.get_hexagons(1).set_resource_type(WOOD);

//     p1.add_resource_start(game_board);
//     p2.add_resource_start(game_board);
//     p3.add_resource_start(game_board);

// for (int i = 0; i < 19; i++) {
//     cout << "Hexagon " << i << endl;
//     for (int j = 0; j < 6; j++) {
//         cout << "Vertex " << game_board.get_hexagons(i).get_vertexs(j)->get_id() << " color: " << game_board.get_hexagons(i).get_vertexs(j)->get_color() << endl;
//     }
// }

// cout<<p1.get_name()<<p1.how_many_resources()<<endl;;
// cout<<p2.get_name()<<p2.how_many_resources()<<endl;;
// cout<<p3.get_name()<<p3.how_many_resources()<<endl;;

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
