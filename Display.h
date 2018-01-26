#ifndef DISPLAY_H
#define DISPLAY_H
#include <thread>
#include "Headers.h"
#include "Aquarium.h"
#include "Effect.h"
/*!
\brief Класс, реализующий отображение на экран


*/
class Display
{
public:
    Display(Aquarium* target, Texture* plankton, Texture* herbivore, Texture* carnivore);
    ~Display();
	void PullEvents() const;
	void DrawAquarium() const;
    Texture* getTexture(LifeType type);
private:
	Texture* plankton;
    Texture* herbivore;
    Texture* carnivore;
	//const Aquarium& aquarium;
    Aquarium* aquarium;
};
#endif  //! DISPLAY_H
