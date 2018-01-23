#include "CarnivoreFish.h"



CarnivoreFish::CarnivoreFish()
    : Fish(LifeType::CARNIVOREFISH, LifeType::HERBIVOREFISH)
{
	that = this;
}

CarnivoreFish::~CarnivoreFish()
{
}
