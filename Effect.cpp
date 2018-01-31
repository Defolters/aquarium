#include "Effect.h"

Effect::Effect(Animation animation_, float lifeSpan_, Coordinates position_)
	: Object(position_)
{
	animation = animation_;
	lifeSpan = lifeSpan_;
	bind(&MAIN_FIELD, Vector2f(1, 1));
	startTime = CLOCK.getElapsedTime().asSeconds();
	sprite.setTexture(animation.GetSpriteList()->atlas);
}

void Effect::calculate()
{
	Object::calculate();
	if (CLOCK.getElapsedTime().asSeconds() - startTime > lifeSpan)
	{
		field->RemoveObject(this);
	}
}

Sprite Effect::getSprite()
{
	Sprite res = sprite;
	Vector2f scale = Vector2f(res.getScale().x / 100 * (100 - position.z*downByUnit), res.getScale().y / 100 * (100 - position.z*downByUnit));
	res.setTextureRect(animation.GetRect());
	res.setScale(scale);
	return res;
}
