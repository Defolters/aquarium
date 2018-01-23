#include "HerbivoreFish.h"



HerbivoreFish::HerbivoreFish(Gene gene, Coordinates position, unsigned int id)
    : Fish(LifeType::HERBIVOREFISH, gene, LifeType::PLANKTON, position, id)
{
	that = this;
}

HerbivoreFish::~HerbivoreFish()
{
}
