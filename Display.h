#ifndef DISPLAY_H
#define DISPLAY_H
#include <thread>
#include "Headers.h"
#include "Aquarium.h"
#include "Effect.h"
#include "CycledObject.h"

/*!
\brief Класс, реализующий отображение на экран
*/
class Display
{
public:
    Display(Aquarium* target);
    ~Display();
	void PullEvents() const;
	void DrawAquarium() const;
private:
	SpriteList* killList;
	SpriteList* seaweedList;
	SpriteList* fishList;
	std::vector<Animation> seaweedAnims;
	Animation killAnimation;
    Texture* background;
    Texture* plankton;
    Sprite backgroundSp;
    Animation herbivore;
    Animation carnivore;
    Aquarium* aquarium;
};
#endif  //! DISPLAY_H
