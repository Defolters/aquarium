#include "Fish.h"
#include <random>


Fish::Fish(LifeType type, Gene gene, LifeType prey, Coordinates position, unsigned int id)
    : Creature(type, gene, prey, position, id), aim(nullptr), mt(rd())
{
}

Fish::~Fish()
{
}

bool Fish::thinkAboutIt(std::list<Creature*>& creatures, Coordinates borders)
{
    if (std::find(creatures.begin(), creatures.end(), aim) == creatures.end())
    {
        aim = nullptr;
    }
    if (myAimIsVeryNear())
    {
        return true;
    }
    /*if ((aim != nullptr) && (getPosition().getDistance(aim->getPosition()) <= (gene.speed+magicNumber)))//gene.rangeOfEatingAndReproducing)  //а если кто-то поспал со мной? а если мы уже поспали с рыбой? а если рыба еще не готова?
    {
        if (aim->getType() == prey)
        {
            std::cout << "Om-nom-nom\n";
            task = TaskType::EAT;
        }
        else if (aim->getType() == type)
        {
            std::cout << "Ah\n";
            task = TaskType::REPRODUCE;
        }
        return true;
    }*/
    else
    {
        // если очень хочу есть » р€дом есть еда, то плыву скорее есть
        if ((hunger >= gene.hungerLimit) && (nearFood(creatures))) 
        {
            //если р€дом, то поставить цель
            if (myAimIsVeryNear())
            {
                return true;
            }
        }
        //если хочу размножатьс€ и р€дом есть пара, то плыву размножатьс€
        else if (isReadyToReproduce() && nearBreeding(creatures))
        {
            //если р€дом поставить цель
            if (myAimIsVeryNear())
            {
                return true;
            }
        }
        //если размножатьс€ не хочу, то просто искать еду
        else if (nearFood(creatures))
        {
            //если р€дом поставить цель
            if (myAimIsVeryNear())
            {
                return true;
            }
        }
        //если еды нет, то плыву к паре
        /*else if (nearBreeding(creatures))
        {
        }*/
        //если никого нет, то плыву просто случайно
        else// если никого не нашли, то выбрать случайное направление
        {
            if (getPosition().getDistance(direction) < 10+gene.speed)
            {
                std::uniform_int_distribution<int> distx(0, borders.x);
                //direction.x = rand() % borders.x;
                direction.x = distx(mt);
                std::uniform_int_distribution<int> disty(0, borders.y);
                //direction.y = rand() % borders.y;
                direction.y = disty(mt);
                std::uniform_int_distribution<int> distz(0, borders.z);
                //direction.z = rand() % borders.z;
                direction.z = distz(mt);
                //std::cout << "New direction: " << direction.toString() << std::endl;
            }
            else
            {
            }
            task = TaskType::RUN;
        }
        
        return false;
    }
}

bool Fish::eat(std::list<Creature*>& creatures)
{
    if (std::find(creatures.begin(), creatures.end(), aim) == creatures.end())
    {
        aim = nullptr;
        return false;
    }
    if (task == TaskType::EAT) // проверить, что эту рыбу другие не съели
    {
        // ¬ throwEvent ƒќЅј¬»“№ ¬≈ “ќ– — Ќ≈ќЅ’ќƒ»ћџћ» «Ќј„≈Ќ»яћ»: съел(who id), умер(who id), родилс€(gen of parent/s)
        //throwEvent(getPosition(), EventType::DEATH, preyIter)
        throwEvent(aim->getPosition(), EventType::DEATH, aim);
        idOfPrey = aim->getId();
        aim = nullptr;
        hunger = 0;
        task = TaskType::RUN;
        return true;
    }
    return false;
}

bool Fish::reproduce(std::list<Creature*>& creatures)
{
    if (std::find(creatures.begin(), creatures.end(), aim) == creatures.end())
    {
        aim = nullptr;
        return false;
    }
    if ((task == TaskType::REPRODUCE) && isReadyToReproduce() && aim->isReadyToReproduce())
    {
        aim->iSleptWithYou();
        throwEvent(getPosition(), EventType::BIRTH, this);
        
        reproductionReady = 0;
        aim = nullptr;
        task = TaskType::RUN;
        return true;
    }
    else if (!isReadyToReproduce())// мы хотели переспать, но с нами уже поспали
    {
        aim = nullptr;
        task = TaskType::RUN;
    }
    return false;
}

unsigned int Fish::getPreyId()
{
    return idOfPrey;
}

bool Fish::nearFood(std::list<Creature*>& creatures)
{
    Creature* creature = nearCreature(creatures, prey);
    if (creature != nullptr)
    {
        aim = creature;
        direction = aim->getPosition();
        return true;
    }
    else
    {
        return false;
    }
}

bool Fish::nearBreeding(std::list<Creature*>& creatures)
{
    Creature* creature = nearCreature(creatures, type);
    if (creature != nullptr)
    {
        aim = creature;
        direction = aim->getPosition();
        return true;
    }
    else
    {
        return false;
    }
}

Creature * Fish::nearCreature(std::list<Creature*>& creatures, LifeType type)
{
    Creature* nearCreature = nullptr;
    double nearestDistance = gene.rangeOfVision + 10;
    for (auto creature : creatures)
    {
        if (creature == this) continue;
        double dist = getPosition().getDistance(creature->getPosition());
        if (dist <= gene.rangeOfVision //вижу
            && creature->getType() == type //оно подходит по типу
            && nearestDistance > dist) // оно ближе, чем то, которое мы уже нашли
        {
            nearCreature = creature;
            nearestDistance = dist;
        }
    }

    return nearCreature;
}

bool Fish::myAimIsVeryNear()
{
    if ((aim != nullptr) && (getPosition().getDistance(aim->getPosition()) <= (gene.speed+magicNumber)))//gene.rangeOfEatingAndReproducing)  //а если кто-то поспал со мной? а если мы уже поспали с рыбой? а если рыба еще не готова?
    {
        if (aim->getType() == prey)
        {
            //std::cout << "Om-nom-nom\n";
            task = TaskType::EAT;
        }
        else if (aim->getType() == type)
        {
            //std::cout << "Ah\n";
            task = TaskType::REPRODUCE;
        }
        return true;
    }
    else
    {
        return false;
    }
}
