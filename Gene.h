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
    }; //!< ����������� ��� ������ �����

    int lifeExpectancy;  //!< ����������������� �����
    int lifeWitoutFood; //!< ������� ����� ���� ��� ���
    int reproductionPeriod; //!< ������ ����������� (���� 2 ��� �������� �������, � ���� ������ � ������, ����� ������������)
    int rangeOfVision;  //!< ��������� ������ ���� (��� ������ ����� ������)
    int hungerLimit;  //!< ������� ������ (���� - ����� �����!!)
    int speed; //!< �������� ����������� (������ �� ��, ������� ����� �������� �� ����� �������?)
};
#endif //! GENE_H