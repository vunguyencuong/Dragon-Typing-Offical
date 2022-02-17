#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class Animation
{
	vector<sf::Sprite> frames;
	int currentFrame;
	int frameCount;
	int delay;
public:
	Animation() {};
	Animation(const vector<sf::IntRect>& spriteTransforms, sf::Texture& texture, int delay);

	sf::Sprite getNextSprite();
};