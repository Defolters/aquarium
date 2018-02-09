#include "Display.h"
#include <iostream>

//TODO more textures and animatios
Display::Display(Aquarium* target)
{ 
	Texture* killAtlas = new Texture();
	killAtlas->loadFromFile("blood_splat.png");
	killList = new SpriteList(*killAtlas, 133, 146, 1, std::vector<int>{4});
	killAnimation = Animation(killList, 0, 8);

	Texture* seaweedAtlas = new Texture();
	seaweedAtlas->loadFromFile("seaweed_list.png");
	seaweedList = new SpriteList(*seaweedAtlas, 60, 81, 3, std::vector<int>{8, 8, 8});

	Texture* fishAtlas = new Texture();
	fishAtlas->loadFromFile("fish_list.png");
	fishList = new SpriteList(*fishAtlas, 32, 26, 2, std::vector<int>{3, 3});
	herbivore = Animation(fishList, 1, 6);
	carnivore = Animation(fishList, 0, 6);

	seaweedAnims.emplace_back(seaweedList, 0, 4);
	seaweedAnims.emplace_back(seaweedList, 1, 4);
	seaweedAnims.emplace_back(seaweedList, 2, 4);

    plankton = new Texture();
    plankton->loadFromFile("plankton.png");
	aquarium = target;
    background = new Texture();
    background->loadFromFile("background.png");

    backgroundSp.setTexture(*background);
    backgroundSp.setPosition(0, 0);
    backgroundSp.setScale(0.5, 0.5);

	auto creatures = aquarium->getListOfCreatures();
	for (Creature* creature : creatures)
	{
		creature->bind(&MAIN_FIELD, creature->getSize());
        if (creature->getType() == LifeType::PLANKTON)
        {
            creature->initGraphicsTex(plankton);
        }
        else if (creature->getType() == LifeType::HERBIVOREFISH)
        {
            creature->initGraphicsAnim(herbivore);
        }
        else
        {
            creature->initGraphicsAnim(carnivore);
        }
		MAIN_FIELD.AddObject(creature);
	}

	target->bind();
	auto borders = aquarium->getBorders();
	CycledObject* backSeaweed1 = new CycledObject(seaweedAnims[0], Coordinates(borders.x-50, borders.y, 0), Vector2f(30,20));
	CycledObject* backSeaweed2 = new CycledObject(seaweedAnims[1], Coordinates(20, borders.y, 0), Vector2f(30, 30));
    CycledObject* backSeaweed3 = new CycledObject(seaweedAnims[0], Coordinates(borders.x -400, borders.y, 0), Vector2f(30,28));
    CycledObject* backSeaweed4 = new CycledObject(seaweedAnims[2], Coordinates(borders.x -550, borders.y, 0), Vector2f(30,25));
    CycledObject* backSeaweed5 = new CycledObject(seaweedAnims[0], Coordinates(borders.x -650, borders.y, 0), Vector2f(30,25));
    CycledObject* backSeaweed6 = new CycledObject(seaweedAnims[0], Coordinates(100, borders.y, 0), Vector2f(30,25));
    CycledObject* backSeaweed7 = new CycledObject(seaweedAnims[0], Coordinates(250, borders.y, 0), Vector2f(30,25));
    CycledObject* backSeaweed8 = new CycledObject(seaweedAnims[0], Coordinates(borders.x -200, borders.y, 0), Vector2f(30,25));


	MAIN_FIELD.AddObject(backSeaweed1);
	MAIN_FIELD.AddObject(backSeaweed2);
	MAIN_FIELD.AddObject(backSeaweed3);
    MAIN_FIELD.AddObject(backSeaweed4);
    MAIN_FIELD.AddObject(backSeaweed5);
    MAIN_FIELD.AddObject(backSeaweed6);
    MAIN_FIELD.AddObject(backSeaweed7);
    MAIN_FIELD.AddObject(backSeaweed8);
}


Display::~Display()
{
	delete killList;
	delete seaweedList;
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
                ev->holder->initGraphicsTex(plankton);
            }
            else if (ev->holder->getType() == LifeType::HERBIVOREFISH)
            {
                ev->holder->initGraphicsAnim(herbivore);
            }
            else
            {
                ev->holder->initGraphicsAnim(carnivore);
            }
		}
		else if (ev->type == EventType::DEATH)
			MAIN_FIELD.RemoveObject(ev->holder);
		else if (ev->type == EventType::KILL)
		{
			Effect* effect = new Effect(killAnimation, 0.5, ev->place);
			MAIN_FIELD.AddObject(effect);
			MAIN_FIELD.RemoveObject(ev->holder);
		}
		ev = getDisplayEvent();
	}
}

void Display::DrawAquarium() const
{
	PullEvents();
    Event ev;
    MAIN_WINDOW.pollEvent(ev);
	MAIN_WINDOW.clear();
    MAIN_WINDOW.draw(backgroundSp);
	MAIN_FIELD.HandleObjects();
	MAIN_WINDOW.display();
}
