#ifndef CARNIVORE_FISH_H
#define CARNIVORE_FISH_H
#include "Fish.h"
/*!
\brief Класс, реализующий плотоядную рыбу

сабж
*/
class CarnivoreFish :
    public Fish
{
public:
    CarnivoreFish();
    virtual ~CarnivoreFish();
};

#endif //! CARNIVORE_FISH_H