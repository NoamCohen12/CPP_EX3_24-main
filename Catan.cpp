#include "hex.hpp"

Catan::Catan(Player &p1, Player &p2, Player &p3)
{
    players[0] = &p1;
    players[1] = &p2;
    players[2] = &p3;
    order_resources();
    order_turns();
}

void Catan::order_resources()

{
    int resources[NUM_RESOURCES] = {SHEEP, SHEEP, SHEEP, SHEEP, WOOD, WOOD, WOOD, WOOD, HAY, HAY, HAY, HAY, RED_STONE, RED_STONE, RED_STONE, WHITE_STONE, WHITE_STONE, WHITE_STONE, DESERT};
    int count = 0;

    srand(time(0)); // Seed the random number generator once

    while (count < NUM_RESOURCES)
    {
        int randomIndex = rand() % NUM_RESOURCES;
        if (resources[randomIndex] != 0)
        {
            int type = resources[randomIndex];
            hex[count]->set_number(type); // Set the number to the Hex object
            resources[randomIndex] = 0;
            count++;
        }
    }
}
void Catan::order_turns()
{
    srand(time(0)); // Seed the random number generator once
    int randomIndex = rand() % 3;
    players[randomIndex]->set_turn(1);
    players[(randomIndex + 1) % 3]->set_turn(2);
    players[(randomIndex + 2) % 3]->set_turn(3);
}

void Catan::intilition_board()
{
    Hex *hex[NUM_RESOURCES];
Hex[0] = new Hex(vertices[0], edges[0], DESERT, 0);



}
Catan::~Catan() {
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        delete hex[i];
    }

    for (int i = 0; i < NUM_VERTICES; ++i) {
        delete vertices[i];
    }
}

