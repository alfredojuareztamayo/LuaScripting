#pragma once
#include <SFML/Graphics.hpp>

class NavePlayer {


	unsigned short x;
	unsigned short y;
	
	sf::Sprite sprite;
	sf::Texture texture;



	public:
	

	NavePlayer();

	void Draw(sf::RenderWindow& window);
	void update();


};
