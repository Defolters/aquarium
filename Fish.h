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
    Fish();
    virtual ~Fish();
private:
	// я так понимаю что просто рыб все равно нет, это абстрактный родтиель так что тип лучше потом ставить
};

#endif  //! FISH_H