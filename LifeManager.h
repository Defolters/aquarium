#ifndef LIFE_MANAGER_H
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

    void startGame(bool isForever, int ticks, Display* display);
    void onThinking() const;
    void onEating() const;  //!< ход прием пищи
    void onReproducing(); //!<  ход размножение
    void onMoving() const;  //!< ход движение
    void dayPassed();  //! ход день прошел
    void onKilling();  //!< kill fishes, which died of old age or hunger (теоретически, функционал этого метода можно перенести в dayPassed)
    void printState(); // напечатать статистику (кол-во рыб всяких) в консоль
    void eventEveryWeek() const;

private:
    unsigned int day; //! количество прошедших дней
    int deadOfAge; //!< количество умерших от старости
    int deadOfHunger; //!< количество умерших от голода
    int newborns; //!< количество новорожденных
    int eaten;
    //std::unique_ptr<Aquarium> aquarium;
    Aquarium* aquarium;
    std::list<Creature* >& creatures;

	bool isForever;
	int ticks;
};

#endif //! LIFE_MANAGER_H