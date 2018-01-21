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

    virtual bool thinkAboutIt(std::list<Creature*>& creatures) override;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual bool eat() override {}; //!< планктон ничего не ест
    virtual bool reproduce() override;  //!< существо размножается каждые reproductionPeriod дней
};
#endif  //! PLANKTON_H