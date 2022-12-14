#include <iostream>
#include <string>
#include "Player.h"


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
		std::cout << "Error at executing command: " << command <<std::endl;
		return false;
	}
	return true;
}
float GetLuaNumber(lua_State *L, const char *variable) {
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

int main()

{
	sf::RenderWindow window(sf::VideoMode(720, 720), "LUA Engine", sf::Style::Default);
	sf::Event m_event;

	lua_State* L = luaL_newstate();
	luaL_openlibs(L);


	//[Caso 6] Almacenamiento para datos estructuras
	
	if (IsValidLuaCommand(L, luaL_dofile(L, "Player.lua"))) {
		lua_getglobal(L, "player");
		if (lua_istable(L, -1)) {

			
			float x = GetLuaNumber(L, "x");
			float y = GetLuaNumber(L, "y");
			
			int c1 = GetLuaNumberint(L, "c1");
			int c2 = GetLuaNumberint(L, "c2");
			int c3 = GetLuaNumberint(L, "c3");
			
				player = Player(x, y, c1, c2, c3);

			
		

				
				
				

				//velTest = vel;
				//regresarPosX = x;
			
		}
	}

	

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
				break;
			default:
				break;
			}
		}

		player.Update();

		window.clear(sf::Color::Blue);
		//sf::RectangleShape testShape;
		//testShape.setPosition(position);
		//testShape.setSize(Size);
		window.draw(player.shape);

		window.display();
	}
	
	

		
	system("pause");
	lua_close(L);
	
	return 0;
}




