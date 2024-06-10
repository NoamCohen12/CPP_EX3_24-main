#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>

#include "Hexagon.cpp"
using namespace std;

class board {
   private:
    vector<Hexagon> hexagons;
    vector<Edge> edges;
    vector<Vertex> vertices;

   public:
    // empty constructor
    board();

    // get
    Hexagon& get_hexagons(int index) {
        return hexagons.at(index);
    }

    vector<Hexagon>& get_board() {
        return hexagons;
    }
    void initialization_board();

    // disrtuctor
    ~board(){

    };
};
#endif