#include "Game.h"
#include "StartScene.h"
#include "EndScene.h"

Game* Game::_instance = nullptr;

Game::Game()
{
	window = new sf::RenderWindow();
	scene = nullptr;
	soundController = nullptr;
}

void Game::init()
{
	scene = (Scene*) new StartScene();

	soundController = new SoundController();
	soundController->addSound("short", "./resources/Short.wav");
}

void Game::start()
{
	sf::Event event;

	int i = 0;
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			else if (scene)
				scene->onEvent(event);
		}

		if (scene)
		{
			window->clear();

			scene->update();
			scene->render(window);

			window->display();
		}

		if (soundController)
		{
			soundController->update();
		}
	}
}


void Game::setFrameRateLimit(unsigned int limit)
{
	window->setFramerateLimit(limit);
}

void Game::setScene(Scene* scene)
{
	Game::scene = scene;
}

Game* Game::instance()
{
	if (Game::_instance == nullptr)
		Game::_instance = new Game();
	return Game::_instance;
}

SoundController& Game::getSoundController()
{
	return *soundController;
}

void Game::setup(int width, int height, std::string title)
{
	window->create(sf::VideoMode(width, height), title);
}


