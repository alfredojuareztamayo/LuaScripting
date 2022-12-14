#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

class Player
{
public:

	sf::Vector2f position;
	sf::CircleShape shape;
	sf::Vector2f direction;

	Player() {}
	Player(float x, float y);

	void Update();
	void SetSpeed(float value) { speed = value; }

private:
	float speed = 0;
	
};