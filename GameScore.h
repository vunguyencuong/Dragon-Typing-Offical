#pragma once

#include "GameObject.h"
#include "Observer.h"
class GameScore : public GameObject, public Subscriber
{
	int results;
	sf::Text text;
	sf::Font font;
public:
	GameScore();
	// luu 
	virtual void saveScore();
	// hien thi text
	virtual void render(sf::RenderWindow* window);

	virtual void notify(Publisher* publisher);

	int getResults();
	int getHighScore();
};

