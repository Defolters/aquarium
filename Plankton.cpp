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
    if (getPositionAqua() != direction)
    {
    }
    else
    {
        // генерируем новое направление
    }
    
}

bool Plankton::reproduce()
{
    //если период прошел, то делимся, проверки на задание нет, ибо планктон
    if (reproductionReady == reproductionPeriod)
    {
        // размножаемся 
        reproductionReady = 0;
    }
    else
    {
        return false;
    }
    
}
