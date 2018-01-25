#include "Fish.h"



Fish::Fish(LifeType type, Gene gene, LifeType prey, Coordinates position, unsigned int id)
    : Creature(type, gene, prey, position, id)
{
}

Fish::~Fish()
{
}

bool Fish::thinkAboutIt(std::list<Creature*>& creatures, Coordinates borders)
{
    /*
    ������� ����: ���� ����� � ������ ���� ����� ����, ���� � ���������, ���� ����-�� ���
    ���� ��������� ����� � ����������, �� ��� ���� ������ (��������� ����� � ����������)
    ���� ����� � ����� � ����� ������������, ��
    */
    return false;
}

bool Fish::eat(std::list<Creature*>& creatures)
{
    if (task == TaskType::EAT)
    {
        //������������ ����� � ������� �����, ��� ���� ��� ����� id �������
        // � throwEvent �������� ������ � ������������ ����������: ����(who id), ����(who id), �������(gen of parent/s)
        hunger = 0;
        //throwEvent(getPosition(), EventType::DEATH, this);

        return true;
    }
    return false;
}

bool Fish::reproduce(std::list<Creature*>& creatures)
{
    if (task == TaskType::REPRODUCE)
    {
        //��������� �������
        //������� �����, ��� ���� ��������
        return true;
    }
    return false;
}

unsigned int Fish::getPreyId()
{
    return idOfPrey;
}
