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
\brief Класс, реализующий аквариум

Класс содержит лишь список рыб, характеристику аквариума и возможность 
добавить/убрать рыбу (на случай рождения или смерти).
*/
class Aquarium
{
public:
    Aquarium();
    ~Aquarium();
    
    bool addCreature(LifeType type);  //! добавить создание в аквариум по типу
    bool removeCreature(int index);  //! убрать создание по индексу в векторе
    void setCapacity(int capacity);  //! устанавливает размер аквариума
    int getCapacity() const;  //! возвращает размер аквариума
    //! getNumberOfCreatures используется в LifeManager для проверки, что 
    //! живность не вымерла и пора выходить из игры, возвращает количество рыб
    int getNumberOfCreatures() const;  
    //! getListOfCreatures используется в LifeManager для вывода статистики 
    //! на экран и может использоваться в Display, чтобы пройтись по вектору 
    //! и получить координаты для отображения
    std::vector<Creature*>& getListOfCreatures();  
	std::mutex eventQueueLocker;
	std::queue<LifeEvent> events;
private:
    int capacity;  //! максимальное количество рыб
    int numberOfCreatures;  //! количество рыб в данный момент
    std::vector<Creature*> creatures;  //! вектор со всей живностью
    Coordinates borders;
    //! lf не указатель! При создании аквариума создается LifeManager, который
    //! инициализирует жизнь (добавляет начальных рыб как-то) и затем управляет
    //! жизнью в акваруиме (считает дни, двигает рыб, размножает, кормит и убивает)
    LifeManager manager; 
};

#endif  //! AQUARIUM_H