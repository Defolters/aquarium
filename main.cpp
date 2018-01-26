// main.cpp : Defines the entry point for the console application.
// 
#include <iostream>
#include "Aquarium.h"
#include "Plankton.h"
#include "Display.h"
#include <random>
#include <chrono>
#include <thread>
//make shared all
#define TEST_CREATE
#define TEST_ADD
#define TEST_PLAY

int main()
{
    
#ifdef TEST_CREATE
    Aquarium aquarium(25, Coordinates(500, 500, 1));

	Texture plankton = Texture();
	plankton.loadFromFile("plankton.png");
    Texture fish = Texture();
	fish.loadFromFile("fish.png");
	Display display = Display(&aquarium, &plankton, &fish, &fish);
#endif // TEST_CREATE

#ifdef TEST_ADD
    //aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(250,250,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(250,250,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(250,250,0));
    for (auto creature : aquarium.getListOfCreatures())
    {
        MAIN_FIELD.AddObject(creature);
        //MAIN_FIELD.AddObject(creature.get());
        creature->initGraphics(display.getTexture(creature->getType()));
    }
#endif // TEST_ADD

#ifdef TEST_PLAY
    aquarium.startGame(false, 500, &display);
#endif // TEST_PLAY

    std::cin.get();
    return 0;
}