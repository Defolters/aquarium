// main.cpp : Defines the entry point for the console application.
//
#include "Creature.h"
#include <iostream>

int main()
{
	auto cret = new Creature();
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
	std::cin.get();
    return 0;
}

