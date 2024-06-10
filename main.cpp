#include <iostream>

#include "Catan.hpp"
#include "Hexagon.cpp"
#include "Player.hpp"
using namespace std;

int main() {
    board game_board;
    cout << game_board.get_hexagons(0).get_edge(0)->get_id() << endl;
    Player p1("Noam", BLUE);
    Player p2("Bar", RED);
    Player p3("Vogdan", ORANGE);
    Catan catan(p1, p2, p3, game_board);  // start order_resources and start order_turns

    // cout<<game_board.get_hexagons(15)->get_resource_type()<<endl;
    //  cout<<game_board.get_hexagons(1).get_resource_type()<<endl;
    //  cout<<game_board.get_hexagons(2).get_number()<<endl;
    //  cout<<game_board.get_hexagons(3).get_edge(10)->get_id()<<endl;

    //  cout<<game_board.get_hexagons(0).get_vertex_hex(0).get_color()<<endl;
    //  for (size_t i = 0; i < 6; i++)
    //  {

    //    cout<< game_board.get_hexagons(10).get_vertexs()[i]->get_id()<<endl;
    //  }

    // cout<<game_board.get_hexagons(0).get_vertex_hex(0).get_id()<<endl;
    // cout<<game_board.get_hexagons(0).get_vertex_hex(1).get_id()<<endl;
    // cout<<game_board.get_hexagons(0).get_vertex_hex(2).get_id()<<endl;
    // cout<<game_board.get_hexagons(0).get_vertex_hex(3).get_id()<<endl;
    // cout<<game_board.get_hexagons(0).get_vertex_hex(4).get_id()<<endl;
    // cout<<game_board.get_hexagons(0).get_vertex_hex(5).get_id()<<endl;

    // game_board.get_hexagons(0).get_vertex_hex(0)->set_color(RED);
    // cout<<game_board.get_hexagons(0).get_vertex_hex(0)->get_color()<<endl;

    // cout<<game_board.get_hexagons(0)->get_resource_type()<<endl;

    // cout<<game_board.get_hexagons(0)->get_vertex_hex(0)->get_color()<<endl;
    //  cout<<game_board.get_hexagons(0)->get_resource_type()<<endl;
    //  p1.set_town_start(game_board,0,0);

    // cout<<game_board.get_hexagons(0)->get_vertex(0)->get_color()<<endl;
    // cout<<game_board.get_hexagons(0)->get_vertex(0)->get_hasTown()<<endl;
    // cout<<game_board.get_hexagons(0)->get_vertex(0)->get_hasCity()<<endl;

    return 0;
}