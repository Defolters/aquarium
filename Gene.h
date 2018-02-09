#ifndef GENE_H
#define GENE_H

//!����� ��������
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

    int lifeExpectancy;  //!< ����������������� �����
    int lifeWitoutFood; //!< ������� ����� ���� ��� ���
    int reproductionPeriod; //!< ������ ����������� (���� 2 ��� �������� �������, � ���� ������ � ������, ����� ������������)
    int rangeOfVision;  //!< ��������� ������ ���� (��� ������ ����� ������)
    int hungerLimit;  //!< ������� ������ (���� - ����� �����!!)
    double speed; //!< �������� �����������
};
#endif //! GENE_H