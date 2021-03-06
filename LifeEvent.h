﻿#ifndef LIFE_EVENT_H
#define LIFE_EVENT_H
#include <iostream>
#include "Coordinates.h"
#include <memory>
using std::shared_ptr;
enum class EventType
{
	DEATH,
	BIRTH,
	KILL
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
    ~LifeEvent() {}
};
#endif //! LIFE_EVENT_H
