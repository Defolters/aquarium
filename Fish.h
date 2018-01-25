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
    Fish(LifeType type, Gene gene, LifeType prey, Coordinates position, unsigned int id);
    virtual ~Fish();
    virtual bool thinkAboutIt(std::list<Creature*>& creatures, Coordinates borders) override;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual bool eat(std::list<Creature*>& creatures) override;//!< восстанавливает голод, ест только кого-то рангом ниже, при этом создание рангом ниже должно умереть, или вообще не ест (планктон, например)
    virtual bool reproduce(std::list<Creature*>& creatures) override;  //!< существо размножается каждые reproductionPeriod дней
    virtual unsigned int getPreyId() override;
private:
    unsigned int idOfPrey;
};

#endif  //! FISH_H#endif  //! FISH_H