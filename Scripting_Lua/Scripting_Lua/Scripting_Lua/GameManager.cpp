#include "GameManager.h"

GameManager::GameManager()
{
	
	gameObjects = std::list<GameObject>();
	Item item_0 = Item("Player.lua", "Images/test_txt.png", sf::Vector2f(100, 100));
	gameObjects.push_back(item_0);
}

void GameManager::Update()
{
	elapsedTime = clock.getElapsedTime().asSeconds();
	deltaTime = elapsedTime - lastTime;
	lastTime = elapsedTime;

	std::list<GameObject>::iterator it;
	for (it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		it->Update();
	}
}

void GameManager::Draw(sf::RenderWindow& window)
{
	std::list<GameObject>::iterator it;
	for (it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		window.draw(it->sprite);
	}
}