// main.cpp : Defines the entry point for the console application.
// 
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "Aquarium.h"
#include "Plankton.h"
#include "Display.h"

#define TEST_CREATE
#define TEST_ADD
#define TEST_PLAY

int main()
{
    
#ifdef TEST_CREATE
    Aquarium aquarium(170, Coordinates(1000, 700 , 0));

	Display display = Display(&aquarium);
#endif // TEST_CREATE

#ifdef TEST_ADD
    aquarium.initialize(10, 8, 6);
#endif // TEST_ADD

#ifdef TEST_PLAY
    std::cin.get();
    aquarium.startGame(true, 500, &display);
#endif // TEST_PLAY

    std::cin.get();
    return 0;
}