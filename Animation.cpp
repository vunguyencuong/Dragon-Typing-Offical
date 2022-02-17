#include "Animation.h"
#include <iostream>

Animation::Animation(const vector<sf::IntRect>& spriteTransforms, sf::Texture& texture, int _delay)
{
	currentFrame = 0;
	delay = _delay;
	frameCount = 0;

	for (auto tf : spriteTransforms)
	{
		sf::Sprite s(texture);
		s.setTextureRect(tf);
		s.setScale(0.4, 0.4);

		frames.push_back(s);
	}
}

sf::Sprite Animation::getNextSprite()
{
	if (frameCount > delay) {
		currentFrame = currentFrame + 1;
		currentFrame %= frames.size();
		frameCount = 0;
	}
	else
	{
		frameCount++;
	}

	return frames[currentFrame];
}
