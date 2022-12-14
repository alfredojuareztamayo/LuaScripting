#include <iostream>
#include <string>

#include "GameManager.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(720, 720), "LUA Engine", sf::Style::Default);
	sf::Event m_event;
	
	LuaSystem luaSystem = LuaSystem();
	GameObject::luaSystem = luaSystem;
	GameManager manager = GameManager();

	while (window.isOpen())
	{
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
				break;

			default:
				break;
			}
		}

		//Update.
		manager.Update();

		//Render.
		window.clear(sf::Color::Blue);
		manager.Draw(window);
		window.display();
	}
	
	system("pause");
	GameObject::luaSystem.Close();
	return 0;
}