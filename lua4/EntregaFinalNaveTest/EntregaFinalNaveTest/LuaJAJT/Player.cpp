#include "Player.h"

Player::Player(float x, float y, int c1, int c2, int c3) {
	position = sf::Vector2f(x, y);
	shape = sf::CircleShape(16, 8);
	shape.setFillColor(sf::Color(c1, c2, c3));
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