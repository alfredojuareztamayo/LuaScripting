#include "GameObject.h"

LuaSystem GameObject::luaSystem = LuaSystem();


GameObject::GameObject(std::string scriptPath,
	std::string name,
	sf::Vector2f position) {
	/*this->position = position;
	texture.loadFromFile("Images/" + name);
	sprite.setTexture(texture);
	sprite.setPosition(position);*/
}

void GameObject::Update() {

	//std::cout << "GameObject Update\n";

}
//void GameObject::SetState(){}
void GameObject::Render() {

}