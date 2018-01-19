#ifndef FISH_H
#define FISH_H
#include "Creature.h"

/*!
\brief Класс, реализующий рыбу

сабж
*/
class Fish abstract :
    public Creature
{
public:
    Fish(LifeType type, LifeType prey);
    virtual ~Fish();
    virtual void thinkAboutIt(std::list<Creature*>& creatures) override;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual void eat() override;//!< восстанавливает голод, ест только кого-то рангом ниже, при этом создание рангом ниже должно умереть, или вообще не ест (планктон, например)
    virtual bool reproduce() override;  //!< размножается (как добавить новую рыбу в аквариум?)
    virtual Coordinates move() override; //!< передвигает жертву к цели, если в этом ходу мы будем двигаться
};

#endif  //! FISH_H