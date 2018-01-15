#ifndef PLANKTON_H
#define PLANKTON_H
#include "Creature.h"
class Plankton :
    public Creature
{
public:
    Plankton();
    virtual ~Plankton();
private:
    LifeType type = LifeType::PLANKTON;
};

#endif  //! PLANKTON_H