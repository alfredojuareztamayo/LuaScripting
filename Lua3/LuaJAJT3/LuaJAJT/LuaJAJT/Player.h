#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>
class Player

{

public:

    float vel = 0.1;
	sf::Vector2f position;
	sf::CircleShape shape;
	Player(){}
	Player(float x, float y, int c1, int c2, int c3);
	void Update();
};

