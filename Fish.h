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
    Fish(LifeType type, LifeType prey, Coordinates position);
    virtual ~Fish();
    virtual bool thinkAboutIt(std::list<Creature*>& creatures) override;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual bool eat() override;//!< восстанавливает голод, ест только кого-то рангом ниже, при этом создание рангом ниже должно умереть, или вообще не ест (планктон, например)
    virtual bool reproduce(std::list<Creature*>& creatures) override;  //!< существо размножается каждые reproductionPeriod дней
};

#endif  //! FISH_H