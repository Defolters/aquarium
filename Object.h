#ifndef OBJECT_h
#define OBJECT_h
#include "Field.h"
#include "Coordinates.h"
/*!
\brief Класс, реализующий объект

нужны комменты к полям и методам, чтобы я мог помочь и понять.
*/
class Object
{
public:
    Object();
    virtual ~Object();

    Coordinates getPosition();
    void setPosition(Coordinates coord);
    Vector2f getRotation();
    virtual Sprite getSprite();
    void resize();
    void setSize(Vector2f size);

 

protected:
	Object* that; //!<
	Field* field; //!<
	Sprite sprite; //!<
	Vector2f size; //!< размер чего?
	//Vector2f position; //!< позиция на экране 
    Coordinates position; //!< положение рыбы в аквариуме
	Vector2f rotation; //!<
	virtual void calculate(); //!<

	Object(Field&, Vector2f);
};

#endif //! OBJECT_h