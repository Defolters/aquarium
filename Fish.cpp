#include "Fish.h"



Fish::Fish(LifeType type, Gene gene, LifeType prey, Coordinates position, unsigned int id)
    : Creature(type, gene, prey, position, id)
{
}

Fish::~Fish()
{
}

bool Fish::thinkAboutIt(std::list<Creature*>& creatures, Coordinates borders)
{
    /*
    ставить цель: либо плыть к другой рыбе этого типа, либо к планктону, либо куда-то еще
    если находимс€ р€дом с планктоном, то его надо съесть (сохранить ивент с планктоном)
    если р€дом с рыбой и можно размножатьс€, то
    */
    return false;
}

bool Fish::eat(std::list<Creature*>& creatures)
{
    if (task == TaskType::EAT)
    {
        //восстановить голод и бросить ивент, что рыба под таким id съедена
        // ¬ throwEvent ƒќЅј¬»“№ ¬≈ “ќ– — Ќ≈ќЅ’ќƒ»ћџћ» «Ќј„≈Ќ»яћ»: съел(who id), умер(who id), родилс€(gen of parent/s)
        hunger = 0;
        //throwEvent(getPosition(), EventType::DEATH, this);

        return true;
    }
    return false;
}

bool Fish::reproduce(std::list<Creature*>& creatures)
{
    if (task == TaskType::REPRODUCE)
    {
        //увеличить перерыв
        //бросить ивент, что рыба родилась
        return true;
    }
    return false;
}

unsigned int Fish::getPreyId()
{
    return idOfPrey;
}
