#ifndef FISH_H
#define FISH_H
#include "Creature.h"

/*!
\brief Класс, реализующий анимацию

нужны комменты к полям и методам, чтобы я мог помочь и понять.
*/
class Fish abstract :
    public Creature
{
protected:
    Fish(LifeType type, LifeType prey);
    virtual ~Fish();
};

#endif  //! FISH_H