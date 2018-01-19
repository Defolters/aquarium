#include "Creature.h"

Creature::Creature(LifeType type, LifeType prey, int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed)
    : type(type), prey(prey), lifeExpectancy(lifeExpectancy), lifeWitoutFood(lifeWitoutFood), reproductionPeriod(reproductionPeriod), rangeOfVision(rangeOfVision),
    hungerLimit(hungerLimit), speed(speed), lifeDaysLeft(lifeExpectancy), hunger(0), reproductionDaysLeft(reproductionPeriod), purpose(Coordinates()),
    task(TaskType::RUN)
{
    
}

Creature::~Creature()
{
}

void Creature::dayPassed()
{
}
