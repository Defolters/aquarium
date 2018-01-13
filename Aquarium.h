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
    
    bool addCreature(Type type_);  //! �������� �������� � �������� �� ����
    bool removeCreature(int index_);  //! ������ �������� �� ��������� �� ������� � �������
    void setCapacity(int capacity_);  //! ������������� ������ ���������
    int getCapacity();  //! ���������� ������ ���������
    std::vector<Creature*> getListOfCreatures();  //!< ������������ � LifeManager ��� ������ ���������� �� ����� � ����� �������������� � Display, ����� �������� �� ������� � �������� ���������� ��� �����������
    int checkSize();  //!< ������������ � LifeManager ��� ��������, ��� �������� �� ������� � ���� �������� �� ����
    
private:
    
    int capacity;  //! ������������ ���������� ���
    std::vector<Creature* > creatures;  //! ������ �� ���� ���������
};

#endif  //! AQUARIUM_H