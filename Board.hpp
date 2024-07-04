#ifndef BOARD_HPP
#define BOARD_HPP

#include <algorithm>  // for std::shuffle
#include <iostream>
#include <memory>  // For unique_ptr
#include <random>  // for std::random_device and std::mt19937
#include <vector>

#include "DevCard.hpp"
#include "Hexagon.cpp"
#include "Knight.hpp"
#include "Monopoly.hpp"
#include "Road_Building.hpp"
#include "Victory_Point.hpp"
#include "Year_Of_Plenty.hpp"

using namespace std;

class Board {
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
    vector<unique_ptr<DevCard>> devCards;

   public:
    // empty constructor
    Board();
    // geters
    Edge* get_edge_from_board(int idEdge) {
        return &edges[idEdge];
    }

    Hexagon& get_hexagons(int index) {
        return hexagons.at(index);
    }
    vector<Edge>& get_edges() {
        return edges;
    }
    vector<Hexagon>& get_board() {
        return hexagons;
    }
    vector<unique_ptr<DevCard>>& get_dev_cards() {
        return devCards;
    }

    unique_ptr<DevCard> get_dev_card();

    // initialization functions
    void initialization_board();
    void initialization_dev_cards();
    // print the board
    void print();

    // set
    void set_dev_cards(vector<unique_ptr<DevCard>> devCards) {
        this->devCards = move(devCards);
    }
    // disrtuctor
    ~Board() {

    };
};
#endif