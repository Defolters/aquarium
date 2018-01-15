#ifndef FISH_H
#define FISH_H
#include "Creature.h"
/*  стоит ли делать разделение от обычной рыбы? или плотоядную наследовать от травоядной?
    Creature -> Fish -> HerbivoreFish (травоядная)
    Creature -> Fish -> CarnivoreFish (плотоядная)
    или 
    Creature -> HerbivoreFish -> CarnivoreFish //<- это уже всеядная получается, лучше разделить
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