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
    //catan.start(p1, p2, p3, game_board);
 //catan.start_game(game_board);

        
   // std::istringstream testInput("0\n0\n0\n1\n0\n7\n0\n11\n1\n1\n1\n3\n1\n13\n1\n13\n2\n2\n2\n5\n2\n14\n2\n15\n");

    //check if function trade in catan correct
   


  
  
 // Save the original buffer of std::cin
//     std::streambuf* cinBuffer = std::cin.rdbuf();
//     // Create a new input stream with the input you want to test
//     std::istringstream testInput("0\n0\n0\n1\n0\n7\n0\n11\n1\n1\n1\n3\n1\n13\n1\n13\n2\n2\n2\n5\n2\n14\n2\n15\n");
// // Redirect std::cin to your input stream
// std::cin.rdbuf(testInput.rdbuf());
// catan.start_game(game_board);
//     CHECK(game_board.get_hexagons(0).get_edge_by_ID(0)->get_color() !=-1);

    return 0;
}