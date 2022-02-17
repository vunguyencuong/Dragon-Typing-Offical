#pragma once
#include "GameObject.h"
#include "RichText.h"
#include "Observer.h"

class Typing : public GameObject, public Publisher
{
	std::string passage;
	sfe::RichText text;
	sf::Font font;
	sf::Texture bg2;
	sf::Sprite bkg2;

	int streak;
	int id;
	int results;
	bool endOfText;
public:
	Typing(std::string passage, std::string fontFile, int fontSize);

	virtual void update();
	virtual void render(sf::RenderWindow* window);

	void setPosition(float x, float y);
	int getStreak();
	int getResults();
	void onKeyPressed(sf::Event& e);
	bool checkEnd();
};

