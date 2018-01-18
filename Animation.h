#ifndef ANIMATION_H
#define ANIMATION_H
#include "SpriteList.h"

/*!
\brief Класс, реализующий анимацию

нужны комменты к полям и методам, чтобы я мог помочь.
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
