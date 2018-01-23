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

void Creature::initGraphics(Texture* tex)
{
	sprite.setTexture(*tex);
	setSize(Vector2f(1,1));//TODO different sizes
}

bool Creature::move()
{
    if (task == TaskType::RUN)
    {
        // двигаемся к цели = меняем координаты существа 
        //(МЫ ЖЕ НЕ СМОЖЕМ ЗДЕСЬ ВЫПЛЫТЬ ЗА ПРЕДЕЛЫ АКВАРИУМА? ЕСЛИ МЫ ПОЯВИМСЯ В ПРЕДЕЛАХ И НАША ЦЕЛЬ ТОЖЕ БУДЕТ В ПРЕДЕЛАХ)
        //Добавить скорость существу
        if (position.x < direction.x)
			position.x++;
        else
			if (position.x > direction.x) 
				position.x--;
        //Y
        if (position.y < direction.y)
			position.y++;
        else 
			if (position.y > direction.y)
				position.y--;
        //Z
        if (position.z < direction.z)
			position.z++;
        else
			if (position.z > direction.z)
				position.z--;
        std::cout << position.toString() << std::endl;
        return true;
		setPosition(position.toVector2f());
    }
    else
    {
		setPosition(position.toVector2f());
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

bool Creature::isDeadOfAge()
{
    if (age == lifeExpectancy) return true;
    else return false;
}

bool Creature::isDeadOfHunger()
{
    if (hunger == lifeWitoutFood) return true;
    else return false;
}
