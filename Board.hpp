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

    Edge* get_edge_from_board(int idEdge) {
        return &edges[idEdge];
    }
    // get
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

    unique_ptr<DevCard> get_dev_card() {
        if (devCards.empty()) {
            cout << "no more dev cards" << endl;
            // Handle the case where there are no development cards left
            return nullptr;  // Or throw an exception, or handle it as appropriate
        }
        auto card = move(devCards.back());
        cout << "move" << endl;
        devCards.pop_back();  // remove the card from the deck
        return card;
    }

    void initialization_board();

    void initialization_dev_cards();
    void print() {
        int k = 0;
        for (size_t i = 0; i < 18; i++) {
            cout << "hexagon id: " << k++ << endl;
            for (size_t j = 0; j < 6; j++) {
                // print all edge with id
                cout << "vertex id: " << hexagons[i].get_vertexs(j)->get_id() << " color " << hexagons[i].get_vertexs(j)->get_color() << endl;
            }
        }
        // print niw edges by hexagon
        for (size_t i = 0; i < 18; i++) {
            cout << "hexagon id: " << i << endl;
            for (size_t j = 0; j < 6; j++) {
                cout << "edge id: " << hexagons[i].get_edges(j)->get_id() << " color " << hexagons[i].get_edges(j)->get_color() << endl;
            }
        }
    }
    // set

    void set_dev_cards(vector<unique_ptr<DevCard>> devCards) {
        this->devCards = move(devCards);
    }
    // disrtuctor
    ~Board() {

    };
};
#endif