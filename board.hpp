#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>
#include "Hexagon.cpp"  // Include Hexagon.hpp here
using namespace std;

class board {
   private:
    std::vector<Hexagon*> hexagons;

   public:
    // empty constructor
    board();

    // get
    Hexagon *get_hexagons(int index) {
        return hexagons.at(index);
    }

    vector<Hexagon *> &get_board() {
        return hexagons;
    }
vector<Hexagon*> initialization_bord();

    // disrtuctor
    ~board(){
        for (int i = 0; i < hexagons.size(); i++)
        {
            delete hexagons.at(i);
        }
        
    }
      
};
#endif