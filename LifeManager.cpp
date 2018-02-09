#include "LifeManager.h"
#include <iostream>
#include "Aquarium.h"
#include "Display.h"
LifeManager::LifeManager(Aquarium * aquarium, std::list<Creature*>& creatures) 
    : aquarium(aquarium), day(1), creatures(creatures), deadOfAge(0), deadOfHunger(0), newborns(0), eaten(0)
{
}

LifeManager::~LifeManager()
{
}

void LifeManager::makeTurn()
{
    onThinking(); // each fish think about plans on the future
    onEating(); // each fish eat, if can
    onReproducing(); //each fish reproducing if can
    onMoving(); // each fish moving if can
    dayPassed(); // reduce life and increase hunger
    onKilling(); // kill fishes, which died of old age or hunger
    printState(); // print state of the day
}

void LifeManager::onThinking() const
{
    for (auto creature : creatures)
    {
        creature->thinkAboutIt(creatures, aquarium->getBorders());
    }
}

void LifeManager::onEating()
{
    for (auto creature : creatures) 
    {
        if (creature->eat(creatures)) 
        {
            
            aquarium->removeCreature(creature->getPreyId());
            getManagerEvent();
            eaten++;
        }
    }    
}

void LifeManager::onReproducing()
{
    for (auto creature : creatures)
    {
        if (creature->reproduce(creatures))
        {
            aquarium->addCreature(creature->getType(), Gene(creature->getType()), creature->getPosition());
            newborns++;

            std::shared_ptr<LifeEvent> evM = getManagerEvent();
        }
    }
}

void LifeManager::onMoving() const
{
    for (auto creature : creatures)
    {
        creature->move();
    }
}

void LifeManager::dayPassed()
{
    for (auto creature : creatures)
    {
        creature->dayPassed();
    }
    day++;
}

void LifeManager::onKilling()
{
    auto i = creatures.begin();
    while (i != creatures.end())
    {
        (*i)->isShouldDead();
        std::shared_ptr<LifeEvent> evM = getManagerEvent();
        if (evM != nullptr)
        {
            aquarium->removeCreature(i++);
            deadOfAge++;
        }
        else i++;
    }
}

void LifeManager::printState()
{
    system("CLS");
    std::cout << "Day: " << day << std::endl
     << "Planktons: " << aquarium->getNumberOfP() << std::endl
    << "Herbivore Fish: " << aquarium->getNumberOfHF() << std::endl
    << "Carnivore Fish: " << aquarium->getNumberOfCF() << std::endl;
    deadOfAge = 0;
    deadOfHunger = 0;
    newborns = 0;
    eaten = 0;
}
