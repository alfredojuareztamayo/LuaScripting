#pragma once
#include "Item.h"
#include <list>

class GameManager
{
public:

	sf::Clock clock;
	float deltaTime;
	float lastTime = 0;

	std::list<GameObject> gameObjects;

	GameManager();
	void Update();
	void Draw(sf::RenderWindow &window);
	float GetElapsedTime() { return elapsedTime; }

private:
	float elapsedTime;
};

