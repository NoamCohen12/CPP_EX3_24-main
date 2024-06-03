#include <iostream>
#include "player.hpp"
#include "Catan.hpp"
#include "hex.hpp"
using namespace std;


int main(){
player p1("Noam",BLUE);
player p2("Bar",RED);
player p3("Vogdan",ORANGE);
Catan catan(p1,p2,p3);//start order_resources and start order_turns







    return 0;
}