#include "Aquarium.h"
#include <iostream>

Aquarium::Aquarium(int capacity, Coordinates borders)
    : capacity(capacity), borders(borders), manager(LifeManager(this, creatures))
{
    // выделить размер для листа.
}

Aquarium::~Aquarium()
{
}

void Aquarium::startGame(bool isForever, int ticks)
{
    manager.startGame(isForever, ticks);
}

bool Aquarium::addCreature(LifeType type)
{
    if (creatures.size() < capacity)
    {
        if (type == LifeType::PLANKTON) 
        {
            creatures.push_back(new Plankton());
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
            creatures.push_back(new CarnivoreFish());
        }
        else
        {
            creatures.push_back(new HerbivoreFish());
        }
        return true;
    }
    else
    {
        std::cout << "I can't add fish, because aquarium is full" << std::endl;
        return false;
    }
    
}

bool Aquarium::removeCreature(int index)
{
    if (index > creatures.size()-1)
    {
        std::cout << "No such index in creatures" << std::endl  ;
        return false;
    }

    // определить с начала искать или с конца (зависит от того, к чему ближе индекс)
    // ..

    // пройтись по листу
    auto iter = creatures.begin();
    for (int i = 0; i < index; i++)
    {
        iter++;
    }

    //удалить 
    creatures.erase(iter);
    return false;
}

void Aquarium::setCapacity(int capacity)
{
    this->capacity = capacity;
}

int Aquarium::getCapacity() const
{
    return capacity;
}

void Aquarium::setBorders(Coordinates borders)
{
    this->borders = borders;
}

Coordinates Aquarium::getBorders() const
{
    return borders;
}

int Aquarium::getNumberOfCreatures() const
{
    return creatures.size();
}

std::list<Creature*>& Aquarium::getListOfCreatures()
{
    return creatures;
}
