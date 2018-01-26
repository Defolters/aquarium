#include "Display.h"
#include <iostream>

//TODO more textures and animatios
Display::Display(Aquarium* target, Texture* plankton_, Texture* herbivore_, Texture* carnivore_)
{ 
	plankton = plankton_;
    herbivore = herbivore_;
    carnivore = carnivore_;
	aquarium = target;
	auto creatures = aquarium->getListOfCreatures();
	for (Creature* creature : creatures)
	{
		creature->bind(&MAIN_FIELD, creature->getSize());
        if (creature->getType() == LifeType::PLANKTON)
        {
            creature->initGraphics(plankton);
        }
        else if (creature->getType() == LifeType::HERBIVOREFISH)
        {
            creature->initGraphics(herbivore);
        }
        else
        {
            creature->initGraphics(carnivore);
        }
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
            if (ev->holder->getType() == LifeType::PLANKTON)
            {
                ev->holder->initGraphics(plankton);
            }
            else if (ev->holder->getType() == LifeType::HERBIVOREFISH)
            {
                ev->holder->initGraphics(herbivore);
            }
            else
            {
                ev->holder->initGraphics(carnivore);
            }
			//ev->holder->initGraphics(plankton);
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

Texture * Display::getTexture(LifeType type)
{
    if (type == LifeType::PLANKTON)
        return plankton;
    else if (type == LifeType::HERBIVOREFISH)
        return herbivore;
    else
        return carnivore;
}
