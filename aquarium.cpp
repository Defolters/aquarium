#include "Aquarium.h"



Aquarium::Aquarium() 
    : numberOfCreatures(0)
{
}


Aquarium::~Aquarium()
{
}

bool Aquarium::addCreature(LifeType type)
{
    return false;
}

bool Aquarium::removeCreature(int index)
{
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

int Aquarium::getNumberOfCreatures() const
{
    return numberOfCreatures;
}

std::vector<Creature*>& Aquarium::getListOfCreatures()
{
    return creatures;
}
