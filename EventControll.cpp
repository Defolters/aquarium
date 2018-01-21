#include "EventControll.h"
#include <exception>

std::queue<std::shared_ptr<LifeEvent>> manager_event_queue;
std::queue<std::shared_ptr<LifeEvent>> display_event_queue;

std::shared_ptr<LifeEvent> getManagerEvent()
{
	if (manager_event_queue.size() == 0)
		return std::shared_ptr<LifeEvent>(nullptr);
	std::shared_ptr<LifeEvent> res = manager_event_queue.front();
	manager_event_queue.pop();
	return res;
}

std::shared_ptr<LifeEvent> getDisplayEvent()
{
	if (display_event_queue.size() == 0)
		return std::shared_ptr<LifeEvent>(nullptr);
	std::shared_ptr<LifeEvent> res = display_event_queue.front();
	display_event_queue.pop();
	return res;
}

void throwEvent(Coordinates coordinates_, EventType type_, Creature* holder_)
{
	std::shared_ptr<LifeEvent> evt = std::make_shared<LifeEvent>(coordinates_, holder_, type_);
	display_event_queue.push(evt);
    manager_event_queue.push(evt);
}