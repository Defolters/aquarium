#include "Aquarium.h"
#include <iostream>
#include "Display.h"
Aquarium::Aquarium(int capacity, Coordinates borders)
    : capacity(capacity), lastId(0), borders(borders), manager(LifeManager(this, creatures)), numberOfCarnivore(0), numberOfHarbivore(0), numberOfPlankton(0)
{
}

Aquarium::~Aquarium()
{
}

void Aquarium::bind()
{
	//TODO
	binded = true;
}

void Aquarium::startGame(bool isForever, int ticks, Display* display_)
{
    display = display_;
    int a = 0;
    //SYSTEMTIME st;
	//GetSystemTime(&st);

    while (isForever || ticks)
    {
        //std::cin.get();
        if (a == 10)//6000000)
        {
            display->DrawAquarium();
            manager.makeTurn();
            if (!(numberOfCarnivore && numberOfHarbivore && numberOfPlankton))
            {
                std::cout << "STOP!";
                break;
            }
            a = 0;
        }
        
        //display->DrawAquarium();
        //manager.makeTurn();
        ticks--;
        a++;
    }
    
}

bool Aquarium::addCreature(LifeType type, Gene gene, Coordinates coord)
{
    if (creatures.size() < capacity)
    {
		Creature* newCreature;
        //std::shared_ptr<Creature> newCreature1;
        if (type == LifeType::PLANKTON) 
        {
			newCreature = new Plankton(gene, coord, lastId);
            numberOfPlankton++;
            //newCreature1 = std::make_shared<Plankton>(gene, coord, lastId);
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
            
			newCreature = new CarnivoreFish(gene, coord, lastId);
            numberOfCarnivore++;
            //newCreature1 = std::make_shared<CarnivoreFish>(gene, coord, lastId);
        }
        else
        {
            numberOfHarbivore++;
			newCreature = new HerbivoreFish(gene, coord, lastId);
            //newCreature1 = std::make_shared<HerbivoreFish>(gene, coord, lastId);
        }
        /*std::shared_ptr<Creature> add = new Plankton(gene, coord, lastId);; //= std::make_shared<Creature>(newCreature);
        add.reset(new );
        delete newCreature;
        if (add == nullptr)
            std::cout << "ITWORKS";
        */
		creatures.push_back(newCreature);
        //creatures1.push_back(newCreature1);

        throwEvent(newCreature->getPosition(), EventType::BIRTH, newCreature);
        getManagerEvent();

        lastId++;
        return true;
    }
    else
    {
        //std::cout << "I can't add fish, because aquarium is full" << std::endl;
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
            if ((*iter)->getType() == LifeType::PLANKTON)
            {
                numberOfPlankton--;
            }
            else if ((*iter)->getType() == LifeType::CARNIVOREFISH)
            {
                numberOfCarnivore--;
            }
            else
            {
                numberOfHarbivore--;
            }
            //throwEvent((*i)->getPosition(), EventType::DEATH, *i);
            if (!binded)
                delete *iter;
                //MAIN_FIELD.RemoveObject(*iter);
            //throwEvent((*iter)->getPosition(), EventType::DEATH, *iter);
            //getManagerEvent();
            creatures.erase(iter);
            //std::cout << "remove ID: " << id << std::endl;
            return true;
        }
    }
    return false;
}

bool Aquarium::removeCreature(std::list<Creature*>::iterator iterator)
{
    if ((*iterator)->getType() == LifeType::PLANKTON)
        {
            numberOfPlankton--;
        }
    else if ((*iterator)->getType() == LifeType::CARNIVOREFISH)
        {
            numberOfCarnivore--;
        }
    else
        {
            numberOfHarbivore--;
        }

    if (!binded)
        delete *iterator;
    
    creatures.erase(iterator);
    return true;
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
