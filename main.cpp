#include <iostream>
#include "Player.hpp"
#include "Catan.hpp"
#include "Hexagon.cpp"
using namespace std;


int main(){
Player p1("Noam",BLUE);
Player p2("Bar",RED);
Player p3("Vogdan",ORANGE);
Catan catan(p1,p2,p3);//start order_resources and start order_turns







    return 0;
}