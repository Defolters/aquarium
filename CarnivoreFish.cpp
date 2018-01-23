#include "CarnivoreFish.h"



CarnivoreFish::CarnivoreFish(Coordinates position)
    : Fish(LifeType::CARNIVOREFISH, LifeType::HERBIVOREFISH, position)
{
	that = this;
}

CarnivoreFish::~CarnivoreFish()
{
}
