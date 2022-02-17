#pragma once
#include<SFML/Graphics.hpp>
#include"GameObject.h"
using namespace std;
class BackGround : public GameObject
{
	sf::Sprite bgSprite[2];
	sf::Texture bg;
	float speed;

public:
	BackGround();

	float getSpeed();
	void setSpeed(float speed);

	virtual void update();
	virtual void render(sf::RenderWindow* window);
};
