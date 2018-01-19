#include "LifeManager.h"
#include <iostream>
#include "Aquarium.h"

LifeManager::LifeManager(Aquarium * aquarium, std::list<Creature*>& creatures) : aquarium(aquarium), days(0), creatures(creatures)
{
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
    //for each think about it
    for (auto creature : creatures)
    {
        creature->thinkAboutIt(creatures);
    }
}

void LifeManager::onEating() const
{
    //for each eat
    //auto creatures = aquarium->getListOfCreatures();
    // ÈÑÏĞÀÂÈÒÜ ÏĞÎÕÎÆÄÅÍÈÅ ÏÎ ÖÈÊËÓ ÍÀ ÑËÓ×ÀÉ ÓÄÀËÅÍÈß
    /*auto end = creatures.end();
    for (auto iter = creatures.begin(); iter != end; iter++)
    {
    aquarium->removeCreature(0);
    std::cout << "removed!" << std::endl;
    iter = creatures.begin();
    end = creatures.end();
    }*/
}

void LifeManager::onReproducing() const
{
    //for each reproduce
    //auto creatures = aquarium->getListOfCreatures();
    // ÈÑÏĞÀÂÈÒÜ ÏĞÎÕÎÆÄÅÍÈÅ ÏÎ ÖÈÊËÓ ÍÀ ÑËÓ×ÀÉ ÓÄÀËÅÍÈß
    /*auto end = creatures.end();
    for (auto iter = creatures.begin(); iter != end; iter++)
    {
    aquarium->removeCreature(0);
    std::cout << "removed!" << std::endl;
    end = creatures.end();
    }*/
}

void LifeManager::onMoving() const
{
    //auto creatures = aquarium->getListOfCreatures();
    //for each move
}

void LifeManager::dayPassed()
{
    //for each reduce life and increase hunger
    //auto creatures = aquarium->getListOfCreatures();
}

void LifeManager::onKilling() const
{
    //for each kill if it should die
    // ÈÑÏĞÀÂÈÒÜ ÏĞÎÕÎÆÄÅÍÈÅ ÏÎ ÖÈÊËÓ ÍÀ ÑËÓ×ÀÉ ÓÄÀËÅÍÈß
    //auto end = 
    /*for (auto iter = creatures.begin(); iter != creatures.end(); ++iter)
    {
    aquarium->removeCreature(0);
    std::cout << "removed!" << std::endl;
    //iter = creatures.begin();
    //end = creatures.end();
    }*/
}

void LifeManager::printState() const
{
    //print some state
}
