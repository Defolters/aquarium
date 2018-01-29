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

    Texture background = Texture();
	background.loadFromFile("background.png");
	Texture plankton = Texture();
	plankton.loadFromFile("plankton.png");
    Texture fish = Texture();
	fish.loadFromFile("fish.png");
    Texture fish1 = Texture();
	fish1.loadFromFile("fish1.png");
	Display display = Display(&aquarium, &plankton, &fish, &fish1, &background);
#endif // TEST_CREATE

#ifdef TEST_ADD
    aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(180,100,0));
    aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(180,150,0));
    aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(180,125,0));
    aquarium.addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(180,150,0));

    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(400,200,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(400,310,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(400,200,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(400,150,0));
    aquarium.addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(400,100,0));

    aquarium.addCreature(LifeType::CARNIVOREFISH, Gene(LifeType::CARNIVOREFISH), Coordinates(100,400,0));
    aquarium.addCreature(LifeType::CARNIVOREFISH, Gene(LifeType::CARNIVOREFISH), Coordinates(100,400,0));
    aquarium.addCreature(LifeType::CARNIVOREFISH, Gene(LifeType::CARNIVOREFISH), Coordinates(100,350,0));
    for (auto creature : aquarium.getListOfCreatures())
    {
        MAIN_FIELD.AddObject(creature);
        creature->initGraphics(display.getTexture(creature->getType()));
    }
#endif // TEST_ADD

#ifdef TEST_PLAY
    std::cin.get();
    aquarium.startGame(true, 500, &display);
#endif // TEST_PLAY

    std::cin.get();
    return 0;
}