#include "board.hpp"

board::board(){
    this->hexagons = initialization_bord();
   
}


vector<Hexagon*> board::initialization_bord() {
    // יצירת הקודקודים
    vector<Vertex*> vertices;
    for (int i = 0; i < 54; ++i) {
        vertices.push_back(new Vertex(i));
    }

    // יצירת הקצוות
    vector<Edge*> edges;
    edges.push_back(new Edge(vertices[3], vertices[0], 0));
    edges.push_back(new Edge(vertices[0], vertices[4], 1));
    edges.push_back(new Edge(vertices[4], vertices[1], 2));
    edges.push_back(new Edge(vertices[1], vertices[5], 3));
    edges.push_back(new Edge(vertices[5], vertices[2], 4));
    edges.push_back(new Edge(vertices[2], vertices[6], 5));
    edges.push_back(new Edge(vertices[3], vertices[7], 6));
    edges.push_back(new Edge(vertices[4], vertices[8], 7));
    edges.push_back(new Edge(vertices[5], vertices[9], 8));
    edges.push_back(new Edge(vertices[6], vertices[10], 9));
    edges.push_back(new Edge(vertices[11], vertices[7], 10));
    edges.push_back(new Edge(vertices[7], vertices[12], 11));
    edges.push_back(new Edge(vertices[12], vertices[8], 12));
    edges.push_back(new Edge(vertices[8], vertices[13], 13));
    edges.push_back(new Edge(vertices[13], vertices[9], 14));
    edges.push_back(new Edge(vertices[9], vertices[14], 15));
    edges.push_back(new Edge(vertices[14], vertices[10], 16));
    edges.push_back(new Edge(vertices[10], vertices[15], 17));
    edges.push_back(new Edge(vertices[11], vertices[16], 18));
    edges.push_back(new Edge(vertices[12], vertices[17], 19));
    edges.push_back(new Edge(vertices[13], vertices[18], 20));
    edges.push_back(new Edge(vertices[14], vertices[19], 21));
    edges.push_back(new Edge(vertices[15], vertices[20], 22));
    edges.push_back(new Edge(vertices[21], vertices[1], 23));
    edges.push_back(new Edge(vertices[1], vertices[22], 24));
    edges.push_back(new Edge(vertices[22], vertices[17], 25));
    edges.push_back(new Edge(vertices[17], vertices[23], 26));
    edges.push_back(new Edge(vertices[23], vertices[18], 27));
    edges.push_back(new Edge(vertices[18], vertices[14], 28));
    edges.push_back(new Edge(vertices[24], vertices[19], 29));
    edges.push_back(new Edge(vertices[19], vertices[25], 30));
    edges.push_back(new Edge(vertices[25], vertices[20], 31));
    edges.push_back(new Edge(vertices[20], vertices[26], 32));
    edges.push_back(new Edge(vertices[21], vertices[27], 33));
    edges.push_back(new Edge(vertices[22], vertices[28], 34));
    edges.push_back(new Edge(vertices[23], vertices[29], 35));
    edges.push_back(new Edge(vertices[24], vertices[30], 36));
    edges.push_back(new Edge(vertices[25], vertices[31], 37));
    edges.push_back(new Edge(vertices[26], vertices[32], 38));
    edges.push_back(new Edge(vertices[27], vertices[33], 39));
    edges.push_back(new Edge(vertices[33], vertices[28], 40));
    edges.push_back(new Edge(vertices[28], vertices[34], 41));
    edges.push_back(new Edge(vertices[34], vertices[29], 42));
    edges.push_back(new Edge(vertices[29], vertices[35], 43));
    edges.push_back(new Edge(vertices[35], vertices[30], 44));
     edges.push_back(new Edge(vertices[30], vertices[36], 45));
    edges.push_back(new Edge(vertices[36], vertices[31], 46));
    edges.push_back(new Edge(vertices[31], vertices[37], 47));
    edges.push_back(new Edge(vertices[37], vertices[32], 48));
    edges.push_back(new Edge(vertices[33], vertices[38], 49));
    edges.push_back(new Edge(vertices[34], vertices[39], 50));
    edges.push_back(new Edge(vertices[35], vertices[40], 51));
    edges.push_back(new Edge(vertices[36], vertices[41], 52));
    edges.push_back(new Edge(vertices[37], vertices[42], 53));
    edges.push_back(new Edge(vertices[38], vertices[43], 54));
    edges.push_back(new Edge(vertices[43], vertices[39], 55));
    edges.push_back(new Edge(vertices[39], vertices[44], 56));
    edges.push_back(new Edge(vertices[44], vertices[40], 57));
    edges.push_back(new Edge(vertices[40], vertices[45], 58));
    edges.push_back(new Edge(vertices[45], vertices[41], 59));
    edges.push_back(new Edge(vertices[41], vertices[46], 60));
    edges.push_back(new Edge(vertices[46], vertices[42], 61));
    edges.push_back(new Edge(vertices[43], vertices[47], 62));
    edges.push_back(new Edge(vertices[44], vertices[48], 63));
    edges.push_back(new Edge(vertices[45], vertices[49], 64));
    edges.push_back(new Edge(vertices[46], vertices[50], 65));
    edges.push_back(new Edge(vertices[47], vertices[51], 66));
    edges.push_back(new Edge(vertices[51], vertices[48], 67));
    edges.push_back(new Edge(vertices[48], vertices[52], 68));
    edges.push_back(new Edge(vertices[52], vertices[49], 69));
    edges.push_back(new Edge(vertices[49], vertices[53], 70));
    edges.push_back(new Edge(vertices[53], vertices[50], 71));

    // חיבור קצוות לקודקודים
    vertices[0]->addEdge2(edges[0], edges[1]);
    vertices[1]->addEdge2(edges[2], edges[3]);
    vertices[2]->addEdge2(edges[4], edges[5]);
    vertices[3]->addEdge2(edges[6], edges[0]);
    vertices[4]->addEdge3(edges[1], edges[7], edges[2]);
    vertices[5]->addEdge3(edges[3], edges[4], edges[8]);
    vertices[6]->addEdge2(edges[5], edges[9]);
    vertices[7]->addEdge3(edges[6], edges[10], edges[11]);
    vertices[8]->addEdge3(edges[7], edges[12], edges[13]);
    vertices[9]->addEdge3(edges[8], edges[14], edges[15]);
    vertices[10]->addEdge3(edges[9], edges[16], edges[17]);
    vertices[11]->addEdge2(edges[10], edges[18]);
    vertices[12]->addEdge3(edges[11], edges[19], edges[12]);
    vertices[13]->addEdge3(edges[13], edges[20], edges[14]);
    vertices[14]->addEdge3(edges[15], edges[21], edges[16]);
    vertices[15]->addEdge2(edges[17], edges[22]);
    vertices[16]->addEdge3(edges[18], edges[23], edges[24]);
    vertices[17]->addEdge3(edges[19], edges[25], edges[26]);
    vertices[18]->addEdge3(edges[20], edges[27], edges[28]);
    vertices[19]->addEdge3(edges[21], edges[29], edges[30]);
    vertices[20]->addEdge3(edges[22], edges[31], edges[32]);
    vertices[21]->addEdge2(edges[33], edges[23]);
    vertices[22]->addEdge3(edges[24], edges[34], edges[25]);
    vertices[23]->addEdge3(edges[26], edges[35], edges[27]);
    vertices[24]->addEdge3(edges[28], edges[36], edges[29]);
    vertices[25]->addEdge3(edges[30], edges[37], edges[31]);
    vertices[26]->addEdge2(edges[32], edges[38]);
    vertices[27]->addEdge2(edges[33], edges[39]);
    vertices[28]->addEdge3(edges[34], edges[40], edges[41]);
    vertices[29]->addEdge3(edges[35], edges[42], edges[43]);
    vertices[30]->addEdge3(edges[36], edges[44], edges[45]);
    vertices[31]->addEdge3(edges[37], edges[46], edges[47]);
    vertices[32]->addEdge2(edges[38], edges[48]);
    vertices[33]->addEdge3(edges[39], edges[40], edges[49]);
    vertices[34]->addEdge3(edges[41], edges[50], edges[42]);
    vertices[35]->addEdge3(edges[43], edges[51], edges[44]);
    vertices[36]->addEdge3(edges[45], edges[52], edges[46]);
    vertices[37]->addEdge3(edges[47], edges[53], edges[48]);
    vertices[38]->addEdge2(edges[49], edges[54]);
    vertices[39]->addEdge3(edges[50], edges[55], edges[56]);
    vertices[40]->addEdge3(edges[51], edges[57], edges[58]);
    vertices[41]->addEdge3(edges[52], edges[59], edges[60]);
    vertices[42]->addEdge2(edges[61], edges[53]);
    vertices[43]->addEdge3(edges[54], edges[62], edges[55]);
    vertices[44]->addEdge3(edges[56], edges[63], edges[57]);
    vertices[45]->addEdge3(edges[58], edges[64], edges[59]);
    vertices[46]->addEdge3(edges[60], edges[65], edges[61]);
    vertices[47]->addEdge2(edges[66], edges[62]);
    vertices[48]->addEdge3(edges[63], edges[67], edges[68]);
    vertices[49]->addEdge3(edges[64], edges[69], edges[70]);
    vertices[50]->addEdge2(edges[65], edges[71]);
    vertices[51]->addEdge2(edges[66], edges[67]);
    vertices[52]->addEdge2(edges[68], edges[69]);
    vertices[53]->addEdge2(edges[70], edges[71]);

    // יצירת משושים
    vector<Hexagon*> hexagons;
    hexagons.push_back(new Hexagon(edges[0], edges[1], edges[7], edges[6], edges[11], edges[12], vertices[0], vertices[12], vertices[4], vertices[3], vertices[7], vertices[8], 0));
    hexagons.push_back(new Hexagon(edges[2], edges[3], edges[8], edges[7], edges[13], edges[14], vertices[1], vertices[13], vertices[5], vertices[4], vertices[8], vertices[9], 1));
    hexagons.push_back(new Hexagon(edges[4], edges[5], edges[9], edges[8], edges[15], edges[16], vertices[2], vertices[6], vertices[5], vertices[9], vertices[10], vertices[14], 2));
    hexagons.push_back(new Hexagon(edges[10], edges[11], edges[18], edges[19], edges[24], edges[23], vertices[7], vertices[11], vertices[22], vertices[16], vertices[12], vertices[17], 3));
    hexagons.push_back(new Hexagon(edges[12], edges[13], edges[20], edges[19], edges[27], edges[26], vertices[8], vertices[12], vertices[23], vertices[17], vertices[23], vertices[18], 4));
    hexagons.push_back(new Hexagon(edges[14], edges[15], edges[21], edges[20], edges[28], edges[29], vertices[9], vertices[13], vertices[24], vertices[18], vertices[24], vertices[19], 5));
    hexagons.push_back(new Hexagon(edges[16], edges[17], edges[22], edges[21], edges[30], edges[31], vertices[10], vertices[14], vertices[15], vertices[20], vertices[25], vertices[19], 6));
    hexagons.push_back(new Hexagon(edges[23], edges[24], edges[33], edges[34], edges[40], edges[39], vertices[16], vertices[21], vertices[33], vertices[27], vertices[22], vertices[28], 7));
    hexagons.push_back(new Hexagon(edges[25], edges[26], edges[35], edges[34], edges[42], edges[41], vertices[17], vertices[22], vertices[23], vertices[29], vertices[34], vertices[29], 8));
    hexagons.push_back(new Hexagon(edges[27], edges[28], edges[36], edges[35], edges[43], edges[44], vertices[18], vertices[23], vertices[24], vertices[30], vertices[35], vertices[30], 9));
    hexagons.push_back(new Hexagon(edges[29], edges[30], edges[37], edges[36], edges[45], edges[46], vertices[19], vertices[24], vertices[25], vertices[31], vertices[36], vertices[31], 10));
    hexagons.push_back(new Hexagon(edges[31], edges[32], edges[38], edges[37], edges[47], edges[48], vertices[20], vertices[26], vertices[25], vertices[32], vertices[37], vertices[32], 11));
    hexagons.push_back(new Hexagon(edges[33], edges[34], edges[39], edges[35], edges[49], edges[50], vertices[27], vertices[28], vertices[33], vertices[38], vertices[33], vertices[34], 12));
    hexagons.push_back(new Hexagon(edges[35], edges[36], edges[41], edges[42], edges[51], edges[52], vertices[28], vertices[29], vertices[34], vertices[39], vertices[40], vertices[35], 13));
    hexagons.push_back(new Hexagon(edges[37], edges[38], edges[43], edges[41], edges[52], edges[53], vertices[30], vertices[32], vertices[31], vertices[36], vertices[41], vertices[37], 14));
    hexagons.push_back(new Hexagon(edges[39], edges[40], edges[50], edges[49], edges[54], edges[55], vertices[33], vertices[38], vertices[39], vertices[43], vertices[43], vertices[44], 15));
    hexagons.push_back(new Hexagon(edges[41], edges[42], edges[51], edges[50], edges[56], edges[57], vertices[34], vertices[39], vertices[40], vertices[44], vertices[45], vertices[44], 16));
    hexagons.push_back(new Hexagon(edges[43], edges[44], edges[52], edges[51], edges[58], edges[59], vertices[35], vertices[40], vertices[45], vertices[41], vertices[46], vertices[45], 17));
    hexagons.push_back(new Hexagon(edges[45], edges[46], edges[53], edges[52], edges[60], edges[61], vertices[36], vertices[41], vertices[46], vertices[42], vertices[47], vertices[46], 18));
    hexagons.push_back(new Hexagon(edges[49], edges[50], edges[55], edges[54], edges[62], edges[63], vertices[39], vertices[43], vertices[44], vertices[48], vertices[47], vertices[48], 19));
    hexagons.push_back(new Hexagon(edges[51], edges[52], edges[57], edges[56], edges[64], edges[65], vertices[40], vertices[44], vertices[45], vertices[49], vertices[48], vertices[49], 20));
    hexagons.push_back(new Hexagon(edges[53], edges[54], edges[58], edges[57], edges[66], edges[67], vertices[42], vertices[46], vertices[45], vertices[50], vertices[49], vertices[50], 21));
    hexagons.push_back(new Hexagon(edges[63], edges[64], edges[69], edges[68], edges[66], edges[70], vertices[48], vertices[49], vertices[52], vertices[49], vertices[51], vertices[52], 22));
    hexagons.push_back(new Hexagon(edges[67], edges[68], edges[71], edges[70], edges[65], edges[66], vertices[50], vertices[52], vertices[53], vertices[52], vertices[51], vertices[53], 23));
    

    return hexagons;
}