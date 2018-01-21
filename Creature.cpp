#include "Creature.h"

Creature::Creature(LifeType type, LifeType prey, int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed)
    : type(type), prey(prey), lifeExpectancy(lifeExpectancy), lifeWitoutFood(lifeWitoutFood), reproductionPeriod(reproductionPeriod), rangeOfVision(rangeOfVision),
    hungerLimit(hungerLimit), speed(speed), age(0), hunger(0), reproductionReady(0), direction(Coordinates()), //��������� �����������, ���������� object??
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
        //(�� �� �� ������ ����� ������� �� ������� ���������? ���� �� �������� � �������� � ���� ���� ���� ����� � ��������)
        //X
        if (positionAqua.x < direction.x) positionAqua.x++;
        else if (positionAqua.x > direction.x) positionAqua.x--;
        //Y
        if (positionAqua.y < direction.y) positionAqua.y++;
        else if (positionAqua.y > direction.y) positionAqua.y--;
        //Z
        if (positionAqua.z < direction.z) positionAqua.z++;
        else if (positionAqua.z > direction.z) positionAqua.z--;
        std::cout << positionAqua.toString() << std::endl;
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
