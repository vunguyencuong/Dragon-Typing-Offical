#include "GameObject.h"
#include <iostream>

GameObject::~GameObject()
{
	std::cout << "Destroyed" << std::endl;
}
