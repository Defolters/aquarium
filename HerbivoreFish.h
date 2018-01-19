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
    HerbivoreFish(int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed);
    virtual ~HerbivoreFish();
private:
    LifeType target = LifeType::PLANKTON;
};
#endif //! CARNIVORE_FISH_H

