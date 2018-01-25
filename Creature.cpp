#include "Creature.h"

Creature::Creature(LifeType type, Gene gene, LifeType prey, Coordinates position, unsigned int id)
    : Object(position), gene(gene), type(type), prey(prey), age(0), hunger(0), 
    reproductionReady(0), direction(position), task(TaskType::RUN), id(id)
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
        
        //Добавить скорость существу
        //X
        if (position.x < direction.x)
			position.x++;
        else if (position.x > direction.x) 
				position.x--;
        //Y
        if (position.y < direction.y)
			position.y++;
        else if (position.y > direction.y)
				position.y--;
        //Z
        if (position.z < direction.z)
			position.z++;
        else if (position.z > direction.z)
				position.z--;
        //std::cout << position.toString() << std::endl;
        return true;
		//setPosition(position);
    }
    else
    {
		setPosition(position);
        return false;
    }
}

bool Creature::dayPassed()
{
    hunger++; //увеличиваем голод
    age++; //увеличиваем возраст
    reproductionReady++; //увелич. кол-во дней от последнего размножения'
    //кидать события, если надо умереть от возраста или голода
    if (age == gene.lifeExpectancy || hunger == gene.lifeWitoutFood)
    {
        //throwEvent(position, EventType::BIRTH, this);
    }
    return true;
}

bool Creature::isDeadOfAge()
{
    if (age == gene.lifeExpectancy) 
        return true;
    else 
        return false;
}

bool Creature::isDeadOfHunger()
{
    if (hunger == gene.lifeWitoutFood) 
        return true;
    else 
        return false;
}

LifeType Creature::getType()
{
    return type;
}

Gene Creature::getGene()
{
    return gene;
}

unsigned int Creature::getId()
{
    return id;
}

bool Creature::isReadyToReproduce()
{
    if (reproductionReady == gene.reproductionPeriod)
        return true;
    else
        return false;
}

void Creature::iSleptWithYou()
{
    reproductionReady = 0;
}
