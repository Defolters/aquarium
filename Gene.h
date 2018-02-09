#ifndef GENE_H
#define GENE_H

//!Геном создания
struct Gene
{
    Gene(int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed)
        : lifeExpectancy(lifeExpectancy), lifeWitoutFood(lifeWitoutFood), reproductionPeriod(reproductionPeriod), rangeOfVision(rangeOfVision),
        hungerLimit(hungerLimit), speed(speed) {};

    Gene(LifeType type)
    {
        if (type == LifeType::PLANKTON)
        {
            lifeExpectancy = 550;
            lifeWitoutFood = 600;
            reproductionPeriod = 35;
            rangeOfVision = 5;
            hungerLimit = 0;
            speed = 0.9;
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
            lifeExpectancy = 1500;
            lifeWitoutFood = 850;
            reproductionPeriod = 180;
            rangeOfVision = 70;
            hungerLimit = 650;
            speed = 0.6;
        }
        else // herbivore fish
        {
            lifeExpectancy = 950;
            lifeWitoutFood = 470;
            reproductionPeriod = 55;
            rangeOfVision = 100;
            hungerLimit = 350;
            speed = 1.1;
        }
    };

    int lifeExpectancy;  //!< продолжительность жизни
    int lifeWitoutFood; //!< сколько может жить без еды
    int reproductionPeriod; //!< период размножения (кажд 2 дня планктон делится, а рыба плывет к другой, чтобы размножиться)
    int rangeOfVision;  //!< дальность зрения рыбы (как далеко видит вокруг)
    int hungerLimit;  //!< граница голода (выше - очень плохо!!)
    double speed; //!< скорость перемещения
};
#endif //! GENE_H