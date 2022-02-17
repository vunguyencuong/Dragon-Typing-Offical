
#include "BackGround.h"
#include <iostream>

BackGround::BackGround()
{
	speed = 2.f;

	bg.loadFromFile("./resources/BackGround.png");

	bgSprite[0].setTexture(bg);
	bgSprite[1].setTexture(bg);


	w = bgSprite[0].getLocalBounds().width;
	h = bgSprite[0].getLocalBounds().height;

	for (int i = 0; i < 2; i++)
	{
		bgSprite[i].setPosition(i * w, 0);
	}

}

float BackGround::getSpeed()
{
	return speed;
}

void BackGround::setSpeed(float speed)
{
	this->speed = speed;
}

void BackGround::update()
{
	for (int i = 0; i < 2; i++)
	{
		sf::Vector2f oldPos = bgSprite[i].getPosition();
		bgSprite[i].setPosition(oldPos.x - speed, oldPos.y);
	}
}

void BackGround::render(sf::RenderWindow* window)
{
	for (int i = 0; i < 2; i++)
	{
		if (bgSprite[i].getPosition().x <= -w)
		{
			bgSprite[i].setPosition(w, bgSprite[i].getPosition().y);
		}

		window->draw(bgSprite[i]);
	}
}
