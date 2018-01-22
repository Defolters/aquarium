#include "Object.h"
#include <algorithm>

Object::Object(Coordinates position)
    : position(position)
{
}

void Object::calculate()
{
	resize();
	sprite.setPosition(field->WorldToScreenPoint(position.toVector2f()));
}

Object::Object(Field & origin, Vector2f size_)
{
	that = this;
	size = size_;
	field = &origin;
	field->AddObject(this);
	float scale = field->GetScale();
	sprite.setScale((size.x / scale)/sprite.getLocalBounds().width, (size.y / scale) / sprite.getLocalBounds().height);
}

Object::~Object()
{
}



Coordinates Object::getPosition()
{
	return position;
}

Vector2f Object::getRotation()
{
	return rotation;
}

Sprite Object::getSprite()
{
    return Sprite();
}

void Object::resize()
{
	float scale = field->GetScale();
	sprite.setScale((size.x / scale) / sprite.getLocalBounds().width, (size.y / scale) / sprite.getLocalBounds().height);
}

void Object::setSize(Vector2f size_)
{
	size = size_;
	calculate();
}


//FIFNISHING FIELD CLASS
void Field::HandleObjects()
{
	if (clearOutOfBounds)//TODO part of image visible
	{
		for (auto obj = objects.begin(); obj != objects.end();)
			if (!displayedRect.contains((*obj)->getPosition().toVector2f()))
			{
				delete(*obj);
				obj = objects.erase(obj);
			}
			else obj++;
	}
	for (auto obj : objects)
	{
		Sprite toDisplay = obj->getSprite();
		toDisplay.setPosition(toDisplay.getPosition() - WorldToScreenPoint(cameraPosition));
		window->draw(toDisplay);
	}
}


void Field::RemoveObject(Object * ptr)
{
	auto itr = std::find(objects.begin(), objects.end(), ptr);
	if (itr != objects.end())
		objects.erase(itr);
}