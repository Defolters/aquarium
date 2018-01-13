#ifndef AQUARIUM_H
#define AQUARIUM_H
#include <vector>
#include "Creature.h"
//! типы созданий
enum class Type {
    PLANKTON,
    HERBIVOREFISH,
    CARNIVOREFISH //??
};

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
    
    bool addCreature(Type type_);  //! добавить создание в аквариум по типу
    bool removeCreature(int index_);  //! убрать создание из аквариума по индексу в векторе
    void setCapacity(int capacity_);  //! устанавливает размер аквариума
    int getCapacity();  //! возвращает размер аквариума
    std::vector<Creature*> getListOfCreatures();  //!< используется в LifeManager для вывода статистики на экран и может использоваться в Display, чтобы пройтись по вектору и получить координаты для отображения
    int checkSize();  //!< используется в LifeManager для проверки, что живность не вымерла и пора выходить из игры
    
private:
    
    int capacity;  //! максимальное количество рыб
    std::vector<Creature* > creatures;  //! вектор со всей живностью
};

#endif  //! AQUARIUM_H