﻿#ifndef LIFE_MANAGER_H
#define LIFE_MANAGER_H
#include <list>
#include "Creature.h"
/*!
\brief Класс, реализующий управление аквариумом

Он - основа всей работы, в нем выполняется последовательно ходы, их очередность такова:
1) Получить из аквариума список рыб //<- раньше у тебя метод ГетВекторСуществ вернул бы копию вектора, я сделал чтоб он возвращал ссылку
2) Ход убийство. Проверить, что никто не должен умереть, если чьи-то дни сочтены, то убить эту тварь //<- мб ход "естественная смерть? а то я не сразу понял про что тут по названию
(этот ход первый для того, чтобы при инициализации не создались зомби, которые будучи мертвыми будут есть и размножаться)
3) Ход движение. Произвести движение для каждой рыбы (вызывается функция move у creature, 
каждая рыба должна видеть карту, чтобы знать куда плыть (пожрать или потрахаться; приоритет потрахаться, но только если мне не грозит смерть от голода)) 
// можно ли двум рыбам находится в одной точке? //<- да, нахождение пути с обходом препятствий это могила
4) Ход прием пищи. Если рыба(хищная рыба) находится там же или рядом с планктоном (рыбой), 
то рыба(хищная рыба) съедает планктон(рыбу) (голод у рыбы(хищной рыбы) уменьшается, планктон(рыба) умирает).
// надо как-то использовать функцию eat у созданий, которая будет возвращать убитую рыбу?
4,5) Надо убить тех, кого съели. 
5) Ход размножение. Если два создания одного типа находятся в одной точке(или рядом) 
и хотя бы одно (секс по обоюдному согласию не для нас) создание готово размножаться (период закончился), то создать новую рыбу рядом и увеличить период //<-мб лучше если оба? так даже реалистичнее (в плане биологии)
// если обе рыбы хотят размножаться, то создать две рыбы, ничего плохого в этом нет, у них вообще там нерест должен быть, но не надо.//<- почему нет? звучит не слишком сложно, потом можно попробовать когда база будет
// планктон размножается делением, ему не нужно быть рядом с другим планктоном, 
//т.е вызывается функция reproduce, которая для каждого создания разная, если она возвращает true, то создать создание такого же типа
6) Ход день прошел. Увеличить голод, уменьшить жизнь у каждого создания.
7) Написать логи в консоль и перерисовать изображение на экране
//Порядок 6 или 7 выбрать
*/
class Aquarium;
class LifeManager
{
public:
    LifeManager();
    ~LifeManager();

	//Везде видел что такие методы называют OnЧто-то. Хз почему но мы тоже не сирые.
    void onPlanning() const;
    void onKilling() const;  //! ход убийство
    void onMoving() const;  //! ход движение
    void onEating() const;  //! ход прием пищи
    void onMating() const; //!  ход размножение
    void dayPassed();  //! ход день прошел
    void printState() const; // напечатать статистику (кол-во рыб всяких) в консоль

private:
    unsigned int days;  //! количество прошедших дней
    //std::unique_ptr<Aquarium> aquarium;
};

#endif //! LIFE_MANAGER_H