#include "Fish.h"



Fish::Fish(LifeType type, LifeType prey)
    : Creature(type, prey, 20, 10, 5, 5, 5, 1)
{
}

Fish::~Fish()
{
}

void Fish::thinkAboutIt(std::list<Creature*>& creatures)
{
}

void Fish::eat()
{
}

bool Fish::reproduce()
{
    return false;
}

Coordinates Fish::move()
{
    return Coordinates();
}
