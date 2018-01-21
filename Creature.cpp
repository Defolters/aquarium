#include "Creature.h"

Creature::Creature(LifeType type, LifeType prey, int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed)
    : type(type), prey(prey), lifeExpectancy(lifeExpectancy), lifeWitoutFood(lifeWitoutFood), reproductionPeriod(reproductionPeriod), rangeOfVision(rangeOfVision),
    hungerLimit(hungerLimit), speed(speed), age(0), hunger(0), reproductionReady(0), direction(Coordinates()), //случайное направление, конструтор object??
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
        // двигаемся к цели = меняем координаты существа 
        //(МЫ ЖЕ НЕ СМОЖЕМ ЗДЕСЬ ВЫПЛЫТЬ ЗА ПРЕДЕЛЫ АКВАРИУМА? ЕСЛИ МЫ ПОЯВИМСЯ В ПРЕДЕЛАХ И НАША ЦЕЛЬ ТОЖЕ БУДЕТ В ПРЕДЕЛАХ)
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
    hunger++; //увеличиваем голод
    age++; //увеличиваем возраст
    reproductionReady++; //увелич. кол-во дней от последнего размножения'
    return true;
}
