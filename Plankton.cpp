#include "Plankton.h"



Plankton::Plankton(Coordinates position)
    : Creature(LifeType::PLANKTON, LifeType::PLANKTON, position, 5, 5, 2, 5, 0, 1)
{
	that = this;
}


Plankton::~Plankton()
{
}

bool Plankton::thinkAboutIt(std::list<Creature*>& creatures)
{
    /*
    если мы не достигли цели, то ничего не меняем
    если достигли, то ставим новую цель*/
    if (getPosition() == direction)
    {
        // достигли желаемого направления, ищем новое
        direction.x = rand() % 10; //aquarium borders should be here!!!
        direction.y = rand() % 10;
        direction.z = rand() % 10;
        std::cout << "New direction: " <<direction.toString() << std::endl;
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
    if (reproductionReady == reproductionPeriod)
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
