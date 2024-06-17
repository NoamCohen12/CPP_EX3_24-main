#include <iostream>

#include "Catan.hpp"
#include "Hexagon.cpp"
#include "Player.hpp"
using namespace std;

int main() {
    board game_board;
    Player p1("Bar", RED);
    Player p2("Noam", BLUE);
    Player p3("Vogdan", ORANGE);
    Catan catan(p1, p2, p3, game_board);  // start order_resources and start order_turns
//     p2.set_town_start(game_board, 0, 4);
   
    
//    game_board.get_edge_new(7)->set_color(RED);

// game_board.get_edge_new(7)->get_color();
for (size_t i = 0; i < 18; i++)
{
  for (size_t j = 0; j < 6; j++)
  {
    //print all edge with id
    cout << "edge id: " << game_board.get_hexagons(i).get_edges(j)->get_id() <<" color "<<game_board.get_hexagons(i).get_edges(j)->get_color()<< endl;
  }
}
  
  


    return 0;
}