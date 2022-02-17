#include "SoundController.h"
#include <iostream>

void SoundController::addSound(std::string name, std::string path)
{

	if (soundBuffers.find(name) != soundBuffers.end())
	{
		std::cout << "Register name existed" << std::endl;
		return;
	}

	if (!soundBuffers[name].loadFromFile(path))
	{
		std::cout << "Can not load buffer from " + path << std::endl;
		return;
	}
}

void SoundController::play(std::string name)
{
	if (soundBuffers.find(name) != soundBuffers.end())
	{
		queue.push(sf::Sound(soundBuffers[name]));
	}
	else
	{
		std::cout << "Can not find any sound buffer match with given name" << std::endl;
	}
}

void SoundController::update()
{
	if (queue.size() > 1)
	{
		sf::Sound& s = queue.front();

		if (s.getStatus() == sf::Sound::Stopped)
		{
			queue.pop();

			queue.front().play();
		}
	}
}