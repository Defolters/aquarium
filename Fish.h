#ifndef FISH_H
#define FISH_H
#include "Creature.h"
/*  стоит ли делать разделение от обычной рыбы? или плотоядную наследовать от травоядной?
    Fish -> HerbivoreFish (травоядная)
    Fish -> CarnivoreFish (плотоядная)
    или 
    HerbivoreFish -> CarnivoreFish
*/
class Fish :
    public Creature
{
public:
    Fish();
    virtual ~Fish();
};

#endif  //! FISH_H