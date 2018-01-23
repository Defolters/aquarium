#include "Aquarium.h"
#include <iostream>

Aquarium::Aquarium(int capacity, Coordinates borders)
    : capacity(capacity), lastId(0), borders(borders), manager(LifeManager(this, creatures))
{
    //creatures.resize(capacity); выдает ошибку
}

Aquarium::~Aquarium()
{
}

void Aquarium::bind()
{
	//TODO
	binded = true;
}

void Aquarium::startGame(bool isForever, int ticks)
{
    manager.startGame(isForever, ticks);
}

bool Aquarium::addCreature(LifeType type, Gene gene, Coordinates coord)
{
    if (creatures.size() < capacity)
    {
		Creature* newCreature;
        if (type == LifeType::PLANKTON) 
        {
			newCreature = new Plankton(gene, coord, lastId);
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
			newCreature = new CarnivoreFish(gene, coord, lastId);
        }
        else
        {
			newCreature = new HerbivoreFish(gene, coord, lastId);
        }
		creatures.push_back(newCreature);
        std::cout << "ID: " << lastId << std::endl;
        lastId++;
		if (binded)
		{
			MAIN_FIELD.AddObject(newCreature);
			throwEvent(newCreature->getPosition(), EventType::BIRTH, newCreature);
		}
        return true;
    }
    else
    {
        std::cout << "I can't add fish, because aquarium is full" << std::endl;
        return false;
    }
    
}

bool Aquarium::removeCreature(unsigned int id)
{
    //перебрать лист, пока не найдем нужную рыбу с id, затем очистить ее 

    for (auto iter = creatures.begin(); iter != creatures.end(); iter++)
    {
        if (id == (*iter)->getId())
        {
            creatures.erase(iter);
            if (binded)
                MAIN_FIELD.RemoveObject(*iter);
            std::cout << "remove ID: " << id << std::endl;
            return true;
        }
    }
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
