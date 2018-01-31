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
    Display(Aquarium* target, Texture* plankton, Texture* background);
    ~Display();
	void PullEvents() const;
	void DrawAquarium() const;
    //Texture* getTexture(LifeType type);
private:
	SpriteList* killList;
	SpriteList* seaweedList;
	SpriteList* fishList;
	std::vector<Animation> seaweedAnims;
	Animation killAnimation;
    Texture* background;
    Sprite backgroundSp;
	Texture* plankton;
    Animation herbivore;
    Animation carnivore;
    Aquarium* aquarium;
};
#endif  //! DISPLAY_H
