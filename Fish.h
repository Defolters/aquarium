#ifndef FISH_H
#define FISH_H
#include "Creature.h"
/*  ����� �� ������ ���������� �� ������� ����? ��� ���������� ����������� �� ����������?
    Fish -> HerbivoreFish (����������)
    Fish -> CarnivoreFish (����������)
    ��� 
    HerbivoreFish -> CarnivoreFish
*/
class Fish :
    public Creature
{
public:
    Fish();
    virtual ~Fish();
};

#endif  //! FISH_H