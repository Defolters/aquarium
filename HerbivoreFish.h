#pragma once
#include "Fish.h"
#include "LifeType.h"
class HerbivoreFish :
    public Fish
{
public:
    HerbivoreFish();
    virtual ~HerbivoreFish();
private:
    LifeType type = LifeType::HERBIVOREFISH;
};

