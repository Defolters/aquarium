﻿#ifndef ANIMATION_H
#define ANIMATION_H
#include "SpriteList.h"
#include "Headers.h"

/*!
\brief Класс, реализующий анимацию
*/
class Animation
{
public:
    SpriteList * GetSpriteList();
    Animation(SpriteList*, int, float);
    Animation() = default;
    void Start();
    void Stop();
    IntRect GetRect();
    ~Animation();

protected:
	SpriteList* list;
	bool cycle;
	int row;
	float framesPerSecond;
	float lastTime;
	IntRect rect;

};
#endif //!ANIMATION_H
