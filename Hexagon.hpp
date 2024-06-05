#include <iostream>
#include <string>
#include <vector>
using namespace std;

// this class represent a hexagon in game board
// it has a center point and 6 vertices
// in all point can build city or town
// in all edge can build road/path
// each hexagon has a resource type

// 5 resources WOOD, WHITE_STONE, RED_STONE, SHEEP, HAY
#define WOOD 1
#define WHITE_STONE 2
#define RED_STONE 3
#define SHEEP 4
#define HAY 5
#define DESERT 7
class Edge; // Forward declaration of Edge

// Vertex class to represent a corner of a hexagon
class Vertex {
   public:
    Player owner;       // -1 means no one built a town/city
    string *my_assets;  // town or city
    int id;             // id
    vector<Edge *> my_edges;
    Vertex(int id) : id(id) {}
    Vertex &addEdge3(Edge *edge1, Edge *edge2, Edge *edge3) {
        my_edges.push_back(edge1);
        my_edges.push_back(edge2);
        my_edges.push_back(edge3);

        return *this;
    }
     Vertex &addEdge2(Edge *edge1, Edge *edge2) {
        my_edges.push_back(edge1);
        my_edges.push_back(edge2);
        return *this;
    }
};

class Edge {
   private:
    Vertex *start;
    Vertex *end;
    Player owner;  // -1 means no one built a road/path
    int id;               // id
    bool hasRoad;         // true if there is a road/path

   public:
    Edge(Vertex *start, Vertex *end, int id) : start(start), end(end), hasRoad(false), id(id) {}
};

class Hexagon {
   private:
    vector<Vertex*> my_vertex;
     vector<Edge*> my_edges;
    int index;
    int number;
    int resource_type;
    string *my_assets;  // town or city
    string *my_roads;   // road/path
   public:
    Hexagon(int resource_type, int index) {
        this->resource_type = resource_type;
        this->index = index;
    }

    int get_resource_type(){
        return  this->resource_type;
    }
         void set_resource_type(int resource_type) {
        this->resource_type = resource_type;
    }

    void set_number(int number) {
        this->number = number;
    }
    void set_my_assets(string *my_assets) {
        this->my_assets = my_assets;
    }
    void set_my_roads(string *my_roads) {
        this->my_roads = my_roads;
    }
};