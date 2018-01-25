#ifndef PLANKTON_H
#define PLANKTON_H
#include "Creature.h"
#include <random>
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
    Plankton(Gene gene, Coordinates position, unsigned int id);
    virtual ~Plankton();

    virtual bool thinkAboutIt(std::list<Creature*>& creatures, Coordinates borders) override;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual bool eat(std::list<Creature*>& creatures) override { return false; }; //!< планктон ничего не ест
    virtual bool reproduce(std::list<Creature*>& creatures) override;  //!< существо размножается каждые reproductionPeriod дней
    virtual unsigned int getPreyId() override { return 0; };
    std::random_device rd;
    std::mt19937 mt;
};
#endif  //! PLANKTON_H