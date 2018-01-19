#ifndef CARNIVORE_FISH_H
#define CARNIVORE_FISH_H
#include "Fish.h"
/*!
\brief Класс, реализующий анимацию

нужны комменты к полям и методам, чтобы я мог помочь и понять.
*/
class CarnivoreFish :
    public Fish
{
public:
    CarnivoreFish(int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed);
    virtual ~CarnivoreFish();
private:
    LifeType target = LifeType::HERBIVOREFISH;
};

#endif //! CARNIVORE_FISH_H