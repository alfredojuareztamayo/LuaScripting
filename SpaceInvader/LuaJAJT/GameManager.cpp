#include "GameManager.h"
GameManager::GameManager() {


	//lua = LuaSystem();
	//GameObject::luaSystem = lua;
	//luasystem.L;
	
	gameObject = std::list<GameObject>();
	

	Item item_0 = Item("Space.lua", "text_txt.png", 
		sf::Vector2f(100, 100));
	
	


	gameObject.push_back(item_0);
	
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
		
		//it->Update();
		
		window.draw(it->sprite);
	}
}