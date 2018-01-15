#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <vector>
#include "Creature.h"
#include "LifeManager.h"
#include "LifeType.h"

/*!
\brief �����, ����������� ��������

����� �������� ���� ������ ���, �������������� ��������� � ����������� 
��������/������ ���� (�� ������ �������� ��� ������).
*/
class Aquarium
{
public:
    Aquarium();
    ~Aquarium();
    
    bool addCreature(LifeType type);  //! �������� �������� � �������� �� ����
    bool removeCreature(int index);  //! ������ �������� �� ������� � �������
    void setCapacity(int capacity);  //! ������������� ������ ���������
    int getCapacity() const;  //! ���������� ������ ���������
    //! getNumberOfCreatures ������������ � LifeManager ��� ��������, ��� 
    //! �������� �� ������� � ���� �������� �� ����, ���������� ���������� ���
    int getNumberOfCreatures() const;  
    //! getListOfCreatures ������������ � LifeManager ��� ������ ���������� 
    //! �� ����� � ����� �������������� � Display, ����� �������� �� ������� 
    //! � �������� ���������� ��� �����������
    std::vector<Creature*>& getListOfCreatures();  
    
private:
    int capacity;  //! ������������ ���������� ���
    int numberOfCreatures;  //! ���������� ��� � ������ ������
    std::vector<Creature*> creatures;  //! ������ �� ���� ���������
    Coordinates borders;
    //! lf �� ���������! ��� �������� ��������� ��������� LifeManager, �������
    //! �������������� ����� (��������� ��������� ��� ���-��) � ����� ���������
    //! ������ � ��������� (������� ���, ������� ���, ����������, ������ � �������)
    LifeManager lf; 
};

#endif  //! AQUARIUM_H