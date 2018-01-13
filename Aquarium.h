#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <vector>
#include "Creature.h"
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
    bool removeCreature(int index);  //! ������ �������� �� ��������� �� ������� � �������
    void setCapacity(int capacity);  //! ������������� ������ ���������
    int getCapacity();  //! ���������� ������ ���������
    int getNumberOfCreatures();  //!< ������������ � LifeManager ��� ��������, ��� �������� �� ������� � ���� �������� �� ����, ���������� ���������� ���
    std::vector<Creature*> getListOfCreatures();  //!< ������������ � LifeManager ��� ������ ���������� �� ����� � ����� �������������� � Display, ����� �������� �� ������� � �������� ���������� ��� �����������
    
private:
    int capacity;  //! ������������ ���������� ���
    int numberOfCreatures;  //! ���������� ��� � ������ ������
    std::vector<Creature*> creatures;  //! ������ �� ���� ���������
};

#endif  //! AQUARIUM_H