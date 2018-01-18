#pragma once
#include "Field.h"
#include "Coordinates.h"

class Object
{
protected:
	Object* that;
	Field* field;
	Sprite sprite;
	Vector2f size;
	Vector2f position; //on the screen 
    Coordinates coordinates; //! положение рыбы в аквариуме
	Vector2f rotation;
	virtual void Calculate();

	Object(Field&, Vector2f);
public:
	Vector2f GetPosition();
	Vector2f GetRotation();
	virtual Sprite GetSprite() = 0;
	void Resize();
	void SetSize(Vector2f);
	virtual ~Object();
};

