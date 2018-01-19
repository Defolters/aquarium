#ifndef CREATURE_H
#define CREATURE_H
#include "Object.h"
#include "LifeType.h"
#include "TaskType.h"
#include "LifeEvent.h"
#include <mutex>
#include "Coordinates.h"
#include <list>
/*!
\brief Класс, реализующий живое создание

нужны комменты к полям и методам, чтобы я мог помочь и понять.
лайф менеджер вызывает функции так:
thinkAboutIt()
eat()
reproduce()
move()
*/

class Creature //abstract?
	: Object
{
public:
    Creature(LifeType type, LifeType prey, int lifeExpectancy, int lifeWitoutFood, int reproductionPeriod, int rangeOfVision, int hungerLimit, int speed);
    virtual ~Creature();
    //!планктон: если не находится в желаемой точке, то выбирает случайную точку(цель), до которой будет плыть.
    //!рыба: если голод ниже границы и период прошел, то смотрим вокруг и плывем к ближайшей рыбе размножаться
    //!рыба: если голод выше границы, то смотрим вокруг и плывем к жертве
    //!рыба: если никого не видно, то как и у планктона выбираем случайную цель и плывем к ней, пока никого не заметим
    virtual void thinkAboutIt(std::list<Creature*>& creatures) = 0;//!< каждое существо рефлексирует и строит планы на будущее (чем заняться и в какую координату плыть) (СВЯЗАТЬ С ENUM)
    virtual void eat() = 0;//!< восстанавливает голод, ест только кого-то рангом ниже, при этом создание рангом ниже должно умереть, или вообще не ест (планктон, например)
    virtual bool reproduce() = 0;  //!< размножается (как добавить новую рыбу в аквариум?)
    virtual Coordinates move() = 0; //!< передвигает жертву к цели, если в этом ходу мы будем двигаться
    void dayPassed();  //!< функция, которая уменьшает значения жизни, периода и голода и которую вызывает dayPassed() у LifeManager, 
    
    std::mutex spriteLocker; //!< ВТФ?
protected:
    LifeType type; //!< тип создания
    LifeType prey; //!< кого мы едим (как быть с этим для планктона? или там eat не реализован, поэтому все ок?) ДОБАВИТЬ В КОНСТРУКТОР
    int lifeExpectancy;  //!< продолжительность жизни
    int lifeWitoutFood; //!< сколько может жить без еды
    int reproductionPeriod; //!< период размножения (кажд 2 дня планктон делится, а рыба плывет к другой, чтобы размножиться)  
    int rangeOfVision;  //!< дальность зрения рыбы (как далеко видит вокруг)
    int hungerLimit;  //!< граница голода (выше - очень плохо!!)
    int speed; //!< скорость перемещения

    // ИЗМЕНЧИВЫЕ ПЕРЕМЕННЫЕ (меняются в процессе существования)
    int lifeDaysLeft;  //!< количество дней, которые осталось жить рыбе
    int hunger;  //!< голод
    int reproductionDaysLeft;  //!< количество дней, кот. остались до следующего размножения
    Coordinates purpose;//!< координаты куда плыть
    TaskType task; //!< задание, которое за этот ход будет делать
}; 

#endif  //! CREATURE_H