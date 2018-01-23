#include "CarnivoreFish.h"



CarnivoreFish::CarnivoreFish(Gene gene, Coordinates position, unsigned int id)
    : Fish(LifeType::CARNIVOREFISH, gene, LifeType::HERBIVOREFISH, position, id)
{
	that = this;
}

CarnivoreFish::~CarnivoreFish()
{
}
