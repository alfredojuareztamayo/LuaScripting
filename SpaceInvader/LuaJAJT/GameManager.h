#pragma once
//#include "GameObject.h"
#include "Item.h"
#include <list>

class GameManager
{
public:
	sf::Clock clock;
	float deltTime;
	float lastTime = 0;
	float coldDown = 10;

	std::list<GameObject> gameObject;
	//LuaSystem lua;
	GameManager();
	void Update();
	void Draw(sf::RenderWindow &window);
	float GetElapsedTime() { return elapsedTime; }

private:
	float elapsedTime;
};

