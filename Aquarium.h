#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <vector>
#include <mutex>
#include <queue>
#include "Creature.h"
#include "LifeManager.h"
#include "LifeType.h"
#include "LifeEvent.h"
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
	std::mutex eventQueueLocker;
	std::queue<LifeEvent> events;
private:
    int capacity;  //! ������������ ���������� ���
    int numberOfCreatures;  //! ���������� ��� � ������ ������
    std::vector<Creature*> creatures;  //! ������ �� ���� ���������
    Coordinates borders;
    //! lf �� ���������! ��� �������� ��������� ��������� LifeManager, �������
    //! �������������� ����� (��������� ��������� ��� ���-��) � ����� ���������
    //! ������ � ��������� (������� ���, ������� ���, ����������, ������ � �������)
    LifeManager manager; 
};

#endif  //! AQUARIUM_H