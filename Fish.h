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
    Fish(LifeType type, int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed);
    virtual ~Fish();
private:
    LifeType target; //!< what I eat
	// я так понимаю что просто рыб все равно нет, это абстрактный родтиель так что тип лучше потом ставить
};

#endif  //! FISH_H