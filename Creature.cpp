#include "Creature.h"
#include "VectorOperations.h"

Creature::Creature(LifeType type, Gene gene, LifeType prey, Coordinates position, unsigned int id)
    : Object(position), gene(gene), type(type), prey(prey), age(0), hunger(0), 
    reproductionReady(0), direction(position), task(TaskType::RUN), id(id)
{

}

Creature::~Creature()
{
}

void Creature::initGraphicsAnim(Animation anim)
{
	animation = new Animation(anim);
	sprite.setTexture(animation->GetSpriteList()->atlas);
	setSize(Vector2f(1,1));//TODO different sizes
}

void Creature::initGraphicsTex(Texture * tex)
{
	sprite.setTexture(*tex);
	setSize(Vector2f(1, 1));//TODO different sizes
}

bool Creature::move()
{
    if (task == TaskType::RUN)
    {
        
        //Добавить скорость существу
        //X
        if (position.x < direction.x)
        {
            position.x += gene.speed;
        }
        else if ((position.x > direction.x) && (position.x >= (direction.x + gene.speed+2)))
        {
            position.x-= gene.speed;
        }
        //Y
        if (position.y < direction.y)
        {
            position.y += gene.speed;
        }
        else if ((position.y > direction.y) && (position.y >= (direction.y + gene.speed+2)))
        {
            position.y-= gene.speed;
        }
        //Z
        if (position.z < direction.z)
        {
            position.z += gene.speed;
        }
        else if ((position.z > direction.z) && (position.z >= (direction.z + gene.speed+2)))
        {
            position.z-= gene.speed;
        }
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
    //кидать события, если надо умереть от возраста или голода
    /*if (age == gene.lifeExpectancy || hunger == gene.lifeWitoutFood)
    {
        throwEvent(position, EventType::DEATH, this);
    }*/
    return true;
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
    if (reproductionReady >= gene.reproductionPeriod)
        return true;
    else
        return false;
}

void Creature::iSleptWithYou()
{
    reproductionReady = 0;
}

void Creature::isShouldDead()
{
    if (age == gene.lifeExpectancy || hunger == gene.lifeWitoutFood)
        throwEvent(getPosition(), EventType::DEATH, this);
}

Sprite Creature::getSprite()
{
	Sprite res = Object::getSprite();
	Vector2f scale = Vector2f(res.getScale().x/100*(100 - position.z*downByUnit), res.getScale().y/100*(100 - position.z*downByUnit));
	if (VectorOperations::AngleBetweenVectors(originDirection, Vector2f(direction.x, direction.y) - Vector2f(position.x,position.y)) > 90)
		scale.x = scale.x * (-1);
	res.setScale(scale);
	return res;
}
