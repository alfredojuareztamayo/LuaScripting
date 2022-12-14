#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <chrono>
class Player

{

public:

    float vel = 0.1f;
	sf::Vector2f position;
	sf::CircleShape shape;
	sf::Vector2f direction;



	Player(){}
	Player(float x, float y, int c1, int c2, int c3);
	void Update();
	void SetSpeed(float value) { speed = value; }
	

private:
	float speed = 0;
	
};

