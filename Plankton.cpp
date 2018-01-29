#include "Plankton.h"
#include <random>


Plankton::Plankton(Gene gene, Coordinates position, unsigned int id)
    : Creature(LifeType::PLANKTON, gene, LifeType::PLANKTON, position, id), mt(rd())
{
	that = this;
    
}


Plankton::~Plankton()
{
}

bool Plankton::thinkAboutIt(std::list<Creature*>& creatures, Coordinates borders)
{
    /*если мы не достигли цели, то ничего не меняем
    если достигли, то ставим новую цель*/
    if (getPosition().getDistance(direction) < 10+gene.speed)
    {
        std::uniform_int_distribution<int> distx(0, borders.x);
        direction.x = distx(mt);
        std::uniform_int_distribution<int> disty(0, borders.y);
        direction.y = disty(mt);
        std::uniform_int_distribution<int> distz(0, borders.z);
        direction.z = distz(mt);
        return true;
    }
    else
    {
        return false;
    }
}

bool Plankton::reproduce(std::list<Creature*>& creatures)
{
    //если период прошел, то делимся, проверки на задание нет, ибо планктон
    if (reproductionReady == gene.reproductionPeriod)
    {
        reproductionReady = 0;
        throwEvent(position, EventType::BIRTH, this);
        return true;
    }
    else
    {
        return false;
    }

}
