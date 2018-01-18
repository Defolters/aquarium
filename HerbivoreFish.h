#ifndef CARNIVORE_FISH_H
#define CARNIVORE_FISH_H
#include "Fish.h"
#include "LifeType.h"
/*!
\brief Класс, реализующий анимацию

нужны комменты к полям и методам, чтобы я мог помочь и понять.
*/
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

