#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Observer.h"
#include <vector>

class Dragon : public GameObject, Subscriber
{
	enum State
	{
		FAST,
		NORMAL,
		SLOW,
		FAIL
	};

	sf::Texture texture;
	State currentState;
	std::vector<Animation> animations;
	int streak;
	float relativeSpeed;
public:
	Dragon();
	virtual void update();
	virtual void render(sf::RenderWindow* window);
	virtual void notify(Publisher* publisher);

	void setStreak(int streak);
	bool isDead();
};

