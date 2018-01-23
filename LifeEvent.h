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
	EventType type;
    Creature* holder;
	LifeEvent(Coordinates place_, EventType type_, Creature* holder_)
	{
		place = place_;
		type = type_;
        holder = holder_;
	};
	~LifeEvent() { std::cout << "blet_event" << std::endl; }
};
#endif //! LIFE_EVENT_H
