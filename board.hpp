#ifndef BOARD_HPP
#define BOARD_HPP
#include <algorithm>  // for std::shuffle
#include <iostream>
#include <memory>  // For unique_ptr
#include <random>  // for std::random_device and std::mt19937
#include <vector>


#include "Hexagon.cpp"
#include "devCard.cpp"

using namespace std;

class board {
   private:
    vector<Hexagon> hexagons;
    vector<Edge> edges;
    vector<Vertex> vertices;
/**
Knight Cards (Soldier Cards):3 cards
Victory Point Cards: 4 cards
Road Building Cards: 2 cards
Year of Plenty Cards: 2 cards
Monopoly Cards: 2 cards
*/
    vector<unique_ptr<devCard>> devCards;

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
    vector<unique_ptr<devCard>>& get_dev_cards() {
        return devCards;
    }
    string get_dev_card() {
        srand(time(0));
         if (devCards.empty()) {
        // Handle the case where there are no development cards left
        return ""; // Or throw an exception, or handle it as appropriate
         }
        //get index rundom at range of dev_cards size
        int index = rand() % devCards.size();
        string type = devCards.at(index)->type();
        devCards.erase(devCards.begin() + index);
        return type;
    }
    void initialization_board();

    void initialization_dev_cards();

    // disrtuctor
    ~board(){

    };
};
#endif