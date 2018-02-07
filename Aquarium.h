#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <list>
#include <mutex>
#include <queue>
//#include <ctime>
#include <windows.h>
#include "Creature.h"
#include "CarnivoreFish.h"
#include "HerbivoreFish.h"
#include "Plankton.h"
#include "LifeManager.h"


/*!
\brief Класс, реализующий аквариум

Класс содержит лишь список рыб, характеристику аквариума и возможность 
добавить/убрать рыбу (на случай рождения или смерти).
*/
//using std::shared_ptr;
class Display;
class Aquarium
{
public:
    Aquarium(int capacity, Coordinates borders); //!< 
    ~Aquarium();
	void bind();
    void initialize(unsigned int numbP, unsigned int numbHF, unsigned int numbCF);
    void startGame(bool isForever, int ticks, Display* display); //!< даем сигнал менеджеру, чтобы запустить цикл работы продолжительностью ticks, if isForever is false, else work forever

    bool addCreature(LifeType type, Gene gene, Coordinates coord);  //!< добавить создание в аквариум по типу (у аквариума должен быть доступ к конструкторам созданий)
    bool removeCreature(unsigned int id);  //!< убрать создание по индексу в векторе // or by id
    bool removeCreature(std::list<Creature*>::iterator iterator);  //!< убрать создание по индексу в векторе // or by id

    void setCapacity(int capacity);  //!< устанавливает размер аквариума
    int getCapacity() const;  //!< возвращает размер аквариума

    void setBorders(Coordinates borders); //!< устанавливает границы аквариума
    Coordinates getBorders() const; //!< возвращает границы аквариума

    int getNumberOfCreatures() const; //< возвращает количество рыб в данный момент
    std::list<Creature*>& getListOfCreatures(); //< возвращает список рыб

    int getNumberOfP();
    int getNumberOfHF();
    int getNumberOfCF();

	std::mutex eventQueueLocker; //!< для многопоточности?

private:
	bool binded = false;
    unsigned int capacity;  //!< максимальное количество рыб
    unsigned int lastId; //!< последний выданный ID
    std::list<Creature*> creatures;  //!< вектор со всей живностью
    std::list<std::shared_ptr<Creature>> creatures1;  //!< вектор со всей живностью
    Coordinates borders;  //!< границы 3д аквариума
    LifeManager manager; //!< управляет жизнью в акваруиме (считает дни, двигает рыб, размножает, кормит и убивает)
    Display* display;
    int numberOfPlankton;
    int numberOfHarbivore;
    int numberOfCarnivore;
};

#endif  //! AQUARIUM_H