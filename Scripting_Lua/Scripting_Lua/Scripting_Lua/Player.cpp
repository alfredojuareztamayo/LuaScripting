#include "Player.h"

//Typo Class::Funcion()

Player::Player(float x, float y)
{
	position = sf::Vector2f(x, y);
	shape = sf::CircleShape(16, 16);
	shape.setFillColor(sf::Color(0, 255, 0));
	shape.setPosition(position);
}

void Player::Update()
{
	position += direction;
	shape.setPosition(position);
}