#include <iostream>

#include "Catan.hpp"
#include "Hexagon.cpp"
#include "Player.hpp"
using namespace std;

int main() {
    Board game_board;
    Player p1("Bar", RED);
    Player p2("Noam", BLUE);
    Player p3("Vogdan", ORANGE);
    Catan catan(p1, p2, p3, game_board);  // start order_resources and start order_turns
    //   Catan catan(p1, p2, p3, game_board, 0);  // start order_resources and start order_turns
    //     std::unique_ptr<Knight> knight = std::make_unique<Knight>();
    //     CHECK(p1.get_points() == 0);
    //     p1.add_dev_card_ptr(std::move(knight));
        
    //     cout<<(p1.get_knights() == 1)<<endl;

    //     // Save the original buffer of std::cin
    //    // std::streambuf* cinBuffer = std::cin.rdbuf();
    //     // Create a new input stream with the input you want to test
    //     //std::istringstream testInput("1\n");  // Redirect std::cin to your input stream
    //     //std::cin.rdbuf(testInput.rdbuf());
    //     p1.use_dev_card(catan, 1);  // Using the Monopoly card
    //     //std::cin.rdbuf(cinBuffer);
}