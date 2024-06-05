#include "Catan.hpp"
#include "board.hpp"

Catan::Catan(Player &p1, Player &p2, Player &p3, board &game_board) {
    players[0] = &p1;
    players[1] = &p2;
    players[2] = &p3;
    order_resources(game_board);
    order_turns();
    order_number(game_board);

}

void Catan::order_number(board game_board) {
    int numbers[NUM_HEX] = {10, 2, 9, 12, 6, 4, 10, 9, 11, -1, 3, 8, 8, 3, 4, 5, 5, 6, 11};
    int count = 0;


    while (count < NUM_HEX) {
        int randomIndex = rand() % NUM_HEX;
        if (numbers[randomIndex] != -1) {
            int number = numbers[randomIndex];

            game_board.get_board()[count]->set_number(number);  
           // Hexagon[count]->set_number(number);  // Set the number to the Hex object
            numbers[randomIndex] = 0;
            count++;
        }
    }
}

void Catan::order_resources(board game_board)

{
    int resources[NUM_HEX] = {SHEEP, SHEEP, SHEEP, SHEEP, WOOD, WOOD, WOOD, WOOD, HAY, HAY, HAY, HAY, RED_STONE, RED_STONE, RED_STONE, WHITE_STONE, WHITE_STONE, WHITE_STONE, DESERT};
    int count = 0;

    srand(time(0));  // Seed the random number generator once

    while (count < NUM_HEX) {
        int randomIndex = rand() % NUM_HEX;
        if (resources[randomIndex] != 0) {
            int type = resources[randomIndex];
                game_board.get_board()[count]->set_number(type);  

        //    Hexagon[count]->set_resource(type);  // Set the number to the Hex object
            resources[randomIndex] = 0;
            count++;
        }
    }
}
void Catan::order_turns() {
    srand(time(0));  // Seed the random number generator once
    int randomIndex = rand() % 3;
    players[randomIndex]->set_turn(1);
    players[(randomIndex + 1) % 3]->set_turn(2);
    players[(randomIndex + 2) % 3]->set_turn(3);
}


Catan::~Catan() {
   
}
