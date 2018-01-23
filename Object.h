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
	Object(Field&, Vector2f);
    virtual ~Object();

    Coordinates getPosition();
    void setPosition(Vector2f coord);
    Vector2f getRotation();
	Vector2f getSize();
    virtual Sprite getSprite();
	Field* getField();
    void resize();
    void setSize(Vector2f size);
	void bind(Field*, Vector2f);

protected:
	Object* that; //!<
	Field* field = nullptr; //!<
	Sprite sprite; //!<
	Vector2f size; //!< размер чего? - спрайта
	//Vector2f position; //!< позиция на экране 
    Coordinates position; //!< положение рыбы в аквариуме
	Vector2f rotation; //!<
	virtual void calculate(); //!<
};

#endif //! OBJECT_h