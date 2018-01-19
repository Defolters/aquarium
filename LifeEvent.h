#ifndef LIFE_EVENT_H
#define LIFE_EVENT_H
/*!
\brief Класс, реализующий аквариум

Класс содержит лишь список рыб, характеристику аквариума и возможность
добавить/убрать рыбу (на случай рождения или смерти).
*/
#include "Coordinates.h"
#include <memory>

enum class EventType
{
	DEATH,
	KILL,
	BIRTH
};

//forward-declare creature
class Creature;
struct LifeEvent
{
	union 
	{
		Coordinates place;
	};
	std::shared_ptr<Creature> holder;
	EventType type;
	LifeEvent(Coordinates place_, std::shared_ptr<Creature> holder_, EventType type_)
	{
		place = place_;
		holder = holder_;
		type = type_;
	};
	~LifeEvent();
};
#endif //! LIFE_EVENT_H
