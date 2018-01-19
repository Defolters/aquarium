#include "Plankton.h"



Plankton::Plankton()
    : Creature(LifeType::PLANKTON, LifeType::PLANKTON, 10, 10, 2, 5, 0, 1)
{
}


Plankton::~Plankton()
{
}

void Plankton::thinkAboutIt(std::list<Creature*>& creatures)
{
}

void Plankton::eat()
{
}

bool Plankton::reproduce()
{
    return false;
}

Coordinates Plankton::move()
{
    return Coordinates();
}

