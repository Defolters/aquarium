#include "Object.h"
#include <algorithm>
#include <iostream>

Object::Object(Coordinates position)
    : position(position)
{
	that = this;
}

void Object::bind(Field* origin, Vector2f size_)
{
	that = this;
	size = size_;
	field = origin;
	calculate();
}

void Object::calculate()
{
	resize();
	sprite.setPosition(field->WorldToScreenPoint(position.toVector2f()));
}

Object::~Object()
{
	delete animation;
}


Coordinates Object::getPosition()
{
	return position;
}

void Object::setPosition(Coordinates coord)
{
	sprite.setPosition(coord.toVector2f());
}

Vector2f Object::getRotation()
{
	return rotation;
}

Vector2f Object::getSize()
{
	return size;
}

Sprite Object::getSprite()
{
	if (animation != nullptr)
		sprite.setTextureRect(animation->GetRect());
    return sprite;
}

Field* Object::getField()
{
	return field;
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

bool Field::AddObject(Object* object)
{
	if (std::find(objects.begin(), objects.end(), object) == objects.end())
	{
		objects.push_back(object);
		if (object->getField() == nullptr)
			object->bind(this, object->getSize());//TODO sizes
		return true;
	}
	else
		return false;
}

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
	auto objects_copy = new std::vector<Object*>(objects);
	for (auto obj : *objects_copy)
		obj->calculate();
	delete objects_copy;
	for (auto obj : objects)
	{
		Sprite toDisplay = obj->getSprite();
        Vector2f origin;
        Vector2f position;
        //horizont
        origin.x = toDisplay.getLocalBounds().left + toDisplay.getLocalBounds().width / 2.0f;
        //vertical
        origin.y = toDisplay.getLocalBounds().top + toDisplay.getLocalBounds().height / 2.0f;

        toDisplay.setOrigin(origin);
        toDisplay.setPosition(obj->getPosition().toVector2f());// - WorldToScreenPoint(cameraPosition));
		//TODO size
		window->draw(toDisplay);
	}
}

int Field::GetObjectCount()
{
	return objects.size();
}

void Field::RemoveObject(Object * ptr)
{
	auto itr = std::find(objects.begin(), objects.end(), ptr);
    if (itr != objects.end())
    {
        delete(*itr);
        objects.erase(itr);
    }
}