#ifndef GENE_H
#define GENE_H
/*Геном создания

должны ли отличаться начальные характеристики у травоядный и плотоядных рыб?
*/
struct Gene
{
    Gene(int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed)
        : lifeExpectancy(lifeExpectancy), lifeWitoutFood(lifeWitoutFood), reproductionPeriod(reproductionPeriod), rangeOfVision(rangeOfVision),
        hungerLimit(hungerLimit), speed(speed) {};

    Gene(LifeType type)
    {
        if (type == LifeType::PLANKTON)
        {
            lifeExpectancy = 500;//200;
            lifeWitoutFood = 600;
            reproductionPeriod = 50;//53;
            rangeOfVision = 5;
            hungerLimit = 0;
            speed = 2;
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
            lifeExpectancy = 600;
            lifeWitoutFood = 500;
            reproductionPeriod = 60;
            rangeOfVision = 100;
            hungerLimit = 300;
            speed = 3;
        }
        else // herbivore fish
        {/*
            lifeExpectancy = 700;
            lifeWitoutFood = 400;
            reproductionPeriod = 40;
            rangeOfVision = 100;
            hungerLimit = 300;
            speed = 4;*/
            lifeExpectancy = 800;
            lifeWitoutFood = 500;
            reproductionPeriod = 40;
            rangeOfVision = 100;
            hungerLimit = 200;
            speed = 4;
        }
    };

    int lifeExpectancy;  //!< продолжительность жизни
    int lifeWitoutFood; //!< сколько может жить без еды
    int reproductionPeriod; //!< период размножения (кажд 2 дня планктон делится, а рыба плывет к другой, чтобы размножиться)
    int rangeOfVision;  //!< дальность зрения рыбы (как далеко видит вокруг)
    int hungerLimit;  //!< граница голода (выше - очень плохо!!)
    int speed; //!< скорость перемещения (влияет на то, сколько шагов движения мы можем сделать?)
};
#endif //! GENE_H