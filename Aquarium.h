#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <list>
#include <mutex>
#include <queue>
#include "Creature.h"
#include "LifeManager.h"

/*!
\brief Класс, реализующий аквариум

Класс содержит лишь список рыб, характеристику аквариума и возможность 
добавить/убрать рыбу (на случай рождения или смерти).
*/
class Aquarium
{
public:
    Aquarium(); //!< 
    Aquarium(int capacity, Coordinates borders);
    ~Aquarium();
    
    void startGame(); //!< даем сигнал менеджеру, чтобы запустить цикл работы
    void stopGame(); //!< даем синал менеджеру, чтобы остановил работу

    bool addCreature(LifeType type);  //!< добавить создание в аквариум по типу (у аквариума должен быть доступ к конструкторам созданий)
    bool removeCreature(int index);  //!< убрать создание по индексу в векторе

    void setCapacity(int capacity);  //!< устанавливает размер аквариума
    int getCapacity() const;  //!< возвращает размер аквариума

    void setBorders(Coordinates borders); //!< устанавливает границы аквариума
    Coordinates getBorders() const; //!< возвращает границы аквариума

    int getNumberOfCreatures() const; //< возвращает количество рыб в данный момент
    std::list<Creature*>& getListOfCreatures(); //< возвращает список рыб

	std::mutex eventQueueLocker; //!< для многопоточности?

private:

    int capacity;  //!< максимальное количество рыб
    int numberOfCreatures;  //!< количество рыб в данный момент
    std::list<Creature*> creatures;  //!< вектор со всей живностью
    Coordinates borders;  //!< границы 3д аквариума
    LifeManager manager; //!< управляет жизнью в акваруиме (считает дни, двигает рыб, размножает, кормит и убивает)
};

#endif  //! AQUARIUM_H