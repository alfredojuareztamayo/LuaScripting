#include "Player.h"

Player::Player(float x, float y) {
	position = sf::Vector2f(x, y);
	shape = sf::CircleShape(16, 8);
	shape.setFillColor(sf::Color(0, 255, 0));
	shape.setPosition(position);


}
void Player::Update() {

	position += direction;
	shape.setPosition(position);
	/*if (position.x < 720) {
		position.x += vel;
		shape.setPosition(position);
	}
	else {
		position.x = 0;
	}*/
}