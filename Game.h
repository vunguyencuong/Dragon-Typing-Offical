#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Scene.h"
#include "SoundController.h"

class Game
{
	static Game* _instance;

	Scene* scene;
	SoundController* soundController;

	std::vector<GameObject*> objects;
	sf::RenderWindow* window;

	sf::Clock clock;

public:
	Game();

	void init();
	void start();
	void setFrameRateLimit(unsigned int limit);
	void setScene(Scene* scene);
	void setup(int width, int height, std::string title);
	SoundController& getSoundController();

	static Game* instance();
};