#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "LuaSystem.h"
#include <iostream> 


class GameObject
{
public:
	std::string scriptPath;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	//lua_State* L;
	 static LuaSystem luaSystem ;


	GameObject() {};
	GameObject(std::string scriptPath,
		std::string name,
		sf::Vector2f position);

	virtual void Update();
	void Render();
};

//LuaSystem GameObject::luaSystem;
//LuaSystem GameObject::luaSystem = LuaSystem();