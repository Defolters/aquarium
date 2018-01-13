#ifndef CREATURE_H
#define CREATURE_H
#include "Headers.h"

#include <string>
class Creature
{
public:
    Creature();
    virtual ~Creature();
    Vector2f move();

private:
    int lifeExpectancy;  //! ����������������� �����
    //! ���������� ����, ������� ���� ����� ������� ��� ��� (���� ���� ����� ������, �.�. ������ ������ � ���������, �� ��������� ������ ������ � �����������)

    //! ������, � ������� �������� ������������ (����. ������ 2 ��� �������� 
    //! ������� ����������� � ������ 4 ��� ���� ����� ������������, �.� 
    //! ������ � ������ ����, � ����� ����������, �� ���������� ����� ����)
    int period;  
    //Vector2f coordinate  // ������������� �������� � 3� ���������, �� ����������� � 2�. ��� ����� ����� �������? 
    //���������� ��, ������� ����� � ��� z ���������� ����������
    //String name �������� ���� (����, ��������) ��� getCreatures � ���������, ��� ���������� � �������, ����� ����������� ����� ����.
    std::string name;
}; 

#endif  //! CREATURE_H