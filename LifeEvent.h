#ifndef LIFE_EVENT_H
#define LIFE_EVENT_H
#include <iostream>
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
	Coordinates place;
	Creature* holder;
	EventType type;
	LifeEvent(Coordinates place_, Creature* holder_, EventType type_)
	{
		place = place_;
		holder = holder_;
		type = type_;
	};
	~LifeEvent() { std::cout << "blet_event" << std::endl; }
};
#endif //! LIFE_EVENT_H
