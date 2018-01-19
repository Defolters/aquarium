// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Aquarium.h"
#define TEST_CASE_1
int main()
{
    
#ifdef TEST_CASE_1
    Aquarium aquarium(10, Coordinates(10, 10, 10));
    aquarium.addCreature(LifeType::PLANKTON);
    aquarium.addCreature(LifeType::HERBIVOREFISH);
    aquarium.addCreature(LifeType::CARNIVOREFISH);
    aquarium.removeCreature(2);
    aquarium.removeCreature(2);
    aquarium.removeCreature(1);
    aquarium.removeCreature(0);
    aquarium.startGame(true, 50);

#endif // TEST_CASE_1

    std::cin.get();

    return 0;
}

