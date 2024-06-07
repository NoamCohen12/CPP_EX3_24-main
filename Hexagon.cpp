#ifndef HEXAGON_HPP
#define HEXAGON_HPP
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

class Edge;  // Forward declaration of Edge

// Vertex class to represent a corner of a hexagon
class Vertex {
   private:
    int color;  // -1 means no one built a town/city
    bool hasCity;
    bool hasTown;
    int id;  // id
    vector<Edge *> my_edges;

   public:
    Vertex(int id) : id(id), hasCity(false), hasTown(false), color(-1) {}
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
    void set_town() {
        hasTown = true;
    }
    void set_city() {
        hasCity = true;
    }
    int get_id() {
        return id;
    }
    int get_color() {
        return color;
    }
    void set_color(int color) {
        this->color = color;
    }
    bool get_hasCity() {
        return hasCity;
    }
    bool get_hasTown() {
        return hasTown;
    }
    vector<Edge *> &get_edges() {
        return this->my_edges;
    }
    void delete_town() {
        hasTown = false;
        cout << "town switch" << endl;
    }
    ~Vertex() {}
};
////////////////////////////////////////////////////////////////////////////////////////////
class Edge {
   private:
    Vertex *start;
    Vertex *end;
    vector<Vertex *> my_vertex;
    int color;     // -1 means no one built a road/path
    int id;        // id
    bool hasRoad;  // true if there is a road/path

   public:
    Edge(Vertex *start, Vertex *end, int id) : start(start), end(end), hasRoad(false), id(id), color(-1) {
        my_vertex.push_back(start);
        my_vertex.push_back(end);
    }
    void set_color(int color) {
        this->color = color;
    }
    int get_color() {
        return color;
    }
    int get_id() {
        return id;
    }
    void set_road() {
        hasRoad = true;
    }
    Vertex *get_vertex(int idVertex) {
        return my_vertex[idVertex];
    }

    ~Edge() {
       delete start;
         delete end;
    }
    };
    ////////////////////////////////////////////////////////////////////////////////////////////
    class Hexagon {
       private:
        vector<Vertex *> my_vertex;
        vector<Edge *> my_edges;
        int id;
        int number_rund;  // random number
        int resource_type;
        string *my_assets;  // town or city
        string *my_roads;   // road/path
       public:
        Hexagon(Edge *edge1, Edge *edge2, Edge *edge3, Edge *edge4, Edge *edge5, Edge *edge6, Vertex *vertex1, Vertex *vertex2, Vertex *vertex3, Vertex *vertex4,
                Vertex *vertex5, Vertex *vertex6, int id) {
            my_vertex.push_back(vertex1);
            my_vertex.push_back(vertex2);
            my_vertex.push_back(vertex3);
            my_vertex.push_back(vertex4);
            my_vertex.push_back(vertex5);
            my_vertex.push_back(vertex6);
            my_edges.push_back(edge1);
            my_edges.push_back(edge2);
            my_edges.push_back(edge3);
            my_edges.push_back(edge4);
            my_edges.push_back(edge5);
            my_edges.push_back(edge6);
            this->id = id;
        }

        int get_resource_type() {
            return this->resource_type;
        }
        void set_resource_type(int resource_type) {
            this->resource_type = resource_type;
        }
        void set_number(int number_rund) {
            this->number_rund = number_rund;
        }

        void set_my_assets(string *my_assets) {
            this->my_assets = my_assets;
        }
        void set_my_roads(string *my_roads) {
            this->my_roads = my_roads;
        }

        Vertex *get_vertex(int idVertex) {
            for (int i = 0; i < my_vertex.size(); i++) {
                if (my_vertex[i]->get_id() == idVertex) {
                    return my_vertex[i];
                }
            }
            return NULL;
        }
        Edge *get_edge(int idEdge) {
            for (int i = 0; i < my_edges.size(); i++) {
                if (my_edges[i]->get_id() == idEdge) {
                    return my_edges[i];
                }
            }
            return NULL;
        }
        vector<Vertex *> &get_vertexs() {
            return my_vertex;
        }
        int get_number() {
            return number_rund;
        }
        void print_edges() {
            for (int i = 0; i < my_edges.size(); i++) {
                cout << "Edge " << i << " has color " << my_edges[i]->get_color() << endl;
            }
        }
        // to string as hexagon in a middle represnt tye resource type and number and on vertices
        // write if there is a town or city
        // on the edge write if there is a road/path wich color
        void to_string() {
            cout << "   " << my_vertex[0]->get_id() << endl;
        }

        ~Hexagon() { 
            for (int i = 0; i < my_vertex.size(); i++) {
                delete my_vertex[i];
            }
            for (int i = 0; i < my_edges.size(); i++) {
                delete my_edges[i];
            }
        }
    };
#endif  // HEXAGON_HPP