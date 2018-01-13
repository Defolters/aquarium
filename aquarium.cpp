#include "Aquarium.h"



Aquarium::Aquarium() 
    : numberOfCreatures(0)
{
}


Aquarium::~Aquarium()
{
}

bool Aquarium::addCreature(Type type)
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

int Aquarium::getCapacity()
{
    return capacity;
}

int Aquarium::getNumberOfCreatures()
{
    return numberOfCreatures;
}

std::vector<Creature*> Aquarium::getListOfCreatures()
{
    return creatures;
}
