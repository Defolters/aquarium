#include "LifeManager.h"
#include <iostream>
#include "Aquarium.h"

LifeManager::LifeManager(Aquarium * aquarium, std::list<Creature*>& creatures) 
    : aquarium(aquarium), day(1), creatures(creatures), deadOfAge(0), deadOfHunger(0)
{
}

LifeManager::~LifeManager()
{
}

void LifeManager::startGame(bool isForever_, int ticks_)
{
	isForever = isForever_;
	ticks = ticks_;
    if (isForever || ticks)
    {
        std::cout << ticks << " TICK!" << std::endl;
        ticks--;
        if (day % 7 == 0)
			eventEveryWeek();
        onThinking(); // each fish think about plans on the future
        onEating(); // each fish eat, if can
        onReproducing(); //each fish reproducing if can
        onMoving(); // each fish moving if can
        dayPassed(); // reduce life and increase hunger
        onKilling(); // kill fishes, which died of old age or hunger
        printState();
        day++;
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
    // ИСПРАВИТЬ ПРОХОЖДЕНИЕ ПО ЦИКЛУ НА СЛУЧАЙ УДАЛЕНИЯ
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
    // ИСПРАВИТЬ ПРОХОЖДЕНИЕ ПО ЦИКЛУ НА СЛУЧАЙ УДАЛЕНИЯ
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
}

void LifeManager::onKilling()
{
    //for each kill if it should die (of oldage or hunger)

    std::list<Creature*>::iterator i = creatures.begin();

    while (i != creatures.end())
    {
        //bool isActive = (*i)->update();
        if ((*i)->isDeadOfAge())
        {
			throwEvent((*i)->getPosition(), EventType::DEATH, *i);
            creatures.erase(i++);  // alternatively, i = items.erase(i);
            deadOfAge++;
        }
        else if ((*i)->isDeadOfHunger())
        {
			throwEvent((*i)->getPosition(), EventType::DEATH, *i);
            creatures.erase(i++);  // alternatively, i = items.erase(i);
            deadOfHunger++;
        }
        else ++i;
    }
}

void LifeManager::printState()
{
    //print some state (например, сколько рыб умерло)
    std::cout << "Number of creatures in aquarium: " << aquarium->getNumberOfCreatures() << 
        "\nToday dead of hunger: "<<deadOfHunger<<"\nToday dead of age: "<<deadOfAge<<std::endl;
    deadOfAge = 0;
    deadOfHunger = 0;
}

void LifeManager::eventEveryWeek() const
{
    std::cout << "Astrologers proclaim the week of References.\nThe number of references has doubled" << std::endl;
}
