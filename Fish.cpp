#include "Fish.h"
#include <random>


Fish::Fish(LifeType type, Gene gene, LifeType prey, Coordinates position, unsigned int id)
    : Creature(type, gene, prey, position, id), aim(nullptr), mt(rd())
{
    distance = gene.rangeOfVision + 5;
}

Fish::~Fish()
{
}

bool Fish::thinkAboutIt(std::list<Creature*>& creatures, Coordinates borders)
{
    if ((aim == nullptr) && (std::find(creatures.begin(), creatures.end(), aim) == creatures.end()))
    {
        aim = nullptr;
        distance = gene.rangeOfVision + 5;
        //return false;
    }
    if ((aim != nullptr) && (getPosition().getDistance(aim->getPosition()) <= 5))//gene.rangeOfEatingAndReproducing)  //а если кто-то поспал со мной? а если мы уже поспали с рыбой? а если рыба еще не готова?
    {
        if (aim->getType() == prey)
        {
            task = TaskType::EAT;
        }
        else if (aim->getType() == type)
        {
            task = TaskType::REPRODUCE;
        }
        return true;
    }
    else
    {
        if ((hunger >= gene.hungerLimit) & (nearFood(creatures))) // хочу есть и р€дом есть еда (если есть еда, то функци€ nearFood() поставиt цель)
        {
        }
        else if (nearBreeding(creatures))//если есть с кем спать, то функци€ вернет тру и поставит ближайшую цель
        {
        }
        else if (aim == nullptr)// если никого не нашли, то выбрать случайное направление
        {
            if (getPosition() == direction)
            {
                std::uniform_int_distribution<int> distx(1, borders.x);
                //direction.x = rand() % borders.x;
                direction.x = distx(mt);
                std::uniform_int_distribution<int> disty(1, borders.y);
                //direction.y = rand() % borders.y;
                direction.y = disty(mt);
                std::uniform_int_distribution<int> distz(1, borders.z);
                //direction.z = rand() % borders.z;
                direction.z = distz(mt);
                //std::cout << "New direction: " << direction.toString() << std::endl;
            }
            else
            {
            }
            task = TaskType::RUN;
        }
        else {}// если мы все же нашли еду.

        //еды нет, есть дл€ размножени€
        //нет ни того, ни другого

        //а если не нашел дл€ размножени€?
        //        если создание подходит по цели и ближе чем другое
        
        
            //aim = std::make_shared<Creature>(creature);
        //ищем ближайшую цель с учетом наших потребностей
        //не спать с собой :)
        
        return false;
    }
    /*
    ставить цель: либо плыть к другой рыбе этого типа, либо к планктону, либо куда-то еще
    если находимс€ р€дом с планктоном, то его надо съесть (сохранить ивент с планктоном)
    если р€дом с рыбой и можно размножатьс€, то
    */
    //ищем р€дом рыб и планктонов, 
    /*
    если уровень голода выше лимита, то направление = ближайший планктон в зоне видимости
    если планктона нет, то ближайша€ рыба
    если никого нет, то случайное направление?
    ***
    если уровень голода ниже лимита, то направление = ближайша€ рыба
    если рыб нет, то планктон
    если никого нет, то случайное направление
    ***
    */
}

bool Fish::eat(std::list<Creature*>& creatures)
{
    if (aim == nullptr && std::find(creatures.begin(), creatures.end(), aim) == creatures.end())
    {
        aim = nullptr;
        distance = gene.rangeOfVision + 5;
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

        return true;
    }
    return false;
}

bool Fish::reproduce(std::list<Creature*>& creatures)
{
    if (aim == nullptr && std::find(creatures.begin(), creatures.end(), aim) == creatures.end())
    {
        aim = nullptr;
        distance = gene.rangeOfVision + 5;
        return false;
    }
    if (task == TaskType::REPRODUCE && (reproductionReady > gene.reproductionPeriod) && aim->isReadyToReproduce())
    {
        aim->iSleptWithYou();
        throwEvent(getPosition(), EventType::BIRTH, this);
        reproductionReady = 0;
        aim = nullptr;
        return true;
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
    double nearestDistance = gene.rangeOfVision + 5;
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
