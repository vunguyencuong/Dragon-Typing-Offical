#include "StartScene.h"
#include "Game.h"
#include "PlayScene.h"

StartScene::StartScene()
{
	font.loadFromFile("./resources/Inter-Medium.ttf");
	//font.loadFromFile("E:\Game\pricedown bl.otf");
	text.setFont(font);
	text.setCharacterSize(25);
	//text.setFillColor(sf::Color::Red);
	s = "Press SPACE to play";
	text.setPosition(375, 450);
	text.setString(s);
}

void StartScene::render(sf::RenderWindow* window)
{
	startBackground.setSpeed(2);
	startBackground.render(window);
	startDragon.render(window);
	window->draw(text);
}

void StartScene::onEvent(sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::instance()->setScene(new PlayScene());
	}
}

void StartScene::update()
{
	startBackground.update();
}
