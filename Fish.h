#ifndef FISH_H
#define FISH_H
#include "Creature.h"
/*  ����� �� ������ ���������� �� ������� ����? ��� ���������� ����������� �� ����������?
    Creature -> Fish -> HerbivoreFish (����������)
    Creature -> Fish -> CarnivoreFish (����������)
    ��� 
    Creature -> HerbivoreFish -> CarnivoreFish //<- ��� ��� �������� ����������, ����� ���������
*/
class Fish abstract :
    public Creature
{
protected:
    Fish();
    virtual ~Fish();
private:
	// � ��� ������� ��� ������ ��� ��� ����� ���, ��� ����������� �������� ��� ��� ��� ����� ����� �������
};

#endif  //! FISH_H