#include "Fish.h"



Fish::Fish(LifeType type, LifeType prey, Coordinates position)
    : Creature(type, prey, position, 20, 10, 5, 5, 5, 1)
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

bool Fish::reproduce(std::list<Creature*>& creatures)
{
    return false;
}
