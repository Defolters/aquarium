#pragma once
#include "Object.h"
#include "Animation.h"

class CycledObject :
	public Object
{
private:
	Animation animation;
public:
	CycledObject(Animation animation_, Coordinates position_, Vector2f size);
	Sprite getSprite() override;
};

