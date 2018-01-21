#include "Creature.h"

Creature::Creature(LifeType type, LifeType prey, int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed)
    : type(type), prey(prey), lifeExpectancy(lifeExpectancy), lifeWitoutFood(lifeWitoutFood), reproductionPeriod(reproductionPeriod), rangeOfVision(rangeOfVision),
    hungerLimit(hungerLimit), speed(speed), age(0), hunger(0), reproductionReady(0), direction(Coordinates()),
    task(TaskType::RUN)
{
    
}

Creature::~Creature()
{
}

bool Creature::move()
{
    if (task == TaskType::RUN)
    {
        // ��������� � ���� = ������ ���������� ��������
        return true;
    }
    else
    {
        return false;
    }
}

bool Creature::dayPassed()
{
    hunger++; //����������� �����
    age++; //����������� �������
    reproductionReady++; //������. ���-�� ���� �� ���������� �����������'
    return true;
}
