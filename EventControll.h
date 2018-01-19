#ifndef EVENT_CONTROLL_H
#define EVENT_CONTROLL_H
#include <queue>
#include <memory>
#include "LifeEvent.h"
extern std::queue<std::shared_ptr<LifeEvent>> manager_event_queue;
extern std::queue<std::shared_ptr<LifeEvent>> display_event_queue;
void throwEvent(Coordinates coordinates_, EventType type_, std::shared_ptr<Creature> holder_); //defined in "Creature.cpp"
#endif //! EVENT_CONTROLL_H