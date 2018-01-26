#ifndef OBJECT_h
#define OBJECT_h
#include "Field.h"
#include "Coordinates.h"
/*!
\brief Класс, реализующий объект


*/
//using std::shared_ptr;
class Object
{
public:
    //Object();
	//Object(Field&, Vector2f);
    Object(Coordinates position);
    virtual ~Object();

    Coordinates getPosition();
    void setPosition(Coordinates coord);
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
    Coordinates position; //!< положение рыбы в аквариуме
	Vector2f rotation; //!<
	virtual void calculate(); //!<
};

#endif //! OBJECT_h