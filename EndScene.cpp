#include "EndScene.h"
#include "Game.h"
#include "PlayScene.h"
#include <iostream>
#include "GameScore.h"
EndScene::EndScene(GameScore* gameScore)
{
	gameScore->saveScore();
	font.loadFromFile("./resources/Inter-Medium.ttf");
	//font.loadFromFile("E:/Game/Haedus-nRGn4.ttf");
	text1.setFont(font);
	text1.setCharacterSize(35);
	text2.setFont(font);
	text2.setCharacterSize(30);
	text3.setFont(font);
	text3.setCharacterSize(25);
	text4.setFont(font);
	text4.setCharacterSize(30);
	text5.setFont(font);
	text5.setCharacterSize(35);
	s1 = "Your Score";
	s2 = "Press SPACE to replay";
	s3 = "High Score";
	score = std::to_string(gameScore->getResults());
	highsc = std::to_string(gameScore->getHighScore());
	text1.setString(s1);
	text1.setPosition(300, 250);
	text2.setString(score);
	text2.setPosition(365, 300);
	text3.setString(s2);
	text3.setPosition(365, 450);
	text4.setString(highsc);
	text4.setPosition(610, 300);
	text5.setString(s3);
	text5.setPosition(550, 250);
	counter = 20;
}

void EndScene::render(sf::RenderWindow* window)
{
	if (counter > 0)
		counter--;
	endBackground.setSpeed(0.5 + counter / 20.0);
	endBackground.render(window);
	window->draw(text1);
	window->draw(text2);
	window->draw(text3);
	window->draw(text4);
	window->draw(text5);
}

void EndScene::update()
{
	endBackground.update();
}

void EndScene::onEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			Game::instance()->setScene(new PlayScene());
}
