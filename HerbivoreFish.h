#ifndef CARNIVORE_FISH_H
#define CARNIVORE_FISH_H
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
#endif //! CARNIVORE_FISH_H

