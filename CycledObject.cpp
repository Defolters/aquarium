#include "CycledObject.h"


CycledObject::CycledObject(Animation animation_, Coordinates position_, Vector2f size)
	: Object(position_)
{
	animation = animation_;
	bind(&MAIN_FIELD, size);
	sprite.setTexture(animation.GetSpriteList()->atlas);
}

Sprite CycledObject::getSprite()
{
	Sprite res = sprite;
	Vector2f scale = Vector2f(res.getScale().x / 100 * (100 - position.z*downByUnit), res.getScale().y / 100 * (100 - position.z*downByUnit));
	res.setTextureRect(animation.GetRect());
	res.setScale(scale);
	return res;
}