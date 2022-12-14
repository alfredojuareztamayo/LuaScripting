#pragma once
#include "GameObject.h"
class Item : public GameObject
{
public:
	Item(){}
	Item(sf::Vector2f position, std::string name) : GameObject(position, name) {}
};

