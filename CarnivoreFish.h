#ifndef CARNIVORE_FISH_H
#define CARNIVORE_FISH_H
#include "Fish.h"
/*!
\brief Класс, реализующий анимацию

нужны комменты к полям и методам, чтобы я мог помочь и понять.
*/
class CarnivoreFish :
    public Fish
{
public:
    CarnivoreFish();
    virtual ~CarnivoreFish();
private:
    LifeType type = LifeType::CARNIVOREFISH;
};

#endif //! CARNIVORE_FISH_H