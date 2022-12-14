#pragma once
#include "GameObject.h"

class Item : public GameObject
{
public:

	Item() {}
	Item(std::string path, std::string name, sf::Vector2f position)
	: GameObject(path, name, position) 
	{
		luaSystem.LoadLuaScript("Player.lua");
	}

	void Update() override
	{
		std::cout << "Item update\n";
	}
};