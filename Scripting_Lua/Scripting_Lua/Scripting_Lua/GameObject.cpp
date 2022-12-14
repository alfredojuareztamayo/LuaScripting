#include "GameObject.h"

LuaSystem GameObject::luaSystem = LuaSystem();

GameObject::GameObject(std::string scriptPath, std::string name, sf::Vector2f position)
{
	/*this->position = position;
	texture.loadFromFile(name);
	sprite.setTexture(texture);
	sprite.setPosition(position);*/
}

void GameObject::Update()
{
	
}

void GameObject::Render()
{

}