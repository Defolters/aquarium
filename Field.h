#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include "Headers.h"
class Object;
/*!
\brief Класс, реализующий анимацию

нужны комменты к полям и методам, чтобы я мог помочь и понять.
*/
class Field
{
protected:
	bool clearOutOfBounds;
	FloatRect displayedRect;
	std::vector<Object*> objects;
	float scale;
	Texture* background;
	Vector2f cameraPosition;
	Vector2f backSize;
	RenderWindow* window;
public:
	Field(float, RenderWindow&, Vector2f = Vector2f(0, 0), bool = false,Texture* = nullptr, Vector2f = Vector2f(0, 0));
	void CalculateDisplayedRect();
	void HandleObjects();
	bool AddObject(Object*);
	float GetScale() const;
	void RemoveObject(Object*);
	Vector2f GetCameraPosition();
	void SetCameraPosition(Vector2f);
	Vector2f WorldToScreenPoint(Vector2f);
	Vector2f ScreenToWorldPoint(Vector2f);
	const RenderWindow* GetWindow();
	~Field();
};

#endif //! FIELD_H