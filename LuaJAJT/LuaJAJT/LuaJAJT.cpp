#include <iostream>
#include <string>
#include "Player.h"
#include "GameManager.h"
#include "Item.h"
#include "LuaSystem.h"



float velTest;
float regresarPosX;
bool EternoLoop = true;
Player player;

int main()

{
	sf::RenderWindow window(sf::VideoMode(720, 720), "LUA Engine", sf::Style::Default);
	sf::Event m_event;


	LuaSystem luasystem = LuaSystem();
	GameManager gamemanager = GameManager();
	Player player;
	Item item = Item(sf::Vector2f(360, 360), "text_txt.png");
	
	//[Caso 6] Almacenamiento para datos estructuras
	
	
	

	while (window.isOpen()) {
		while (window.pollEvent(m_event))
		{
			switch (m_event.type)
			{
			case sf::Event::Closed:
				window.close(); 
				break;
			case sf::Event::KeyPressed:
				if (m_event.key.code == sf::Keyboard::Escape)
					window.close();
				if (m_event.key.code == sf::Keyboard::A)
					player.direction.x = -0.1;
				if (m_event.key.code == sf::Keyboard::W)
					player.direction.y = -0.1;
				break;
			case sf::Event::KeyReleased:
				if (m_event.key.code == sf::Keyboard::A)
					player.direction.x = 0;
				if (m_event.key.code == sf::Keyboard::W)
					player.direction.y = 0;
			default:
				break;
			}
		}

		player.Update();

		gamemanager.Update();
		//std::cout << gamemanager.elapsedTime << std::endl;

		window.clear(sf::Color::Blue);
		sf::RectangleShape testShape;
		//testShape.setPosition(position);
		//testShape.setSize(Size);
	window.draw(player.shape);
		window.draw(item.sprite);
		gamemanager.Draw(window);
		window.display();
	}	
	system("pause");
	
	luasystem.Close();
	return 0;
}




