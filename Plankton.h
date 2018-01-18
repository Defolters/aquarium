#ifndef PLANKTON_H
#define PLANKTON_H
#include "Creature.h"
/*!
\brief Класс, реализующий анимацию

нужны комменты к полям и методам, чтобы я мог помочь и понять.
*/
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