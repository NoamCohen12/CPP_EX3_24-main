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
    int x, y;       // Coordinates
    Vertex(int x, int y) : x(x), y(y) {}
    get_x() { return x; }
    get_y() { return y; }
};

class Edge
{
private:
    Vertex start;
    Vertex end;
    int color = -1; //-1 means no one built a road
public:
    Edge(Vertex start, Vertex end) { start(atart.get_x(),
                                           start.get_y()),
                                     end(end.get_x(), end.get_y()) }

    {
    }
};

class hexagon
{
private:
    Vertex *vertices[6];
    Edge *edges[6];
    string resource_type;
    string *my_assets; // town or city
    string *my_roads;  // road/path
public:
    hexagon(Vertex *vertices[6], Edge *edges[6], string resource_type)
    {
        for (int i = 0; i < 6; i++)
        {
            this->vertices[i] = vertices[i];
            this->edges[i] = edges[i];
        }
        this->resource_type = resource_type;
    }
    int *get_vertices(Vertex vertex);
    int *get_edges(Edge edge);

    string get_resource_type(
        return resource_type;);

    void set_resource_type(string resource_type)
    {
        this->resource_type = resource_type;
    }
    void set_my_assets(string asset);
    void set_my_roads(string road);
};