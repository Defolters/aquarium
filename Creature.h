#ifndef CREATURE_H
#define CREATURE_H
#include <mutex>
#include <list>
#include "Object.h"
#include "LifeType.h"
#include "TaskType.h"
//#include "Headers.h"
#include "LifeEvent.h"
#include "EventControll.h"
#include "Coordinates.h"
#include "Animation.h"
#include "Gene.h"
#include <list>

/*!
\brief Класс, реализующий живое создание

лайф менеджер вызывает функции так:
thinkAboutIt()
eat()
reproduce()
move()
Добавить наследование признаков + мутации
*/

class Creature abstract
	: public Object
{
public:
    Creature(LifeType type, Gene gene, LifeType prey, Coordinates position, unsigned int id);//int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed, unsigned int id);
    virtual ~Creature();
	void initGraphics(Texture* tex);
    //!планктон: если не находится в желаемой точке, то выбирает случайную точку(цель), до которой будет плыть.
    //!рыба: если голод ниже границы и период прошел, то смотрим вокруг и плывем к ближайшей рыбе размножаться
    //!рыба: если голод выше границы, то смотрим вокруг и плывем к жертве
    //!рыба: если никого не видно, то как и у планктона выбираем случайную цель и плывем к ней, пока никого не заметим
    virtual bool thinkAboutIt(std::list<Creature*>& creatures, Coordinates borders) = 0;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual bool eat(std::list<Creature*>& creatures) = 0;//!< восстанавливает голод, ест только кого-то рангом ниже, при этом создание рангом ниже должно умереть, или вообще не ест (планктон, например)
    virtual bool reproduce(std::list<Creature*>& creatures) = 0;  //!< существо размножается каждые reproductionPeriod дней
    bool move(); //!< передвигает существо к цели, если в этом ходу мы будем двигаться
    bool dayPassed(); //!< функция, которая уменьшает значения жизни, периода и голода и которую вызывает dayPassed() у LifeManager, 
    bool isDeadOfAge(); //!< true, если должны умереть от старости
    bool isDeadOfHunger(); //!< true, если должны умереть от голода
    LifeType getType(); //!< 
    Gene getGene(); //!< 
    unsigned int getId(); //!< 
    bool isReadyToReproduce(); //!< 
    void iSleptWithYou(); //!< 
    virtual unsigned int getPreyId() = 0;
    void isShouldDead();

    std::mutex spriteLocker; //!< ВТФ? ето для потоков, потом понадобится
protected:
    unsigned int id; //!< уникальный номер для каждого создания
    LifeType type; //!< тип создания
    LifeType prey; //!< кого мы едим 
    Gene gene; //!< ген рыбы с характеристикой (продолжительность жизни, кол-во дней без еды, период размножения)
    // ИЗМЕНЧИВЫЕ ПЕРЕМЕННЫЕ (меняются в процессе существования)
    int hunger;  //!< голод
    int age;  //!< количество дней, сколько живет рыба
    int reproductionReady;  //!< количество дней, сколько прошло после последнего размножения
    Coordinates direction;//!< координаты куда плыть
    TaskType task; //!< задание, которое за этот ход будет делать (default = TaskType::RUN)
};
#endif  //! CREATURE_H