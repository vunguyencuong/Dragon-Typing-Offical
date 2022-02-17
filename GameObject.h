#pragma once
#include<SFML/Graphics.hpp>


class GameObject
{
protected:
	float x, y;
	float w, h;
public:
	virtual void update() {};

	virtual void render(sf::RenderWindow* window) {};

	~GameObject();
};
