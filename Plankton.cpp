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
    if (getPositionAqua() != direction)
    {
    }
    else
    {
        // ���������� ����� �����������
    }
    
}

bool Plankton::reproduce()
{
    //���� ������ ������, �� �������, �������� �� ������� ���, ��� ��������
    if (reproductionReady == reproductionPeriod)
    {
        // ������������ 
        reproductionReady = 0;
    }
    else
    {
        return false;
    }
    
}
