#include "Plankton.h"



Plankton::Plankton(Gene gene, Coordinates position, unsigned int id)
    : Creature(LifeType::PLANKTON, gene, LifeType::PLANKTON, position, id)
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
    if (getPosition() == direction)
    {
        direction.x = rand() % borders.x;
        direction.y = rand() % borders.y;
        direction.z = rand() % borders.z;
        std::cout << "New direction: " << direction.toString() << std::endl;
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
        // здесь добавляем нового планктона в аквариум
        throwEvent(position, EventType::BIRTH, this);
        reproductionReady = 0;
        return true;
    }
    else
    {
        return false;
    }

}
