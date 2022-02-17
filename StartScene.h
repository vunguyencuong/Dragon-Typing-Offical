#pragma once
#include "Scene.h"
#include "Dragon.h"
#include "BackGround.h"
class StartScene : public Scene
{
	Dragon startDragon;
	BackGround startBackground;

	sf::Text text;
	sf::Font font;
	std::string s;

public:
	StartScene();
	virtual void render(sf::RenderWindow* window);
	virtual void onEvent(sf::Event& event);
	virtual void update();
};

