#include "Fish.h"



Fish::Fish(LifeType type, LifeType prey)
    : Creature(type, prey, 20, 10, 5, 5, 5, 1)
{
}

Fish::~Fish()
{
}

bool Fish::thinkAboutIt(std::list<Creature*>& creatures)
{
    return false;
}

bool Fish::eat()
{
    return false;
}

bool Fish::reproduce()
{
    return false;
}
