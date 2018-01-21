// main.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Aquarium.h"
#include "Plankton.h"
#include <time.h>       /* time */

#define TEST_CREATE
#define TEST_ADD
//#define TEST_REMOVE
#define TEST_PLAY
//#define TEST_EVENT
int main()
{
    srand(time(NULL));
#ifdef TEST_EVENT
	auto cret = new Plankton();
	Coordinates coord(1, 1, 3);
	throwEvent(coord, EventType::BIRTH, cret);
	throwEvent(Coordinates(1,2,1), EventType::KILL, cret);
	
	std::cout << "Manager event's coordinates: " << std::endl;
	std::shared_ptr<LifeEvent> evM = getManagerEvent();
	std::cout << evM->place.toString() << std::endl;

	evM = getManagerEvent();
	std::cout << evM->place.toString() << std::endl;

	std::cout << "Display event's coordinates: " << std::endl;
	evM = getDisplayEvent();
	std::cout << evM->place.toString() << std::endl;

	evM = getDisplayEvent();
	std::cout << evM->place.toString() << std::endl;

	std::cout << "done" << std::endl;
#endif // TEST_EVENT

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

/*
// main.cpp : Defines the entry point for the console application.
//


int main()
{


return 0;
}


*/
