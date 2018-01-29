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
            lifeExpectancy = 450;//200;
            lifeWitoutFood = 600;
            reproductionPeriod = 60;//58
            rangeOfVision = 5;
            hungerLimit = 0;
            speed = 1;//1.5
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
            lifeExpectancy = 1000;
            lifeWitoutFood = 700;
            reproductionPeriod = 125;
            rangeOfVision = 70;
            hungerLimit = 550;
            speed = 0.8;
        }
        else // herbivore fish
        {
            lifeExpectancy = 900;
            lifeWitoutFood = 550;
            reproductionPeriod = 55;
            rangeOfVision = 100;
            hungerLimit = 400;
            speed = 1.2;
        }
    };

    int lifeExpectancy;  //!< ����������������� �����
    int lifeWitoutFood; //!< ������� ����� ���� ��� ���
    int reproductionPeriod; //!< ������ ����������� (���� 2 ��� �������� �������, � ���� ������ � ������, ����� ������������)
    int rangeOfVision;  //!< ��������� ������ ���� (��� ������ ����� ������)
    int hungerLimit;  //!< ������� ������ (���� - ����� �����!!)
    double speed; //!< �������� ����������� (������ �� ��, ������� ����� �������� �� ����� �������?)
};
#endif //! GENE_H