#include <iostream>
#include <string>
#include "Player.h"
#include "GameManager.h"
#include "Item.h"
//#include "LuaSystem.h"
#include "Space.h"
extern "C" {
#include "Lua542/include/lua.h"
#include "Lua542/include/lauxlib.h"
#include "Lua542/include/lualib.h"
}


#ifdef _WIN32
#pragma comment(lib,"Lua542/liblua54.a")
#include <Windows.h>
#else
#include <unistd.h>
#endif
bool IsValidLuaCommand(lua_State* L, int command) {
	if (command != LUA_OK) {
		//std::string error_message = lua_tostring(L, -1);
		std::cout << "Error at executing command: " << command << std::endl;
		return false;
	}
	return true;
}
float GetLuaNumber(lua_State* L, const char* variable) {
	lua_pushstring(L, variable);
	lua_gettable(L, -2);
	float x = lua_tonumber(L, -1);
	lua_pop(L, 1);
	return x;
}
int GetLuaNumberint(lua_State* L, const char* variable) {
	lua_pushstring(L, variable);
	lua_gettable(L, -2);
	int a = lua_tonumber(L, -1);
	lua_pop(L, 1);
	return a;
}



float velTest;
float regresarPosX;
bool EternoLoop = true;
Player player;
Space space;

int main()

{
	//sf::RenderWindow window(sf::VideoMode(720, 720), "SpaceInvader", sf::Style::Default);
	RenderWindow window(VideoMode(720, 720), "SpaceInvader", sf::Style::Default);
	window.setFramerateLimit(60);
	sf::Event m_event;


	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	if (IsValidLuaCommand(L, luaL_dofile(L, "Space.lua")))
	{
		lua_getglobal(L, "player");
		if (lua_istable(L, -1)) {
			float x = GetLuaNumber(L, "x");
			float y = GetLuaNumber(L, "y");
			/*int Colorx1 = GetLuaNumberint(L, "Colorx1");
			int Colorx2 = GetLuaNumberint(L, "Colorx2");
			int Colorx3 = GetLuaNumberint(L, "Colorx3");
			int Colory1 = GetLuaNumberint(L, "Colory1");
			int Colory2 = GetLuaNumberint(L, "Colory2");
			int Colory3 = GetLuaNumberint(L, "Colory3");
			int Colorz1 = GetLuaNumberint(L, "Colorz1");
			int Colorz2 = GetLuaNumberint(L, "Colorz2");
			int Colorz3 = GetLuaNumberint(L, "Colorz3");*/
			

				
				 space = Space( x,  y);
					

		}
	}
	GameManager gamemanager = GameManager();
	Player player;
	Item item = Item(sf::Vector2f(360, 360), "text_txt.png");

	
	
	//[Caso 6] Almacenamiento para datos estructuras
	
	
	space.ball.setPosition(Vector2f(0, window.getSize().y - space.ball.getRadius() * 3));

	while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
					if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
						window.close();
				}
		
				//Update hoop
				if (space.hoop.getPosition().x <= 0)
					space.dir = 1;
				else if (space.hoop.getPosition().x + space.hoop.getRadius()*2 >= window.getSize().x)
					space.dir = 0;
		
				if (space.dir == 0)
				{
					space.hoop.move(-5.f, 0);
				}
				else
				{
					space.hoop.move(5.f, 0);
				}
		
				//Update ball
				if (Mouse::isButtonPressed(Mouse::Left))
					space.isShot = true;
		
				if(!space.isShot)
					space.ball.setPosition(Mouse::getPosition(window).x, space.ball.getPosition().y);
				else
					space.ball.move(0, -5.f);
		
				//Collision ball
				if (space.ball.getPosition().y <= 0 || space.ball.getGlobalBounds().intersects(space.hoop.getGlobalBounds()))
				{
					//Reset ball
					space.isShot = false;
					space.ball.setPosition(space.ball.getPosition().x, window.getSize().y - space.ball.getRadius() * 3);
				}
		
				//DRAW
				window.clear(Color::White);
		
				window.draw(space.hoop);
				window.draw(space.ball);
		
				window.display();
			}
	lua_close(L);
			return 0;
}




