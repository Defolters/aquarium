#include "Aquarium.h"



Aquarium::Aquarium() 
    : capacity(0), borders(Coordinates()), numberOfCreatures(0)
{
}

Aquarium::Aquarium(int capacity, Coordinates borders)
    : capacity(capacity), borders(borders), numberOfCreatures(0)
{
    // выделить размер для листа.
}

Aquarium::~Aquarium()
{
}

void Aquarium::startGame()
{
    //manager.startGame();
}

void Aquarium::stopGame()
{
    //manager.stopGame();
}

bool Aquarium::addCreature(LifeType type)
{
    if (numberOfCreatures < capacity)
    {
        //добавить рыбу
    }
    else
    {
        return false;
    }
    
}

bool Aquarium::removeCreature(int index)
{
    //убрать рыбу из листа
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
}

Coordinates Aquarium::getBorders() const
{
    return borders;
}

int Aquarium::getNumberOfCreatures() const
{
    return numberOfCreatures;
}

std::vector<Creature*>& Aquarium::getListOfCreatures()
{
    return creatures;
}
