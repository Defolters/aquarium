#ifndef FISH_H
#define FISH_H
#include "Creature.h"
/*  ����� �� ������ ���������� �� ������� ����? ��� ���������� ����������� �� ����������?
    Creature -> Fish -> HerbivoreFish (����������)
    Creature -> Fish -> CarnivoreFish (����������)
    ��� 
    Creature -> HerbivoreFish -> CarnivoreFish
*/
class Fish :
    public Creature
{
public:
    Fish();
    virtual ~Fish();
private:
    std::string name = "Fish";
};

#endif  //! FISH_H