#ifndef FISH_H
#define FISH_H
#include "Creature.h"
/*  стоит ли делать разделение от обычной рыбы? или плотоядную наследовать от травоядной?
    Creature -> Fish -> HerbivoreFish (травоядная)
    Creature -> Fish -> CarnivoreFish (плотоядная)
    или 
    Creature -> HerbivoreFish -> CarnivoreFish
*/
class Fish :
    public Creature
{
public:
    Fish();
    virtual ~Fish();
private:
    std::string name = "Fish";
};

#endif  //! FISH_H