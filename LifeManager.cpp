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
    if (day % 7 == 0)
        eventEveryWeek();
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
    //for each think about it
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
    //for each reproduce
    for (auto creature : creatures)
    {
        if (creature->reproduce(creatures))
        {
            aquarium->addCreature(creature->getType(), Gene(creature->getType()), creature->getPosition());
            newborns++;

            std::shared_ptr<LifeEvent> evM = getManagerEvent();
            /*if (evM != nullptr)
            {
                // здесь можно получать гены родителей и создать нового ребенка
                aquarium->addCreature(evM->holder->getType(), Gene(evM->holder->getType()), evM->holder->getPosition());
                newborns++;
            }*/
        }
}

void LifeManager::onMoving() const
{
    //for each move
    for (auto creature : creatures)
    {
        creature->move();
    }
}

void LifeManager::dayPassed()
{
    //for each reduce life and increase hunger
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
    //print some state (например, сколько рыб умерло)
    //system("CLS");
    std::cout << "Day: ";
    std::cout << day << std::endl;
    std::cout << "Number of creatures in aquarium: " << aquarium->getNumberOfCreatures() << 
        //"\nToday dead of hunger: "<<deadOfHunger<<
        "\nToday dead of age: "<<deadOfAge <<
        "\nToday newborns: " << newborns <<
        "\nToday eaten: " << eaten << "\n" <<
        std::endl;
    deadOfAge = 0;
    deadOfHunger = 0;
    newborns = 0;
    eaten = 0;
}

void LifeManager::eventEveryWeek() const
{
    //std::cout << "Astrologers proclaim the week of References.\nThe number of references has doubled" << std::endl;
}
