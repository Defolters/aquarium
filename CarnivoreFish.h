#pragma once
#include "Fish.h"
class CarnivoreFish :
    public Fish
{
public:
    CarnivoreFish();
    virtual ~CarnivoreFish();
private:
    LifeType type = LifeType::CARNIVOREFISH;
};

