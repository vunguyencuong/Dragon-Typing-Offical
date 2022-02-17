#pragma once
#include"GameObject.h"
#include<vector>
#include<string>

enum class Status { SWITCH, CLOSE };

class Scene
{
public:
	virtual void update() {}
	virtual void onEvent(sf::Event& event) {}
	virtual void render(sf::RenderWindow* window) {}
	virtual void clear() {}
};

//template<typename Base>
//inline Base* Scene::getObject()
//{
//	for (int i = 0; i < objects.size(); i++)
//	{
//		if (Base* obj = dynamic_cast<Base*>(objects[i]))
//			return obj;
//	}
//	return nullptr;
//}

