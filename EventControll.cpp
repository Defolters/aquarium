#include "EventControll.h"

std::queue<std::shared_ptr<LifeEvent>> manager_event_queue;
std::queue<std::shared_ptr<LifeEvent>> display_event_queue;

void throwEvent(Coordinates coordinates_, EventType type_, std::shared_ptr<Creature> holder_)
{
    auto evt = std::make_shared<LifeEvent>(coordinates_, holder_, type_);
    display_event_queue.push(evt);
    manager_event_queue.push(evt);
}