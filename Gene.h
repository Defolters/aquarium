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

    int lifeExpectancy;  //!< ����������������� �����
    int lifeWitoutFood; //!< ������� ����� ���� ��� ���
    int reproductionPeriod; //!< ������ ����������� (���� 2 ��� �������� �������, � ���� ������ � ������, ����� ������������)
    int rangeOfVision;  //!< ��������� ������ ���� (��� ������ ����� ������)
    int hungerLimit;  //!< ������� ������ (���� - ����� �����!!)
    double speed; //!< �������� ����������� (������ �� ��, ������� ����� �������� �� ����� �������?)
};
#endif //! GENE_H