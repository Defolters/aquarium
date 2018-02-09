#ifndef CARNIVORE_FISH_H
#define CARNIVORE_FISH_H
#include "Fish.h"
/*!
\brief Класс, реализующий плотоядную рыбу
*/
class CarnivoreFish :
    public Fish
{
public:
    CarnivoreFish(Gene gene, Coordinates position, unsigned int id);
    virtual ~CarnivoreFish();
};

#endif //! CARNIVORE_FISH_H