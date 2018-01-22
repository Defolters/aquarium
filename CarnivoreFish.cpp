#include "CarnivoreFish.h"



CarnivoreFish::CarnivoreFish(Coordinates position)
    : Fish(LifeType::CARNIVOREFISH, LifeType::HERBIVOREFISH, position)
{
}

CarnivoreFish::~CarnivoreFish()
{
}
