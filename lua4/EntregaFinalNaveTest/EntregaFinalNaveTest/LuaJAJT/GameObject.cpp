#include "GameObject.h"
GameObject::GameObject(sf::Vector2f position, std::string name) {
	this->position = position;
	texture.loadFromFile("Images/" + name);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

void GameObject::Update() {

}
void GameObject::Render() {

}