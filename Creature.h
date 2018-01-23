#ifndef CREATURE_H
#define CREATURE_H
#include "Object.h"
#include "LifeType.h"
#include "TaskType.h"
#include "LifeEvent.h"
#include "EventControll.h"
#include <mutex>
#include "Coordinates.h"
#include "Animation.h"
#include <list>
/*!
\brief Класс, реализующий живое создание

нужны комменты к полям и методам, чтобы я мог помочь и понять.
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
    Creature(LifeType type, LifeType prey, int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed);
    virtual ~Creature();
	void initGraphics(Texture* tex);
    //!планктон: если не находится в желаемой точке, то выбирает случайную точку(цель), до которой будет плыть.
    //!рыба: если голод ниже границы и период прошел, то смотрим вокруг и плывем к ближайшей рыбе размножаться
    //!рыба: если голод выше границы, то смотрим вокруг и плывем к жертве
    //!рыба: если никого не видно, то как и у планктона выбираем случайную цель и плывем к ней, пока никого не заметим
    virtual bool thinkAboutIt(std::list<Creature*>& creatures) = 0;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual bool eat() = 0;//!< восстанавливает голод, ест только кого-то рангом ниже, при этом создание рангом ниже должно умереть, или вообще не ест (планктон, например)
    virtual bool reproduce() = 0;  //!< существо размножается каждые reproductionPeriod дней
    bool move(); //!< передвигает существо к цели, если в этом ходу мы будем двигаться
    bool dayPassed(); //!< функция, которая уменьшает значения жизни, периода и голода и которую вызывает dayPassed() у LifeManager, 
    bool isDeadOfAge(); //!< true, если должны умереть от старости
    bool isDeadOfHunger(); //!< true, если должны умереть от голода
    
    std::mutex spriteLocker; //!< ВТФ? ето для потоков, потом понадобится
protected:
    LifeType type; //!< тип создания
    LifeType prey; //!< кого мы едим (как быть с этим для планктона? или там eat не реализован, поэтому все ок?) ДОБАВИТЬ В КОНСТРУКТОР
    int lifeExpectancy;  //!< продолжительность жизни
    int lifeWitoutFood; //!< сколько может жить без еды
    int reproductionPeriod; //!< период размножения (кажд 2 дня планктон делится, а рыба плывет к другой, чтобы размножиться)  
    int rangeOfVision;  //!< дальность зрения рыбы (как далеко видит вокруг)
    int hungerLimit;  //!< граница голода (выше - очень плохо!!)
    int speed; //!< скорость перемещения (влияет на то, сколько шагов движения мы можем сделать?)

    // ИЗМЕНЧИВЫЕ ПЕРЕМЕННЫЕ (меняются в процессе существования)
    int hunger;  //!< голод
    int age;  //!< количество дней, сколько живет рыба
    int reproductionReady;  //!< количество дней, сколько прошло после последнего размножения
    Coordinates direction;//!< координаты куда плыть
    TaskType task; //!< задание, которое за этот ход будет делать (default = TaskType::RUN)
}; 

#endif  //! CREATURE_H