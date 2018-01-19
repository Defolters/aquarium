#include "LifeManager.h"
#include <iostream>
#include "Aquarium.h"
LifeManager::LifeManager(Aquarium * aquarium) : aquarium(aquarium), days(0)
{
    std::cout << "lm\n";

}

LifeManager::~LifeManager()
{
}

void LifeManager::startGame(bool isForever, int ticks)
{
    while (isForever || ticks)
    {
        std::cout << ticks << " TICK!" << std::endl;
        ticks--;
        onThinking(); // each fish think about plans on the future
        onEating(); // each fish eat, if can
        onReproducing(); //each fish reproducing if can
        onMoving(); // each fish moving if can
        dayPassed(); // reduce life and increase hunger
        onKilling(); // kill fishes, which died of old age or hunger
        printState();
    }
}

void LifeManager::onThinking() const
{
    // здесь такое не нужно, ибо на этом ходу убийств и рождений не будет
    auto creatures = aquarium->getListOfCreatures();
    auto end = creatures.end();
    for (auto iter = creatures.begin(); iter != end; iter++)
    {
        aquarium->removeCreature(0);
        std::cout << "removed!" << std::endl;
        end = creatures.end();
    }
    //for (int i =0;;)
    //{    }
    //for each think about it
}

void LifeManager::onKilling() const
{
    //for each think about it
}

void LifeManager::onMoving() const
{
    //for each think about it
}

void LifeManager::onEating() const
{
    //for each think about it
}

void LifeManager::onReproducing() const
{
    //for each think about it
}

void LifeManager::dayPassed()
{
    //for each think about it
}

void LifeManager::printState() const
{
    //for each think about it
}
