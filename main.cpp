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
       p3.set_path_start(game_board,4,15);
       p3.set_path_start(game_board,5,16);
        p3.buy_town( 1, 9,game_board);

        

   game_board.print();
    
//    game_board.get_edge_new(7)->set_color(RED);

  
  


    return 0;
}