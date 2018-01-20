#ifndef EVENT_CONTROLL_H
#define EVENT_CONTROLL_H
#include <queue>
#include <memory>
#include "LifeEvent.h"
std::shared_ptr<LifeEvent> getManagerEvent();
std::shared_ptr<LifeEvent> getDisplayEvent();
void throwEvent(Coordinates coordinates_, EventType type_, Creature* holder_); //defined in "Creature.cpp"
#endif //! EVENT_CONTROLL_H