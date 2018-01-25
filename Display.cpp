#include "Display.h"
#include <iostream>

//TODO more textures and animatios
Display::Display(Aquarium* target, Texture* plankton_)
{ 
	plankton = plankton_;
	aquarium = target;
	auto creatures = aquarium->getListOfCreatures();
	for (Creature* creature : creatures)
	{
		creature->bind(&MAIN_FIELD, creature->getSize());
		creature->initGraphics(plankton);
		MAIN_FIELD.AddObject(creature);
	}
	target->bind();
}


Display::~Display()
{
}


void Display::PullEvents() const
{
	auto ev = getDisplayEvent();
	while (ev.get() != nullptr)
	{
		if (ev->type == EventType::BIRTH)
		{
			MAIN_FIELD.AddObject(ev->holder);
			ev->holder->initGraphics(plankton);
		}
		else if (ev->type == EventType::DEATH)
			MAIN_FIELD.RemoveObject(ev->holder);
		ev = getDisplayEvent();
	}
}

void Display::DrawAquarium() const
{
	PullEvents();
	//std::cout << "Objects: " << MAIN_FIELD.GetObjectCount() << std::endl;
	MAIN_WINDOW.clear();
	MAIN_FIELD.HandleObjects();
	MAIN_WINDOW.display();
}
