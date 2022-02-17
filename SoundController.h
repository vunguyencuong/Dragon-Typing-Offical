#pragma once
#include <unordered_map>
#include <SFML/Audio.hpp>
#include <queue>

class SoundController
{
	std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
	std::queue<sf::Sound> queue;
public:
	void update();
	void addSound(std::string name, std::string path);
	void play(std::string name);
};

