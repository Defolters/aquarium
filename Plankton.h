#ifndef PLANKTON_H
#define PLANKTON_H
#include "Creature.h"
/*!
\brief Класс, реализующий планктон

Планктон ставит цель на карте, затем плывет к ней, а когда достигает, то
ставит новую цель...
Размножается каждые * дней.
*/
class Plankton :
    public Creature
{
public:
    Plankton(Coordinates position);
    virtual ~Plankton();

    virtual bool thinkAboutIt(std::list<Creature*>& creatures) override;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual bool eat() override { return true; }; //!< планктон ничего не ест
    virtual bool reproduce(std::list<Creature*>& creatures) override;  //!< существо размножается каждые reproductionPeriod дней
};
#endif  //! PLANKTON_H