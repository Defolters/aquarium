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
    printState(); // print state of the day
    dayPassed(); // reduce life and increase hunger
    onKilling(); // kill fishes, which died of old age or hunger
}

void LifeManager::onThinking() const
{
    //for each think about it
    for (auto creature : creatures)
    {
        creature->thinkAboutIt(creatures, aquarium->getBorders());
    }
}

void LifeManager::onEating() const
{
    // учитывать то, что кого-то могут съесть
    //for each eat
    for (auto creature : creatures) 
    {
        if (creature->eat(creatures)) 
        {
            
            aquarium->removeCreature(creature->getPreyId());
            //throwEvent((*i)->getPosition(), EventType::DEATH, *i);
            //creatures.erase(i++);  // alternatively, i = items.erase(i);
        }
    }
    //auto creatures = aquarium->getListOfCreatures();
    // ИСПРАВИТЬ ПРОХОЖДЕНИЕ ПО ЦИКЛУ НА СЛУЧАЙ УДАЛЕНИЯ
    /* auto end = creatures.end();
    for (auto iter = creatures.begin(); iter != creatures.end(); iter++)
    {
    //aquarium->removeCreature(0);
    //std::cout << "removed!" << std::endl;
    //iter = creatures.begin();
    end = creatures.end();*/
    
}

void LifeManager::onReproducing()
{
    //for each reproduce
    for (auto creature : creatures)
    {
        creature->reproduce(creatures);
        //auto event = getManagerEvent();
        std::shared_ptr<LifeEvent> evM = getManagerEvent();
        if (evM != nullptr)
        {
            // здесь можно получать гены родителей и создать нового ребенка
            aquarium->addCreature(evM->holder->getType(), Gene(evM->holder->getType()), evM->holder->getPosition());
            newborns++;
        }
		/*if (creature->reproduce(creatures))
		{
			// здесь добавляем нового планктона в аквариум
            //throwEvent(newCreature->getPosition(), EventType::BIRTH, newCreature);
            //getManagerEvent();
            auto event = getManagerEvent();

			aquarium->addCreature(creature->getType(), Gene(creature->getType()), creature->getPosition());
			newborns++;
		}*/
    }
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
    day++;
}

void LifeManager::onKilling()
{
    //for each kill if it should die (of oldage or hunger)
    // check list and kill
    //std::list<Creature*>::iterator i = creatures.begin();
    // бросать ивенты
    //for (auto creature : creatures)
    auto i = creatures.begin();
    while (i != creatures.end())
    {
        (*i++)->isShouldDead();
        std::shared_ptr<LifeEvent> evM = getManagerEvent();
        if (evM != nullptr)
        {
            // здесь можно получать гены родителей и создать нового ребенка
            aquarium->removeCreature(evM->holder->getId());
            //aquarium->addCreature(evM->holder->getType(), Gene(evM->holder->getType()), evM->holder->getPosition());
            //newborns++;
        }
    }
    /*while (i != creatures.end())
    {
        //bool isActive = (*i)->update();
        if ((*i)->isDeadOfAge())
        {
            aquarium->removeCreature((*i++)->getId());
			//throwEvent((*i)->getPosition(), EventType::DEATH, *i);
            //creatures.erase(i++);  // alternatively, i = items.erase(i);
            
            deadOfAge++;
        }
        else if ((*i)->isDeadOfHunger())
        {
            aquarium->removeCreature((*i++)->getId());
			//throwEvent((*i)->getPosition(), EventType::DEATH, *i);
            //creatures.erase(i++);  // alternatively, i = items.erase(i);

            deadOfHunger++;
        }
        else ++i;
    }*/
}

void LifeManager::printState()
{
    //print some state (например, сколько рыб умерло)
    //system("CLS");
    std::cout << "Number of creatures in aquarium: " << aquarium->getNumberOfCreatures() << 
        "\nToday dead of hunger: "<<deadOfHunger<<
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
