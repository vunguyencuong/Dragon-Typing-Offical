#pragma once
#include "Scene.h"
#include "GameObject.h"
#include <vector>

class PlayScene : public Scene
{
	std::vector<GameObject*> objects;
public:
	PlayScene();
	virtual void update();
	virtual void onEvent(sf::Event& event);
	virtual void render(sf::RenderWindow* window);
	virtual void clear();

	template<typename Base>
	inline Base* getObject();
};

template<typename Base>
inline Base* PlayScene::getObject()
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (Base* obj = dynamic_cast<Base*>(objects[i]))
			return obj;
	}
}