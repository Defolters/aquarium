#ifndef CARNIVORE_FISH_H
#define CARNIVORE_FISH_H
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

#endif //! CARNIVORE_FISH_H