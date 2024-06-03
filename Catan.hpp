#ifndef CATAN_HPP
#define CATAN_HPP
#include "player.hpp"
#include "hex.hpp"
#include "edge.hpp"
#include "vertex.hpp"
#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#define num_of_hex 19;

class Catan
{

private:
    Hex *hex[num_of_hex];
    Player *players[3];
    // there are 53 vertexes in the game
    Vertex *vertices0;
    Vertex *vertices1;
    Vertex *vertices2;
    Vertex *vertices3;
    Vertex *vertices4;
    Vertex *vertices5;
    Vertex *vertices6;
    Vertex *vertices7;
    Vertex *vertices8;
    Vertex *vertices9;
    Vertex *vertices10;
    Vertex *vertices11;
    Vertex *vertices12;
    Vertex *vertices13;
    Vertex *vertices14;
    Vertex *vertices15;
    Vertex *vertices16;
    Vertex *vertices17;
    Vertex *vertices18;
    Vertex *vertices19;
    Vertex *vertices20;
    Vertex *vertices21;
    Vertex *vertices22;
    Vertex *vertices23;
    Vertex *vertices24;
    Vertex *vertices25;
    Vertex *vertices26;
    Vertex *vertices27;
    Vertex *vertices28;
    Vertex *vertices29;
    Vertex *vertices30;
    Vertex *vertices31;
    Vertex *vertices32;
    Vertex *vertices33;
    Vertex *vertices34;
    Vertex *vertices35;
    Vertex *vertices36;
    Vertex *vertices37;
    Vertex *vertices38;
    Vertex *vertices39;
    Vertex *vertices40;
    Vertex *vertices41;
    Vertex *vertices42;
    Vertex *vertices43;
    Vertex *vertices44;
    Vertex *vertices45;
    Vertex *vertices46;
    Vertex *vertices47;
    Vertex *vertices48;
    Vertex *vertices49;
    Vertex *vertices50;
    Vertex *vertices51;
    Vertex *vertices52;
    // there are 72 edges in the game
    Edge *edges0 = new Edge(vertices3, vertices0, 0);
    Edge *edges1 = new Edge(vertices0, vertices4, 1);
    Edge *edges2 = new Edge(vertices4, vertices1, 2);
    Edge *edges3 = new Edge(vertices1, vertices5, 3);
    Edge *edges4 = new Edge(vertices5, vertices2, 4);
    Edge *edges5 = new Edge(vertices2, vertices6, 5);
    Edge *edges6 = new Edge(vertices3, vertices7, 6);
    Edge *edges7 = new Edge(vertices4, vertices8, 7);
    Edge *edges8 = new Edge(vertices5, vertices9, 8);
    Edge *edges9 = new Edge(vertices6, vertices10, 9);
    
    Edge *edges10 = new Edge(vertices11, vertices7, 10);
    Edge *edges11 = new Edge(vertices7, vertices12, 11);
    Edge *edges12 = new Edge(vertices12, vertices8, 12);

    Edge *edges13 = new Edge(vertices8, vertices13, 13);
    Edge *edges14 = new Edge(vertices13, vertices9, 14);
    Edge *edges15 = new Edge(vertices9, vertices14, 15);
    Edge *edges16 = new Edge(vertices14, vertices10, 16);
    Edge *edges17 = new Edge(vertices10, vertices15, 17);


    Edge *edges18 = new Edge(vertices11, vertices16, 18);
    Edge *edges19 = new Edge(vertices12, vertices17, 19);
    Edge *edges20 = new Edge(vertices13, vertices18, 20);


    Edge *edges21 = new Edge(vertices14, vertices19, 21);


    Edge *edges22 = new Edge(vertices15, vertices20, 22);

    Edge *edges23 = new Edge(vertices21, vertices1, 23);
    Edge *edges24 = new Edge(vertices1, vertices22, 24);

    Edge *edges25 = new Edge(vertices22, vertices17, 25);

    Edge *edges26 = new Edge(vertices17, vertices23, 26);

    Edge *edges27 = new Edge(vertices23, vertices18, 27);

    Edge *edges28 = new Edge(vertices18, vertices14, 28);

    Edge *edges29 = new Edge(vertices24, vertices19, 29);

    Edge *edges30 = new Edge(vertices19, vertices25, 30);

    Edge *edges31 = new Edge(vertices25, vertices20, 31);

    Edge *edges32 = new Edge(vertices20, vertices26, 32);

    Edge *edges33 = new Edge(vertices21, vertices27, 33);

    Edge *edges34 = new Edge(vertices22, vertices28, 34);
    Edge *edges35 = new Edge(vertices23, vertices29, 35);

    Edge *edges36 = new Edge(vertices24, vertices30, 36);

    Edge *edges37 = new Edge(vertices25, vertices31, 37);

    Edge *edges38 = new Edge(vertices26, vertices32, 38);

    Edge *edges39 = new Edge(vertices27, vertices33, 39);

    Edge *edges40 = new Edge(vertices33, vertices28, 40);

    Edge *edges41 = new Edge(vertices28, vertices34, 41);

    Edge *edges42 = new Edge(vertices34, vertices29, 42);

    Edge *edges43 = new Edge(vertices29, vertices35, 43);

    Edge *edges44 = new Edge(vertices35, vertices30, 44);

    Edge *edges45 = new Edge(vertices30, vertices36, 45);
    Edge *edges46 = new Edge(vertices36, vertices31, 46);

    Edge *edges47 = new Edge(vertices31, vertices37, 47);
    Edge *edges48 = new Edge(vertices37, vertices32, 48);
    Edge *edges49 = new Edge(vertices33, vertices38, 49);
    Edge *edges50= new Edge(vertices34, vertices39, 50);
    Edge *edges51= new Edge(vertices35, vertices40, 51);
    Edge *edges52= new Edge(vertices36, vertices41, 52);
    Edge *edges53= new Edge(vertices37, vertices42, 53);
    Edge *edges54= new Edge(vertices38, vertices43, 54);
    Edge *edges55= new Edge(vertices43, vertices39, 55);
    Edge *edges56= new Edge(vertices39, vertices44, 56);
    Edge *edges57= new Edge(vertices44, vertices40, 57);
    Edge *edges58= new Edge(vertices40, vertices45, 58);
    Edge *edges59= new Edge(vertices45, vertices41, 59);
    Edge *edges60= new Edge(vertices41, vertices46, 60);
    Edge *edges61= new Edge(vertices46, vertices42, 61);
    Edge *edges62= new Edge(vertices43, vertices47, 62);
    Edge *edges63= new Edge(vertices44, vertices48, 63);
    Edge *edges64= new Edge(vertices45, vertices49, 64);
    Edge *edges65= new Edge(vertices46, vertices50, 65);
    Edge *edges66= new Edge(vertices47, vertices51, 66);
    Edge *edges67= new Edge(vertices51, vertices48, 67);
    Edge *edges68= new Edge(vertices48, vertices52, 68);
    Edge *edges69= new Edge(vertices52, vertices49, 69);
    Edge *edges70= new Edge(vertices49, vertices53, 70);
    Edge *edges71= new Edge(vertices53, vertices50, 71);

public:
    Catan(Player &p1, Player &p2, Player &p3);
    void order_resources();
    void start_game();
    ~Catan();
}
#endif