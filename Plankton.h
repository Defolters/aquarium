#ifndef PLANKTON_H
#define PLANKTON_H
#include "Creature.h"
/*!
\brief Класс, реализующий планктоны

сабж
*/
class Plankton :
    public Creature
{
public:
    Plankton();
    virtual ~Plankton();

    virtual void thinkAboutIt(std::list<Creature*>& creatures) override;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual void eat() override;//!< восстанавливает голод, ест только кого-то рангом ниже, при этом создание рангом ниже должно умереть, или вообще не ест (планктон, например)
    virtual bool reproduce() override;  //!< размножается (как добавить новую рыбу в аквариум?)
    virtual Coordinates move() override; //!< передвигает жертву к цели, если в этом ходу мы будем двигаться
};
#endif  //! PLANKTON_H