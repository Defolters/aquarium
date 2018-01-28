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
    Aquarium aquarium(70, Coordinates(700, 500, 0));

	Texture plankton = Texture();
	plankton.loadFromFile("plankton.png");
    Texture fish = Texture();
	fish.loadFromFile("fish.png");
    Texture fish1 = Texture();
	fish1.loadFromFile("fish1.png");
	Display display = Display(&aquarium, &plankton, &fish, &fish1);
#endif // TEST_CREATE

#ifdef TEST_ADD
    aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(250,250,0));
    aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(550,150,0));
    aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(10,250,0));
    aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(100,150,0));

    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(250,200,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(310,310,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(250,200,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(100,150,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(100,100,0));

    aquarium.addCreature(LifeType::CARNIVOREFISH, Gene(LifeType::CARNIVOREFISH), Coordinates(100,400,0));
    aquarium.addCreature(LifeType::CARNIVOREFISH, Gene(LifeType::CARNIVOREFISH), Coordinates(200,400,0));
    for (auto creature : aquarium.getListOfCreatures())
    {
        MAIN_FIELD.AddObject(creature);
        creature->initGraphics(display.getTexture(creature->getType()));
    }
#endif // TEST_ADD

#ifdef TEST_PLAY
    aquarium.startGame(true, 500, &display);
#endif // TEST_PLAY

    std::cin.get();
    return 0;
}