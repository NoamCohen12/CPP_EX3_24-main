#include <iostream>
#include "Player.hpp"
#include "Catan.hpp"
#include "Hexagon.cpp"
using namespace std;


int main(){
board game_board;
Player p1("Noam",BLUE);
Player p2("Bar",RED);
Player p3("Vogdan",ORANGE);
Catan catan(p1,p2,p3,game_board);//start order_resources and start order_turns

    cout<<game_board.get_hexagons(0)->get_vertex(0)->get_color()<<endl;
    cout<<game_board.get_hexagons(0)->get_resource_type()<<endl;








    return 0;
}