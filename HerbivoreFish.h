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
    HerbivoreFish(Gene gene, Coordinates position, unsigned int id);
    virtual ~HerbivoreFish();
};
#endif //! HERBIVORE_FISH_H
