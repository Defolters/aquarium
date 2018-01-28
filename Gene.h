#ifndef GENE_H
#define GENE_H
/*����� ��������

������ �� ���������� ��������� �������������� � ���������� � ���������� ���?
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

    int lifeExpectancy;  //!< ����������������� �����
    int lifeWitoutFood; //!< ������� ����� ���� ��� ���
    int reproductionPeriod; //!< ������ ����������� (���� 2 ��� �������� �������, � ���� ������ � ������, ����� ������������)
    int rangeOfVision;  //!< ��������� ������ ���� (��� ������ ����� ������)
    int hungerLimit;  //!< ������� ������ (���� - ����� �����!!)
    int speed; //!< �������� ����������� (������ �� ��, ������� ����� �������� �� ����� �������?)
};
#endif //! GENE_H