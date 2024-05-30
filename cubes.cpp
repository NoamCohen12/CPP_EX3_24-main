#include <iostream>
#include <random>
#include <stdio.h>
#include <time.h>


#define MAX 12
#define MIN 2
class cubes
{

public:
    // this function return random num between 2 to 12

    int roll()
    {
        srand(time(0)); // use current time as seed for random generator
        int randNum = rand() % (MAX - MIN + 1) + MIN;
        std::cout << "you get : " << randNum << std::endl;
        return randNum;
    }
};