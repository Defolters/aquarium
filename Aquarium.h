#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <vector>
#include "Creature.h"
#include "LifeManager.h"
//! ���� ��������
enum class Type {
    PLANKTON,
    HERBIVOREFISH,
    CARNIVOREFISH //??
};

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
    
    bool addCreature(Type type);  //! �������� �������� � �������� �� ����
    bool removeCreature(int index);  //! ������ �������� �� ������� � �������
    void setCapacity(int capacity);  //! ������������� ������ ���������
    int getCapacity();  //! ���������� ������ ���������
    //! getNumberOfCreatures ������������ � LifeManager ��� ��������, ��� 
    //! �������� �� ������� � ���� �������� �� ����, ���������� ���������� ���
    int getNumberOfCreatures();  
    //! getListOfCreatures ������������ � LifeManager ��� ������ ���������� 
    //! �� ����� � ����� �������������� � Display, ����� �������� �� ������� 
    //! � �������� ���������� ��� �����������
    std::vector<Creature*> getListOfCreatures();  
    
private:
    int capacity;  //! ������������ ���������� ���
    int numberOfCreatures;  //! ���������� ��� � ������ ������
    std::vector<Creature*> creatures;  //! ������ �� ���� ���������
    //! lf �� ���������! ��� �������� ��������� ��������� LifeManager, �������
    //! �������������� ����� (��������� ��������� ��� ���-��) � ����� ���������
    //! ������ � ��������� (������� ���, ������� ���, ����������, ������ � �������)
    LifeManager lf; 
};

#endif  //! AQUARIUM_H