#ifndef OBJECT_h
#define OBJECT_h
#include "Field.h"
#include "Coordinates.h"
/*!
\brief Класс, реализующий анимацию

нужны комменты к полям и методам, чтобы я мог помочь и понять.
*/
class Object
{
public:
    Object();
    virtual ~Object();

    Vector2f GetPosition();
    Vector2f GetRotation();
    virtual Sprite GetSprite();
    void Resize();
    void SetSize(Vector2f);
 

protected:
	Object* that; //!<
	Field* field; //!<
	Sprite sprite; //!<
	Vector2f size; //!< размер чего?
	Vector2f position; //!< позиция на экране 
    Coordinates coordinates; //!< положение рыбы в аквариуме
	Vector2f rotation; //!<
	virtual void Calculate(); //!<

	Object(Field&, Vector2f);
};

#endif //! OBJECT_h