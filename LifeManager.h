﻿#ifndef LIFE_MANAGER_H
#define LIFE_MANAGER_H
#include <list>
#include "Creature.h"

/*!
\brief Класс, реализующий управление аквариумом
В нем течет жизнь
*/
class Aquarium;
class Display;
class LifeManager
{
public:
    LifeManager(Aquarium* aquarium, std::list<Creature* >& creatures);
    ~LifeManager();

    void makeTurn();
    void onThinking() const;
    void onEating();  //!< ход прием пищи
    void onReproducing(); //!<  ход размножение
    void onMoving() const;  //!< ход движение
    void dayPassed();  //! ход день прошел
    void onKilling();  //!< kill fishes, which died of old age or hunger
    void printState(); // напечатать статистику (кол-во рыб всяких) в консоль

private:
    unsigned int day; //! количество прошедших дней
    int deadOfAge; //!< количество умерших от старости
    int deadOfHunger; //!< количество умерших от голода
    int newborns; //!< количество новорожденных
    int eaten;
    Aquarium* aquarium;
    std::list<Creature* >& creatures;
	bool isForever;
	int ticks;
};

#endif //! LIFE_MANAGER_H