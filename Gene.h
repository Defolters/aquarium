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
            lifeExpectancy = 300;//200;
            lifeWitoutFood = 600;
            reproductionPeriod = 25;//53;
            rangeOfVision = 5;
            hungerLimit = 0;
            speed = 2;
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
            lifeExpectancy = 500;
            lifeWitoutFood = 300;
            reproductionPeriod = 60;
            rangeOfVision = 55;
            hungerLimit = 250;
            speed = 1.8;
        }
        else // herbivore fish
        {
            lifeExpectancy = 600;
            lifeWitoutFood = 300;
            reproductionPeriod = 30;
            rangeOfVision = 100;
            hungerLimit = 200;
            speed = 2.8;
        }
    };

    int lifeExpectancy;  //!< продолжительность жизни
    int lifeWitoutFood; //!< сколько может жить без еды
    int reproductionPeriod; //!< период размножения (кажд 2 дня планктон делится, а рыба плывет к другой, чтобы размножиться)
    int rangeOfVision;  //!< дальность зрения рыбы (как далеко видит вокруг)
    int hungerLimit;  //!< граница голода (выше - очень плохо!!)
    double speed; //!< скорость перемещения (влияет на то, сколько шагов движения мы можем сделать?)
};
#endif //! GENE_H