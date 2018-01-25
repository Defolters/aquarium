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
            lifeExpectancy = 10;//200;
            lifeWitoutFood = 201;
            reproductionPeriod = 5;//53;
            rangeOfVision = 5;
            hungerLimit = 0;
            speed = 1;
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
            lifeExpectancy = 20;
            lifeWitoutFood = 10;
            reproductionPeriod = 5;
            rangeOfVision = 5;
            hungerLimit = 5;
            speed = 1;
        }
        else // herbivore fish
        {
            lifeExpectancy = 1;
            lifeWitoutFood = 1;
            reproductionPeriod = 1;
            rangeOfVision = 1;
            hungerLimit = 1;
            speed = 1;
        }
    }; //!< стандартные для разных типов

    int lifeExpectancy;  //!< продолжительность жизни
    int lifeWitoutFood; //!< сколько может жить без еды
    int reproductionPeriod; //!< период размножения (кажд 2 дня планктон делится, а рыба плывет к другой, чтобы размножиться)
    int rangeOfVision;  //!< дальность зрения рыбы (как далеко видит вокруг)
    int hungerLimit;  //!< граница голода (выше - очень плохо!!)
    int speed; //!< скорость перемещения (влияет на то, сколько шагов движения мы можем сделать?)
};
#endif //! GENE_H