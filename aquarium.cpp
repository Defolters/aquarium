#include "Aquarium.h"
#include <iostream>


Aquarium::Aquarium() 
    : capacity(0), borders(Coordinates()), numberOfCreatures(0)
{
}

Aquarium::Aquarium(int capacity, Coordinates borders)
    : capacity(capacity), borders(borders), numberOfCreatures(0)
{
    // �������� ������ ��� �����.
}

Aquarium::~Aquarium()
{
}

void Aquarium::startGame(bool isForever, int ticks)
{
    //manager.startGame();
}

bool Aquarium::addCreature(LifeType type)
{
    if (numberOfCreatures < capacity)
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
    // ���������� � ������ ������ ��� � ����� (������� �� ����, � ���� ����� ������)
    // �������� �� �����
    auto iter = creatures.begin();
    for (int i = 0; i < index; i++)
    {
        iter++;
    }
    creatures.erase(iter);
    //������� 
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

std::list<Creature*>& Aquarium::getListOfCreatures()
{
    return creatures;
}
