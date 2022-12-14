

#include <chrono>

#include "GameManager.h"
#include "GlobarScreenVariables.h"
#include "NavePlayer.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(ScreenResize * ScreenWidth, 
		ScreenResize * ScreenHeight), "Space Invaders", sf::Style::Close);
	//Resizing the screen.
	window.setView(sf::View(sf::FloatRect(0, 0, ScreenWidth, ScreenHeight)));	
	
	sf::Event m_event;

	NavePlayer naveplayer;
	std::chrono::steady_clock::time_point previous_time;

	std::chrono::microseconds lag(0);
	previous_time = std::chrono::steady_clock::now();

	while (1 == window.isOpen())
	{
		//Making the game frame rate independent.
		std::chrono::microseconds delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time);

		lag += delta_time;

		previous_time += delta_time;
		while (FRAME_DURATION <= lag)
		{
			lag -= FRAME_DURATION;

			while (1 == window.pollEvent(m_event))
			{
				switch (m_event.type)
				{
				case sf::Event::Closed:
				{
					window.close();
				}
				}
			}
			naveplayer.update();
			if (FRAME_DURATION > lag)
			{
				window.clear();


				naveplayer.Draw(window);

				window.display();
			}
		}
	}


	
	
	system("pause");
	return 0;
}


