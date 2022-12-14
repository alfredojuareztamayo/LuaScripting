
#include <chrono>
#include "NavePlayer.h"
#include "GlobarScreenVariables.h"
#include "GameManager.h"
#include <SFML/Graphics.hpp>


NavePlayer::NavePlayer() :
	x(0.5f * (ScreenWidth - BaseSize))
	{
	
	texture.loadFromFile("Images/Nave2.png");
	
	sprite.setTexture(texture);
	}
void NavePlayer::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(x, ScreenHeight-2 * BaseSize);
	//
	/*for (const Bullet& bullet : bullets)
	{
		bullet_sprite.setPosition(bullet.x, bullet.y);

		window.draw(bullet_sprite);
	}*/
	window.draw(sprite);

}
void NavePlayer::update()
{
	if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
			
			x = std::max<int>(x - PLAYER_MOVE_SPEED, BaseSize);
	}

		if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			
				x = std::min<int>(PLAYER_MOVE_SPEED + x, ScreenWidth - 2 * BaseSize);
			
		}
		/*if (0 == reload_timer) {

			if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				reload_timer = RELOAD_DURATION;
				bullets.push_back(Bullet(0, -PLAYER_BULLET_SPEED, x, y));

			}
		}
		else
		{
			reload_timer--;
		};*/

		
		//for (Bullet& bullet : bullets)
		//{
		//	//bullet.update();

		//	/*if (0 == bullet.dead)
		//	{
		//		if (1 == i_ufo.check_bullet_collision(i_random_engine, bullet.get_hitbox()))
		//		{
		//			bullet.dead = 1;
		//		}
		//	}*/
		//}

		
}