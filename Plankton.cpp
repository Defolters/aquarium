#include "Plankton.h"



Plankton::Plankton()
    : Creature(LifeType::PLANKTON, LifeType::PLANKTON, 10, 10, 2, 5, 0, 1)
{
}


Plankton::~Plankton()
{
}

bool Plankton::thinkAboutIt(std::list<Creature*>& creatures)
{
    /*
    если мы не достигли цели, то ничего не меняем
    если достигли, то ставим новую цель*/
    if (getPositionAqua() == direction)
    {
        // достигли желаемого направления, ищем новое
        direction.x = rand() % 10; //aquarium borders
        direction.y = rand() % 10;
        direction.z = rand() % 10;
    }
    else
    {
    }
    return true;
}

bool Plankton::reproduce()
{
    //если период прошел, то делимся, проверки на задание нет, ибо планктон
    if (reproductionReady == reproductionPeriod)
    {
        // добавляем нового планктона в аквариум
        reproductionReady = 0;
        return true;
    }
    else
    {
        return false;
    }
    
}
