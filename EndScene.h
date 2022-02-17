#pragma once
#include"Scene.h"
#include"string"
#include"BackGround.h"
#include "GameScore.h"

class EndScene : public Scene
{
	BackGround endBackground;

	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	sf::Text text5;
	sf::Font font;
	std::string s1;
	std::string s2;
	std::string s3;
	std::string score;
	std::string highsc;

	float counter;

public:
	EndScene(GameScore* score);
	virtual void render(sf::RenderWindow* window);
	virtual void onEvent(sf::Event& event);
	virtual void update();
};

