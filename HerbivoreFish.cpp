#include "HerbivoreFish.h"



HerbivoreFish::HerbivoreFish()
    : Fish(LifeType::HERBIVOREFISH, LifeType::PLANKTON)
{
	that = this;
}

HerbivoreFish::~HerbivoreFish()
{
}
