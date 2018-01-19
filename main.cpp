// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Aquarium.h"
#define TEST_CREATE
#define TEST_ADD
//#define TEST_REMOVE
#define TEST_PLAY
int main()
{
    
#ifdef TEST_CREATE
    Aquarium aquarium(10, Coordinates(10, 10, 10));
#endif // TEST_CREATE
#ifdef TEST_ADD
    aquarium.addCreature(LifeType::PLANKTON);
    aquarium.addCreature(LifeType::HERBIVOREFISH);
    aquarium.addCreature(LifeType::CARNIVOREFISH);
#endif // TEST_ADD
#ifdef TEST_REMOVE
    aquarium.removeCreature(2);
    aquarium.removeCreature(2);
    aquarium.removeCreature(1);
    aquarium.removeCreature(0);
#endif // TEST_REMOVE
#ifdef TEST_PLAY
    aquarium.startGame(false, 10);
#endif // TEST_PLAY


    std::cin.get();

    return 0;
}

