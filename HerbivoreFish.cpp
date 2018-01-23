#include "HerbivoreFish.h"



HerbivoreFish::HerbivoreFish(Coordinates position)
    : Fish(LifeType::HERBIVOREFISH, LifeType::PLANKTON, position)
{
	that = this;
}

HerbivoreFish::~HerbivoreFish()
{
}
