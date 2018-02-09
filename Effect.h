#ifndef EFFECT_H
#define EFFECT_H

/*!
\brief Класс, реализующий эффекты
*/
#include "Animation.h"
#include "Object.h"
class Effect 
	: public Object
{
public:
	Effect(Animation animation_, float life, Coordinates position_);
	void calculate() override;
private:
	Sprite getSprite() override;
	Animation animation;
	float startTime;
	float lifeSpan;
};

#endif //! EFFECT_H