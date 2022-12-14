#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class GameObject
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	GameObject() {};
	GameObject(sf::Vector2f position, std::string txtPath);
	void Update();
	void Render();
};

