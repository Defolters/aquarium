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
            lifeExpectancy = 100;//200;
            lifeWitoutFood = 201;
            reproductionPeriod = 80;//53;
            rangeOfVision = 5;
            hungerLimit = 0;
            speed = 1;
        }
        else if (type == LifeType::CARNIVOREFISH)
        {
            lifeExpectancy = 20;
            lifeWitoutFood = 10;
            reproductionPeriod = 5;
            rangeOfVision = 15;
            hungerLimit = 5;
            speed = 1;
        }
        else // herbivore fish
        {
            lifeExpectancy = 500;
            lifeWitoutFood = 500;
            reproductionPeriod = 5;
            rangeOfVision = 40;
            hungerLimit = 10;
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