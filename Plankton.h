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
    std::string name = "Plankton";
};

#endif  //! PLANKTON_H