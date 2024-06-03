#include <iostream>
#include <string>
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
// Vertex class to represent a corner of a hexagon
class Vertex
{
public:
    imt color = -1; // -1 means no one built a town/city
    bool hasTown;
    bool hasCity;
    int id; // id
    vector<Edge *> my_edges;
    Vertex(int id) : id(id), hasTown(false), hasCity(false) {}
};

class Edge
{
private:
    Vertex *start;
    Vertex *end;
    int color = -1; // -1 means no one built a road/path
    int id; // id

public:
    Edge(Vertex *start, Vertex *end, int id) : start(start), end(end), hasRoad(false), id(id) {}
};

class hex
{
private:
    Vertex *vertices[6];
    Edge *edges[6];
    int number;
    int resource_type;
    string *my_assets; // town or city
    string *my_roads;  // road/path
public:
    hex(Vertex *vertices[6], Edge *edges[6], int resource_type, int number)
    {
        for (int i = 0; i < 6; i++)
        {
            this->vertices[i] = vertices[i];
            this->edges[i] = edges[i];
        }
        this->resource_type = resource_type;
        this->number = number;
    }

    string get_resource_type(
        return resource_type;) void set_resource_type(string resource_type)
    {
        this->resource_type = resource_type;
    }


    void set_number(int number)
    {
        this->number = number;
    }
    void set_my_assets(string *my_assets)
    {
        this->my_assets = my_assets;
    }
    void set_my_roads(string *my_roads)
    {
        this->my_roads = my_roads;
    }
};