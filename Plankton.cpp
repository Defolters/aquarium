#include "Plankton.h"



Plankton::Plankton()
    : Creature(LifeType::PLANKTON, LifeType::PLANKTON, 10, 10, 2, 5, 0, 1)
{
}


Plankton::~Plankton()
{
}

bool Plankton::thinkAboutIt(std::list<Creature*>& creatures)
{
    /*
    ���� �� �� �������� ����, �� ������ �� ������
    ���� ��������, �� ������ ����� ����*/
    if (getPositionAqua() == direction)
    {
        // �������� ��������� �����������, ���� �����
        direction.x = rand() % 10; //aquarium borders
        direction.y = rand() % 10;
        direction.z = rand() % 10;
    }
    else
    {
    }
    return true;
}

bool Plankton::reproduce()
{
    //���� ������ ������, �� �������, �������� �� ������� ���, ��� ��������
    if (reproductionReady == reproductionPeriod)
    {
        // ��������� ������ ��������� � ��������
        reproductionReady = 0;
        return true;
    }
    else
    {
        return false;
    }
    
}
