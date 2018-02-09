#include "Aquarium.h"
#include <random>
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
	binded = true;
}

void Aquarium::initialize(unsigned int numbP, unsigned int numbHF, unsigned int numbCF)
{
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution<int> distx(0, borders.x);
    std::uniform_int_distribution<int> disty(0, borders.y);
    
    
    for (unsigned int i = 0; i < numbCF; i++)
    {
        addCreature(LifeType::CARNIVOREFISH, Gene(LifeType::CARNIVOREFISH), Coordinates(distx(mt), disty(mt), 0));
    };
    for (unsigned int i = 0; i < numbHF; i++)
    {
        addCreature(LifeType::HERBIVOREFISH, Gene(LifeType::HERBIVOREFISH), Coordinates(distx(mt), disty(mt), 0));
    };
    for (unsigned int i = 0; i < numbP; i++)
    {
        addCreature(LifeType::PLANKTON, Gene(LifeType::PLANKTON), Coordinates(distx(mt), disty(mt), 0));
    };
}

void Aquarium::startGame(bool isForever, int ticks, Display* display_)
{
    display = display_;
    std::chrono::time_point<std::chrono::system_clock> start, start2, end1, end2;
    start = std::chrono::system_clock::now();
    while (isForever || ticks)
    {
        end1 = std::chrono::system_clock::now();
        if((std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start) > std::chrono::milliseconds(90))) 
        {
            start = std::chrono::system_clock::now();
            display->DrawAquarium();
            manager.makeTurn();
            if (!(numberOfCarnivore && numberOfHarbivore && numberOfPlankton))
            {
                end1 = std::chrono::system_clock::now();
                
                std::cout << "STOP!";
                manager.printState();
                std::cout << "\n\nProgram: " << ((double)std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start).count())/1000 << "seconds\n";
                break;
            }
        }
        ticks--;
    }
    
}

bool Aquarium::addCreature(LifeType type, Gene gene, Coordinates coord)
{
    if((creatures.size() < capacity) && 
        ((!(type==LifeType::PLANKTON)) || (numberOfPlankton <= 4*numberOfHarbivore)) && 
        ((!(type==LifeType::HERBIVOREFISH)) || (numberOfHarbivore <= 4*numberOfCarnivore))
        )   
    {
        if (((type == LifeType::CARNIVOREFISH) && (numberOfHarbivore!=0) && (numberOfCarnivore > 0.4*(numberOfHarbivore))) ||
            ((type == LifeType::HERBIVOREFISH) && (numberOfPlankton!=0) && (numberOfHarbivore > 1*(numberOfPlankton))))
        {
            return false;
        }

		Creature* newCreature;
        if (type == LifeType::PLANKTON) 
        {
			newCreature = new Plankton(gene, coord, lastId);
            numberOfPlankton++;
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
			newCreature = new CarnivoreFish(gene, coord, lastId);
            numberOfCarnivore++;
        }
        else
        {
            numberOfHarbivore++;
			newCreature = new HerbivoreFish(gene, coord, lastId);
        }
		creatures.push_back(newCreature);

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

            if (!binded)
                delete *iter;
            
            creatures.erase(iter);
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

int Aquarium::getNumberOfP()
{
    return numberOfPlankton;
}

int Aquarium::getNumberOfHF()
{
    return numberOfHarbivore;
}

int Aquarium::getNumberOfCF()
{
    return numberOfCarnivore;
}
