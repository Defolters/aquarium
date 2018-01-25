// main.cpp : Defines the entry point for the console application.
// 
#include <iostream>
#include "Aquarium.h"
#include "Plankton.h"
#include "Display.h"
#include <random>
#include <chrono>
#include <thread>
//ловить ивенты для аквариума
//вынести проверку в аквариум
#define TEST_CREATE
#define TEST_ADD
#define TEST_PLAY

int main()
{
#ifdef TEST_CREATE
    Aquarium aquarium(25, Coordinates(500, 500, 1));
	
	Texture plankton = Texture();
	plankton.loadFromFile("plankton.png");
	Display display = Display(&aquarium, &plankton);
#endif // TEST_CREATE

#ifdef TEST_ADD
    aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(250,250,0));
    for (auto creature : aquarium.getListOfCreatures())
    {
        MAIN_FIELD.AddObject(creature);
        creature->initGraphics(display.getTexture(creature->getType()));
    }
    
#endif // TEST_ADD

#ifdef TEST_PLAY
    aquarium.startGame(false, 500, &display);

#endif // TEST_PLAY

    std::cin.get();
    return 0;
}