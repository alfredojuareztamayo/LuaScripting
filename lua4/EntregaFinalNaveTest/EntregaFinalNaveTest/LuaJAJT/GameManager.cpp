#include "GameManager.h"
GameManager::GameManager() {
	gameObject = std::list<GameObject>();

	Item item_0 = Item(sf::Vector2f(100, 100), "text_txt.png");
	Item item_1 = Item(sf::Vector2f(200, 200), "text_txt.png");
	Item item_2 = Item(sf::Vector2f(300, 300), "text_txt.png");


	gameObject.push_back(item_0);
	gameObject.push_back(item_1);
	gameObject.push_back(item_2);
}
void GameManager::Update() {
	elapsedTime = clock.getElapsedTime().asSeconds();

	deltTime = elapsedTime - lastTime;
	lastTime = elapsedTime;
	coldDown -= deltTime;
}
void GameManager::Draw(sf::RenderWindow& window) {
	std::list<GameObject>::iterator it;
	for (it = gameObject.begin(); it != gameObject.end(); it++) {
		window.draw(it->sprite);
	}
}