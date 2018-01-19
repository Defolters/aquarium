#ifndef HERBIVORE_FISH_H
#define HERBIVORE_FISH_H
#include "Fish.h"
#include "LifeType.h"
/*!
\brief Класс, реализующий травоядную рыбу

сабж
*/
class HerbivoreFish :
    public Fish
{
public:
    HerbivoreFish();
    virtual ~HerbivoreFish();
};
#endif //! HERBIVORE_FISH_H

